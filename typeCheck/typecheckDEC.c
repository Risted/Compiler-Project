#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckDEC(SymbolTable* symbolTable, DEC* declaration){
  switch (declaration->kind) {
    case listK:
      // printf("DEC listK\n");
      typeCheckLIST(symbolTable, declaration->val.listD);
      break;
    case dectypeK:
      typeCheckTYPE(symbolTable, declaration->val.dectypeD.type);
      break;
    case decfuncK:
      typeCheckFUNC(symbolTable, declaration->val.decfuncD);
      break;
    default:
      printf("default case in typeCheckDEC\n");
      break;
  }
  return 0;
}
