#include <stdio.h>
#include "headers/symbol.h"
#include "headers/pretty.h"
#include "headers/tree.h"
#include "headers/typecheck.h"
#include "headers/weed.h"
int lineno;
int debug;
void yyparse();

FILE* yyin;

FUNC* thebody;

int main(){
  lineno = 1;
  //set debug to 1 to enter debug mode
  debug = 0;
  SymbolTable* root = initSymbolTable();
  yyin = fopen("test.sk", "r");
  yyparse();
  if (debug){
    prettyFUNC(thebody);
  }
  int doesItWork = typeCheckFUNC(root, thebody);
  printf("\n");
  fclose(yyin);
  // printf("doesItWork = %i\n", doesItWork);
  return 0;
}
