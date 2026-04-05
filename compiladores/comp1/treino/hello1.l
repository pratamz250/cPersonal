%{
#include <stdio.h>
#include "hello1.tab.h"
%}

%%
"Tedio"	  { return TEDIO; }
"Domingo" { return DOMINGO; }

[ \t\n]+  { }
.         { }

%%

int yywrap(){
	return 1;
}

int main(){
	return yyparse();
}
