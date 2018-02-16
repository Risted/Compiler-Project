%{
#include <stdio.h>
#include "tree.h"

extern char *yytext;
extern STM *thestatement;
extern EXP *theexpression;

void yyerror() {
   printf("syntax error before %s\n",yytext);
}
%}

%union {
   int intconst;
   char *stringconst;
   struct STM *stm;
   struct EXP *exp;
}

%token <intconst> tINTCONST
%token <stringconst> tIDENTIFIER

%type <stm> program exp

%start program

%left '+' '-'
%left '*' '/'

%%
program: stm
         {thestatement = $1;}
;

stm : exp
      {theexpression = $1;}
    | "return" '(' exp ')'
      {$$ = makeSTMreturn($3);}
    | "if" '(' exp ')' "then" '(' stm ')'
      {$$ = makeSTMifThen($3,$7);}

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
    | '(' exp ')'
      {$$ = $2;}
;


%%
