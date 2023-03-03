%{
	#include "token.h"
	int line = 1;
%}

%%
[ \t\r] {/*Whitespace is not significant*/}
\n {line++;}
[/]{2,}[^\n]+ {/*Comments are ignored*/}
array {return TOKEN_ARRAY;}
boolean {return TOKEN_BOOLEAN;}
char {return TOKEN_CHAR;}
else {return TOKEN_ELSE;}
false {return TOKEN_FALSE;}
for {return TOKEN_FOR;}
function {return TOKEN_FUNCTION;}
if {return TOKEN_IF;}
integer {return TOKEN_INTEGER;}
print {return TOKEN_PRINT;}
return {return TOKEN_RETURN;}
string {return TOKEN_STRING;}
true {return TOKEN_TRUE;}
void {return TOKEN_VOID;}
while {return TOKEN_WHILE;}
[a-zA-Z_]+[a-zA-Z0-9_]* {return TOKEN_ID;}
[^ \n\t\r]+ {fprintf(stderr, "Unrecognized token %s at line %d\n", yytext, line);}
%%

int yywrap() {return 1;}