%{
#include <stdio.h>

int yylex();
void yyerror(const char *s);

%}

%token TEDIO
%token DOMINGO

%%
	start:
		TEDIO DOMINGO{ printf("Tenho tedio no domingo\n"); }
		;
%%

void yyerror(const char *s){
	fprintf(stderr, "Erro de sintaxe: %s\n", s); 
}
