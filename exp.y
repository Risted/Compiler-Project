%{
#include <stdio.h>
#include "tree.h"

extern char *yytext;
extern EXP *theexpression;

void yyerror() {
   printf("syntax error before %s\n",yytext);
}
%}

%union {
   int intconst;
   char *stringconst;
   struct EXP *exp;
   struct Type type;
   struct Par_decl_list par_decl_list;
}

%token <intconst> tINTCONST
%token <stringconst> tIDENTIFIER

%type <exp> program exp
%type <par_decl_list> par_decl_list

%start program

%left '+' '-'
%left '*' '/' '%'

%%
program: exp
         { theexpression = $1;}
;
exp           :"function id (" par_decl_list "):" type
              {$$ = makeHead($2,$4);}
type          :tIDENTIFIER
              {$$ = makeEXPid($1);}
par_decl_list : par_decl_list par_decl_list {$$ = makeParList($1,$2)}
              | par_decl_list
;

%%
