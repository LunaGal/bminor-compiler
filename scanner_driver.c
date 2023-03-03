#include "token.h"
#include <stdio.h>

extern FILE *yyin;
extern int yylex();
extern int line;
extern char *yytext;
const char* str_token_type(token_t);

int main(int argc, char const *argv[])
{
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
		token_t t = yylex();
		if (t==TOKEN_EOF) {
			break;
		}
		const char* token_type = str_token_type(t);
		printf("type: %s line: %d text: %s\n", token_type, line, yytext);
	}
	return 0;
}

const char* str_token_type(token_t t) {
	switch (t) {
		case TOKEN_EOF: return "EOF";
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
	}
	return "";
}