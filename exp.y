%{
#include <stdio.h>
#include "tree.h"

extern char *yytext;
extern EXP *theexpression;
extern STM *thestatement;

void yyerror() {
   printf("syntax error before %s\n",yytext);
}
%}

%union {
   int intconst;
   char *stringconst;
   struct EXP* expression;
   struct STM* statement;
   struct DEC* declaration;
   struct TERM* term;
   struct TYPE* type;
}
%token <declaration> tTYPEINTEGER tTYPESTRING
%token <intconst> tINTCONST
%token <stringconst> tIDENTIFIER
%token <expression> tASSIGN tEQUALTO tNEQUALTO tAND tPIPE
%token <expression> tLPAREN tRPAREN tLBRACE tRBRACE
%token <expression> tSMALLER tBIGGER tSMALEQUAL tBIGEQUAL
%token <expression> tMOD tMULT tDIV tPLUS tSUB tSEMI tCOLON
%token <statement> tRETURN tWRITE tALLOCATE tOF tLENGTH tIF
%token <statement> tTHEN tELSE tWHILE tDO
%token <term> tNOT

%type <statement> statement
%type <expression> program expression
%type <term> term
%type <type> type variable

%start program

%left tNOT
%left tEQUALTO tNEQUALTO tSMALLER tBIGGER tSMALEQUAL tBIGEQUAL
%left tAND tPIPE
%left tPLUS tSUB
%left tMULT tDIV

%%
program    : statement              { thestatement = $1;}
;

statement  : tRETURN expression                               {$$ = makeSTMreturn($2);}
           | tWRITE expression                                {$$ = makeSTMwrite($2);}
           | tALLOCATE variable                               {$$ = makeSTMallocate($2);};
           | tALLOCATE variable tOF tLENGTH expression        {$$ = makeSTMallocateoflength($2, $5);}
           | variable tASSIGN expression                      {$$ = makeSTMassign($1, $3);}
           | tIF expression tTHEN statement                   {$$ = makeSTMifthen($2, $4);}
           | tIF expression tTHEN statement tELSE statement   {$$ = makeSTMifelse($2, $4, $6);}
           | tWHILE expression tDO statement                  {$$ = makeSTMwhile($2, $4);}
;

expression : expression tEQUALTO expression     {$$ = makeEXPequalto($1,$3);}
           | expression tNEQUALTO expression    {$$ = makeEXPnoequalto($1,$3);}
           | expression tAND expression         {$$ = makeEXPand($1,$3);}
           | expression tSMALLER expression     {$$ = makeEXPsmaller($1,$3);}
           | expression tBIGGER expression      {$$ = makeEXPbigger($1,$3);}
           | expression tSMALEQUAL expression   {$$ = makeEXPsmalequal($1,$3);}
           | expression tBIGEQUAL expression    {$$ = makeEXPbigequal($1,$3);}
           | expression tMOD expression         {$$ = makeEXPmodulo($1,$3);}
           | expression tMULT expression        {$$ = makeEXPtimes($1,$3);}
           | expression tDIV expression         {$$ = makeEXPdiv($1,$3);}
           | expression tPLUS expression        {$$ = makeEXPplus($1,$3);}
           | expression tSUB expression         {$$ = makeEXPminus($1,$3);}
           | tLPAREN expression tRPAREN         {$$ = $2;}
           | term                               {$$ = makeEXPterm($1);}
;

variable : tIDENTIFIER        {$$ = makeTYPEid($1);}

term : tIDENTIFIER tCOLON type        {$$ = makeTERMidtype($1, $3);}
     | tLPAREN expression tRPAREN     {$$ = makeTERMexpression($2);}
     | tNOT term                      {$$ = makeTERMnot($2);}
     | tPIPE expression tPIPE         {$$ = makeTERMabsolute($2);}
     | tINTCONST                      {$$ = makeTERMnum($1);}
;

type : tIDENTIFIER        {$$ = makeTYPEid($1);}
     | tINTCONST          {$$ = makeTYPEintconst($1);}
;

%%
