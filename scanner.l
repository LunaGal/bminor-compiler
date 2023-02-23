%{
	int line = 1;
%}

%%
[ \t\r] {/*Whitespace is not significant*/}
\n {line++; printf("\n");}
[a-zA-Z_]+[a-zA-Z_0-9]* {printf(" `id: %s` ", yytext);}
[.] {printf("Unrecognized Token %s at line %d\n", yytext, line);}
%%

main(int argc, char **argv) {
	yylex();
}