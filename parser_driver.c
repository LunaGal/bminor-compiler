#include <stdio.h>
#include "ast.h"

extern int yyparse();
extern FILE *yyin;
extern decl_t *parser_result;

int main(int argc, char const *argv[]) {
	if (!argv[1]) {
		yyin = stdin;
	}
	else {
		yyin = fopen(argv[1], "r");
		if (!yyin) {
			printf("Could not open %s\n", argv[1]);
		}
	}

	if(yyparse()==0) {
		print_decl(parser_result, 0);
		printf("Parse successful!\n");
	}
	else {
		printf("Parse failed.\n");
	}
}