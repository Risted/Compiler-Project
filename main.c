#include "headers/pretty.h"
#include "headers/tree.h"
#include <stdio.h>

int lineno;

void yyparse();

FILE* yyin;

FUNC* thebody;
EXP *theexpression;
STM* thestatement;

int main(){
  lineno = 1;
  yyin = fopen("test.sk", "r");
  yyparse();
  prettyFUNC(thebody);
  fclose(yyin);
  printf("\n");
  return 0;
}
