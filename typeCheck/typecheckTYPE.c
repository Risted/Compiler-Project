#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckTYPE(SymbolTable* symbolTable, TYPE* type){
  int error;
  int typeCheck;
  Symbol* symbol;
  // printf("KIND: %i\n", type->kind);
  switch (type->kind) {
    case idK:
      printf("TYPE idK\n");
      // printf("Id is: %s\n", type->val.idT);
      break;

    case intconstK:
      printf("TYPE intconstK\n");
      break;

    case var_typeK:
      printf("TYPE var_typeK\n");
      // printf("Id is: %s\n", type->val.var_typeT.id);
      error = typeCheckTYPE(symbolTable, type->val.var_typeT.variable);
      if (error == 0){
        typeCheck = findType(type->val.var_typeT.variable);
        printf("Typecheck: %i\n", typeCheck);
        symbol = putSymbol(symbolTable, type->val.var_typeT.id, typeCheck, NULL);
      }
      break;

    default:
      printf("default case in typeCheckTYPE\n");
      break;
  }
  return 0;
}


int findType(TYPE* type){
  switch (type->kind) {
    case intconstK:
      return INTEGER;
      break;

    case boolK:
      return BOOLEAN;
      break;

    default:
      printf("Error not right type\n");
      break;
  }

  return -1;
}
