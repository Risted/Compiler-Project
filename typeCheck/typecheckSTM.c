#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckSTM(STM* statement, SymbolTable* symbolTable){
  switch (statement->kind) {
    case assignK:
      printf("STM assignK\n");
      typeCheckTYPE(statement->val.assignS.variable, symbolTable);
      typeCheckEXP(statement->val.assignS.expression, symbolTable);
      break;
      
    default:
      printf("default case in typeCheckSTM\n");
      break;
  }
  return 0;
}
