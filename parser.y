%{
#include <stdio.h>
#include "ast.h"

decl_t *parser_result;
int yylex(void);
void yyerror(const char* msg) {
  fprintf(stderr, "%s\n", msg);
}
int decl_count = 0;
int stmt_count = 0;
extern char *yytext;
extern int line;
%}

%union {
	int integer;
	char *string;
	decl_t *decl;
	stmt_t *stmt;
	expr_t *expr;
	type_t *sem_type;
	param_list_t *param_list;
}

%token TOKEN_ARRAY
%token TOKEN_BOOLEAN
%token TOKEN_CHAR
%token TOKEN_ELSE
%token TOKEN_FALSE
%token TOKEN_FOR
%token TOKEN_FUNCTION
%token TOKEN_IF
%token TOKEN_INTEGER
%token TOKEN_PRINT
%token TOKEN_RETURN
%token TOKEN_STRING
%token TOKEN_TRUE
%token TOKEN_VOID
%token TOKEN_WHILE
%token <string> TOKEN_ID
%token <integer> TOKEN_INT_LTRL
%token <string> TOKEN_STR_LTRL
%token <string> TOKEN_CHAR_LTRL
%token TOKEN_COLON
%token TOKEN_SEMI
%token TOKEN_L_PAREN
%token TOKEN_R_PAREN
%token TOKEN_L_BRACE
%token TOKEN_R_BRACE
%token TOKEN_ASSIGN
%token TOKEN_EQUIV
%token TOKEN_L_BRACKET
%token TOKEN_R_BRACKET
%token TOKEN_COMMA

%type <string> declarator
%type <decl> program decl_list declaration
%type <stmt> codeblock codeblock_start statement
%type <expr> expression
%type <sem_type> type
%type <param_list> paramlist

%%
program: decl_list { parser_result = $1; };

decl_list: declaration
	   | declaration decl_list { $$ = $1; $1->next = $2; }
	   ;

declaration: declarator type TOKEN_SEMI { $$ = decl_create($1, $2, 0, 0, 0); decl_count++; }
		   | declarator type TOKEN_ASSIGN codeblock { $$ = decl_create($1, $2, 0, $4, 0); decl_count++; }
		   | declarator type TOKEN_ASSIGN expression TOKEN_SEMI { $$ = decl_create($1, $2, $4, 0, 0); decl_count++; }
		   ;

declarator: TOKEN_ID TOKEN_COLON { $$ = $1; };

type: TOKEN_BOOLEAN { $$ = type_create(TYPE_BOOLEAN, 0, 0)}
	  | TOKEN_CHAR { $$ = type_create(TYPE_CHARACTER, 0, 0); }
	  | TOKEN_INTEGER { $$ = type_create(TYPE_INTEGER, 0, 0); }
	  | TOKEN_STRING { $$ = type_create(TYPE_STRING, 0, 0); }
	  | TOKEN_FUNCTION type TOKEN_L_PAREN TOKEN_R_PAREN { $$ = type_create(TYPE_FUNCTION, $2, 0); }
	  ;

paramlist: paramlist TOKEN_COMMA declarator type { param_list_t *p = param_list_create($3, $4, NULL); $1->next = p; }
					| declarator type { $$ = param_list_create($1, $2, NULL); }
					;

expression: TOKEN_INT_LTRL { $$ = expr_create_integer_literal($1); }
		  | TOKEN_STR_LTRL { $$ = expr_create_integer_literal($1); }
		  | TOKEN_ID { ;}
		  | TOKEN_L_PAREN expression TOKEN_R_PAREN { $$ = $2; }
		  ;

codeblock: codeblock_start TOKEN_R_BRACE { $$ = $1; };

codeblock_start: TOKEN_L_BRACE { $$ = stmt_create(STMT_BLOCK, 0, 0, 0, 0, 0, 0, 0); }
			   | codeblock_start statement { stmt_t* current = $$;
			   														 while(current->next != NULL) {
			   														 		current = current->next;
			   														 	}
			   														 	current->next = $2;
			   														 }
			   ;

statement: declaration { $$ = stmt_create(STMT_DECL, $1, 0, 0, 0, 0, 0, 0); stmt_count++; }
		 | TOKEN_RETURN expression TOKEN_SEMI {$$ = stmt_create(STMT_RETURN, 0, 0, $2, 0, 0, 0, 0); stmt_count++; }
		 ;
