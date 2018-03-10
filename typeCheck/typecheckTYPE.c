#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckTYPE(SymbolTable* symbolTable, TYPE* type){
  switch (type->kind) {
    case idK:
      printf("TYPE idK\n");
      printf("Id is: %s\n", type->val.idT);
      break;

    case var_typeK:
      printf("TYPE var_typeK\n");
      printf("Id is: %s\n", type->val.var_typeT.id);
      typeCheckTYPE(symbolTable, type->val.var_typeT.variable);
      break;

    default:
      printf("default case in typeCheckTYPE\n");
      break;
  }
  return 0;
}
