#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckEXP(EXP* expression, SymbolTable* symbolTable){
  switch (expression->kind) {
    case termK:
      printf("EXP termK\n");
      typeCheckTERM(expression->val.termE, symbolTable);
      break;

    default:
      printf("default case in typeCheckEXP\n");
      break;
  }

  return 0;
}
