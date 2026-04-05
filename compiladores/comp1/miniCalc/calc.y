%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%union {
	int intValue;
}

%token <intValue> NUM;
%token PLUS MINUS TIMES DIV LPAREN RPAREN
%type <intValue> expr

%%

start:
     expr {printf("Resultado: %d\n", $1); }
;

expr:
      expr PLUS expr	{ $$ = $1 + $3; }
    | expr MINUS expr 	{ $$ = $1 - $3; }
    | expr TIMES expr 	{ $$ = $1 * $3; }
    | expr DIV expr 	{ $$ = $1 / $3; }
    | LPAREN expr RPAREN{ $$ = $2; }
    | NUM 		{ $$ = $1; }
    ;

%%

int main(){
	return yyparse();
}

void yyerror(const char *s){
	fprintf(stderr, "Erro: %s\n", s);
}
