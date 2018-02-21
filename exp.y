%{
#include <stdio.h>
#include "headers/tree.h"

extern char *yytext;
extern FUNC* thebody;
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
   struct LIST* list;
   struct FUNC* function;
}

%token <declaration> tTYPEINTEGER tTYPESTRING
%token <intconst> tINT
%token <stringconst> tID
%token <type> tBOOL tARRAY tRECORD tEND tDOT tTYPE tVAR tFUNC
%token <expression> tASSIGN tEQUALTO tNEQUALTO tAND tPIPE
%token <expression> tLPAREN tRPAREN tLBRACE tRBRACE tLSQUARE tRSQUARE
%token <expression> tSMALLER tBIGGER tSMALEQUAL tBIGEQUAL
%token <expression> tMOD tMULT tDIV tPLUS tSUB tSEMI tCOLON
%token <statement> tRETURN tWRITE tALLOCATE tOF tLENGTH tIF
%token <statement> tTHEN tELSE tWHILE tDO
%token <term> tNOT tTRUE tFALSE tNULL
%token <list> tCOMMA

%type <statement> statement
%type <expression> program expression
%type <function> function head body tail
%type <list> par_decl_list var_decl_list decl_list statement_list act_list exp_list
%type <declaration> declaration
%type <term> term
%type <type> type variable var_type

%start program

%left tNOT
%left tEQUALTO tNEQUALTO tSMALLER tBIGGER tSMALEQUAL tBIGEQUAL
%left tAND tPIPE
%left tPLUS tSUB
%left tMULT tDIV

%%
program    : body              { thebody = $1;}
;

function : head body tail           {$$ = makeFUNC($1, $2, $3);}
;

head : tFUNC tID tLPAREN par_decl_list tRPAREN tCOLON type      {$$ = makeFUNChead($2, $4, $7);}
;

tail : tEND tID             {$$ = makeFUNCtail($2);}
;

type : tID                                            {$$ = makeTYPEid($1);}
     | tINT                                           {$$ = makeTYPEintconst($1);}
     | tBOOL                                          {$$ = makeTYPEbool($1);}
     | tARRAY tOF type                                {$$ = makeTYPEarray($3);}
     | tRECORD tOF tLBRACE var_decl_list tRBRACE      {$$ = makeTYPErecord($4);}
;

par_decl_list : /* empty */
              | var_decl_list             {$$ = makeLISTpar($1);}
;

var_decl_list : var_type tCOMMA var_decl_list      {$$ = makeLISTvarlist($1, $3);}
              | var_type                           {$$ = makeLISTvar($1);}
;

var_type : tID tCOLON type                {$$ = makeTYPEvar($1, $3);}
;

body : decl_list statement_list           {$$ = makeFUNCbody($1, $2);}
;

decl_list : /* empty */
          | declaration decl_list         {$$ = makeLISTdecl($1, $2);}
;

declaration : tTYPE tID tASSIGN type tSEMI     {$$ = makeDECtype($4);}
            | function                         {$$ = makeDECfunc($1);}
            | tVAR var_decl_list tSEMI         {$$ = makeDEClist($2);}
;

statement_list : statement                    {$$ = makeLISTstate($1);}
               | statement statement_list     {$$ = makeLISTstatelist($1, $2);}
;

statement  : tRETURN expression tSEMI                              {$$ = makeSTMreturn($2);}
           | tWRITE expression tSEMI                               {$$ = makeSTMwrite($2);}
           | tALLOCATE variable tSEMI                              {$$ = makeSTMallocate($2);};
           | tALLOCATE variable tOF tLENGTH expression tSEMI       {$$ = makeSTMallocateoflength($2, $5);}
           | variable tASSIGN expression tSEMI                     {$$ = makeSTMassign($1, $3);}
           | tIF expression tTHEN statement                        {$$ = makeSTMifthen($2, $4);}
           | tIF expression tTHEN statement tELSE statement        {$$ = makeSTMifelse($2, $4, $6);}
           | tWHILE expression tDO statement                       {$$ = makeSTMwhile($2, $4);}
           | tLBRACE statement_list tRBRACE                        {$$ = makeSTMlist($2);}
;

variable : tID                                          {$$ = makeTYPEid($1);}
         | variable tLSQUARE expression tRSQUARE        {$$ = makeTYPEvarexp($1, $3);}
         | variable tDOT tID                            {$$ = makeTYPEvar($1, $3);}
;

expression : expression tEQUALTO expression     {$$ = makeEXPequalto($1,$3);}
           | expression tNEQUALTO expression    {$$ = makeEXPnoequalto($1,$3);}
           | expression tAND expression         {$$ = makeEXPand($1,$3);}
           | expression tPIPE tPIPE expression  {$$ = makeEXPor($1,$4);}
           | expression tSMALLER expression     {$$ = makeEXPsmaller($1,$3);}
           | expression tBIGGER expression      {$$ = makeEXPbigger($1,$3);}
           | expression tSMALEQUAL expression   {$$ = makeEXPsmalequal($1,$3);}
           | expression tBIGEQUAL expression    {$$ = makeEXPbigequal($1,$3);}
           | expression tMOD expression         {$$ = makeEXPmodulo($1,$3);}
           | expression tMULT expression        {$$ = makeEXPtimes($1,$3);}
           | expression tDIV expression         {$$ = makeEXPdiv($1,$3);}
           | expression tPLUS expression        {$$ = makeEXPplus($1,$3);}
           | expression tSUB expression         {$$ = makeEXPminus($1,$3);}
           | term                               {$$ = makeEXPterm($1);}
;

term : variable                       {$$ = makeTERMvar($1);}
     | tID tLPAREN act_list tRPAREN   {$$ = makeTERMact($1, $3);}
     | tLPAREN expression tRPAREN     {$$ = makeTERMexpression($2);}
     | tNOT term                      {$$ = makeTERMnot($2);}
     | tPIPE expression tPIPE         {$$ = makeTERMabsolute($2);}
     | tINT                           {$$ = makeTERMnum($1);}
     | tTRUE                          {$$ = makeTERMboolean(0);}
     | tFALSE                         {$$ = makeTERMboolean(1);}
     | tNULL                          {$$ = makeTERMboolean(-1);}
;

act_list : /* empty */
         | exp_list         {$$ = makeLISTact($1);}
;

exp_list : expression                   {$$ = makeLISTexp($1);}
         | expression tCOMMA exp_list   {$$ = makeLISTexplist($1, $3);}
;

%%
