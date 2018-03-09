#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckDEC(DEC* declaration, SymbolTable* symbolTable){
  switch (declaration->kind) {
    case listK:
      printf("DEC listK\n");
      typeCheckLIST(declaration->val.listD, symbolTable);
      break;
      
    default:
      printf("default case in typeCheckDEC\n");
      break;
  }
  return 0;
}
