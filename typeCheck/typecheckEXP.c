#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckEXP(SymbolTable* symbolTable, EXP* expression){
  switch (expression->kind) {
    case termK:
      printf("EXP termK\n");
      typeCheckTERM(symbolTable, expression->val.termE);
      break;

    default:
      printf("default case in typeCheckEXP\n");
      break;
  }

  return 0;
}
