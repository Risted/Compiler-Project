#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckDEC(DEC* declaration, SymbolTable* symbolTable){
  switch (declaration->kind) {
    case listK:
      printf("DEC var_list\n");
      typeCheckLIST(declaration->val.listD,symbolTable);
      break;
    case typeK:
      printf("DEC type\n");
      putSymbol(symbolTable, declaration->val.typeD.id, declaration->val.typeD.type, NULL);
      break;
    //TODO make the other switch cases
    default:
      printf("error typeCheckDEC, default case reached\n");
      break;
  }
  return 0;
}
