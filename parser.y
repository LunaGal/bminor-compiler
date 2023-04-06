%{
#include <stdio.h>
int yylex(void);
void yyerror(const char* msg) {
  fprintf(stderr, "%s\n", msg);
}	
%}

%token TOKEN_EOF
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
%token TOKEN_ID
%token TOKEN_INT_LTRL
%token TOKEN_STR_LTRL
%token TOKEN_COLON
%token TOKEN_SEMI
%token TOKEN_L_PAREN
%token TOKEN_R_PAREN
%token TOKEN_L_BRACE
%token TOKEN_R_BRACE
%token TOKEN_ASSIGN
%token TOKEN_EQUIV

%%
program: declaration
	   | program declaration
	   ;

declaration: var_declaration
		   | func_declaration
		   ;

func_declaration: func_header TOKEN_SEMI
				| func_header func_assignment
				;

func_header: declarator TOKEN_FUNCTION type TOKEN_L_PAREN TOKEN_R_PAREN
		   ;

var_declaration: declarator type TOKEN_SEMI
			   | declarator type var_assignment TOKEN_SEMI
			   ;

declarator: TOKEN_ID TOKEN_COLON
			  ;

var_assignment: TOKEN_ASSIGN expression;

func_assignment: TOKEN_ASSIGN TOKEN_L_BRACE compound_statement TOKEN_R_BRACE;

type: TOKEN_BOOLEAN
	  | TOKEN_CHAR
	  | TOKEN_INTEGER
	  | TOKEN_STRING
	  ;

expression: constant
		  | TOKEN_L_PAREN expression TOKEN_R_PAREN
		  ;

constant: TOKEN_INT_LTRL
		| TOKEN_STR_LTRL
		;

statement: declaration
		 | TOKEN_RETURN expression TOKEN_SEMI
		 ;

compound_statement: statement
				  | compound_statement statement
				  ;
