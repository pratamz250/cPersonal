%{
#include "calc.tab.h"
#include <stdio.h>
#include <stdlib.h>
%}

%%

[ \t\n]+ { }
[0-9]+ {
	yylval.intValue = atoi(yytext);
	return NUM;
}

"+"	{ return PLUS; }
"-"	{ return MINUS; }
"*"	{ return TIMES; }
"/" 	{ return DIV; }
"("	{ return LPAREN; }
")" 	{ return RPAREN; }
.	{ } //ignora tudo o mais

%%

int yywrap(){ return 1; }
