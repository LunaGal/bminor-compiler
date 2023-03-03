%{
	#include "token.h"
	int line = 1;
%}

%%
[ \t\r] {/*Whitespace is not significant*/}
\n {line++;}
[/]{2,}[^\n]+ {/*Comments are ignored*/}
[a-zA-Z_]+[a-zA-Z0-9_]* {return TOKEN_ID;}
[^ \n\t\r]+ {fprintf(stderr, "Unrecognized token %s at line %d\n", yytext, line);}
%%

int yywrap() {return 1;}