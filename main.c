#include <stdio.h>
#include "headers/symbol.h"
#include "headers/pretty.h"
#include "headers/tree.h"
#include "headers/typecheck.h"
#include <stdio.h>

int lineno;

void yyparse();

FILE* yyin;

FUNC* thebody;

int main(){

  lineno = 1;
  yyin = fopen("test.sk", "r");
  yyparse();
  int doesItWork = typeCheck(thebody);
  fclose(yyin);
  // printf("doesItWork = %i\n", doesItWork);
  return 0;
}
