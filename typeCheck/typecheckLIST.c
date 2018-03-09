#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckLIST(LIST* list, SymbolTable* symbolTable){
  switch (list->kind) {
    case decK:
      printf("LIST decK\n");
      typeCheckDEC(list->val.decL.declaration, symbolTable);

      if (list->val.decL.decl_list != NULL){
        printf("You should not be here\n");
        typeCheckLIST(list->val.decL.decl_list, symbolTable);
      }
      break;

    case stateK:
      printf("LIST stateK\n");
      typeCheckSTM(list->val.stateL, symbolTable);
      break;

    case varK:
      printf("LIST varK\n");
      typeCheckTYPE(list->val.varL, symbolTable);
      break;

    default:
      printf("default case in typeCheckLIST\n");
      break;
  }

  return 0;
}
