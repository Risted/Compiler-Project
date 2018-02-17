%{
#include <stdio.h>
#include "tree.h"

extern char *yytext;
extern STM *thestatement;

void yyerror() {
   printf("syntax error before %s\n",yytext);
}
%}

%union {
   int intconst;
   char *stringconst;
   struct EXP *expression;
}

%token <intconst> tINTCONST
%token <stringconst> tIDENTIFIER

%type <expression> statement exp

%start statement

%left '+' '-'
%left '*' '/' '%'
%left "return"
%%

statement   : exp
            {thestatement = makeSTMEXP($1);}
;

exp : tIDENTIFIER
      {$$ = makeEXPid($1);}
    | tINTCONST
      {$$ = makeEXPintconst($1);}
    | exp '*' exp
      {$$ = makeEXPtimes($1,$3);}
    | exp '/' exp
      {$$ = makeEXPdiv($1,$3);}
    | exp '+' exp
      {$$ = makeEXPplus($1,$3);}
    | exp '-' exp
      {$$ = makeEXPminus($1,$3);}
    | exp '%' exp
      {$$ = makeEXPmodulo($1,$3);}
    | '(' exp ')'
      {$$ = $2;}

;

%%
