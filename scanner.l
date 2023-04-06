%{
	#include "parser.tab.h"
	int line = 1;
%}

%%

	/*Remove non-syntactic text*/
[ \t\r] {/*Whitespace is not significant*/}
\n {line++;}
[/]{2,}[^\n]+ {/*Comments are ignored*/}

	/*Scan for punctuators*/
\: {return TOKEN_COLON;}
\; {return TOKEN_SEMI;}
\( {return TOKEN_L_PAREN;}
\) {return TOKEN_R_PAREN;}
\{ {return TOKEN_L_BRACE;}
\} {return TOKEN_R_BRACE;}
= {return TOKEN_ASSIGN;}
== {return TOKEN_EQUIV;}

	/*Scan for literals*/
\"(.)*\" {return TOKEN_STR_LTRL;}
[0-9]+ {return TOKEN_INT_LTRL;}

	/*Scan for keywords*/
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


	/*Identifiers*/
[a-zA-Z_][a-zA-Z0-9_]* {return TOKEN_ID;}

	/*Check for problems*/
[^ \n\t\r:;(){}}"]+ {fprintf(stderr, "Unrecognized token %s at line %d\n", yytext, line);}
["] {fprintf(stderr, "Unmatched \" line %d\n", line);}
%%

int yywrap() {return 1;}