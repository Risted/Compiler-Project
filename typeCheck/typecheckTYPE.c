#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckTYPE(SymbolTable* symbolTable, TYPE* type){
  int error;
  int typeCheck;
  Symbol* symbol;
  printf("TYPE KIND: %i\n", type->kind);
  switch (type->kind) {
    case idK:
      return 3;
      break;

    case intconstK:
      return INTEGER;
      break;

    case boolK:
      return BOOLEAN;
      break;

    case arrayK:
      typeCheckTYPE(symbolTable, type->val.arrayT);
      break;

    case recordK:
      typeCheckLIST(symbolTable, type->val.recordT);
      break;

    case vareK:
      typeCheckTYPE(symbolTable, type->val.vareT.variable);
      //TODO: find out how to do id
      break;

    case varexpK:
      typeCheckTYPE(symbolTable, type->val.varexpT.variable);
      typeCheckEXP(symbolTable, type->val.varexpT.expression);
      break;

    case var_typeK:
      //printf("here\n");
      typeCheck = typeCheckTYPE(symbolTable, type->val.var_typeT.variable);
      putSymbol(symbolTable,type->val.var_typeT.id,typeCheck,NULL);
      printf("putting id: %s of type: %i\n", type->val.var_typeT.id,typeCheck);
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
      printf("ERROR Message: not right type,  line %i\n", type->lineno);
      break;
  }

  return -1;
}
