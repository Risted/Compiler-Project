#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckSTM(SymbolTable* symbolTable, STM* statement){
  switch (statement->kind) {
    case assignK:
      printf("STM assignK\n");
      typeCheckTYPE(symbolTable, statement->val.assignS.variable);
      typeCheckEXP(symbolTable, statement->val.assignS.expression);
      break;

    default:
      printf("default case in typeCheckSTM\n");
      break;
  }
  return 0;
}
