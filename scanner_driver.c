#include "ast.h"
#include "parser.tab.h"
#include <stdio.h>

extern FILE *yyin;
extern int yylex();
extern int line;
extern char *yytext;
const char* str_token_type(enum yytokentype);

YYSTYPE yylval;

int main(int argc, char const *argv[])
{
	printf("test %s\n", str_token_type(TOKEN_INT_LTRL));
	if (!argv[1]) {
		yyin = stdin;
	}
	else {
		yyin = fopen(argv[1], "r");
		if (!yyin) {
			printf("Could not open %s\n", argv[1]);
		}
	}
	
	while (1) {
		enum yytokentype t = yylex();
		if (t==0) {
			break;
		}
		const char* token_type = str_token_type(t);
		printf("type: %s line: %d text: %s\n", token_type, line, yytext);
	}
	return 0;
}

const char* str_token_type(enum yytokentype t) {
	switch (t) {
		case TOKEN_ARRAY: return "keyword array";
		case TOKEN_BOOLEAN: return "keyword boolean";
		case TOKEN_CHAR: return "keyword char";
		case TOKEN_ELSE: return "keyword else";
		case TOKEN_FALSE: return "keyword false";
		case TOKEN_FOR: return "keyword for";
		case TOKEN_FUNCTION: return "keyword function";
		case TOKEN_IF: return "keyword if";
		case TOKEN_INTEGER: return "keyword integer";
		case TOKEN_PRINT: return "keyword print";
		case TOKEN_RETURN: return "keyword return";
		case TOKEN_STRING: return "keyword string";
		case TOKEN_TRUE: return "keyword true";
		case TOKEN_VOID: return "keyword void";
		case TOKEN_WHILE: return "keyword while";
		case TOKEN_ID: return "id";
		case TOKEN_INT_LTRL: return "int literal";
		case TOKEN_STR_LTRL: return "str literal";
		case TOKEN_COLON: return "colon";
		case TOKEN_SEMI: return "semicolon";
		case TOKEN_L_PAREN: return "L paren";
		case TOKEN_R_PAREN: return "R paren";
		case TOKEN_L_BRACE: return "L brace";
		case TOKEN_R_BRACE: return "R brace";
		case TOKEN_ASSIGN: return "assign";
		case TOKEN_EQUIV: return "equiv";
		case TOKEN_CHAR_LTRL: return "char literal";
		case TOKEN_L_BRACKET: return "left bracket";
		case TOKEN_R_BRACKET: return "right bracket";
	}
	return "";
}