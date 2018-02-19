#include "headers/pretty.h"
#include "headers/tree.h"
#include <stdio.h>

int lineno;

void yyparse();

FILE* yyin;

EXP *theexpression;
STM* thestatement;

int main(){
  lineno = 1;
  yyin = fopen("test.sk", "r");
  yyparse();
  prettySTM(thestatement);
  fclose(yyin);
  printf("\n");
  return 0;
}
