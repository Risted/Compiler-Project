#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckLIST(SymbolTable* symbolTable, LIST* list){
  switch (list->kind) {
    case decK:
      printf("LIST decK\n");
      typeCheckDEC(symbolTable, list->val.decL.declaration);

      if (list->val.decL.decl_list != NULL){
        printf("You should not be here\n");
        typeCheckLIST(symbolTable, list->val.decL.decl_list);
      }
      break;

    case stateK:
      printf("LIST stateK\n");
      typeCheckSTM(symbolTable, list->val.stateL);
      break;

    case varK:
      printf("LIST varK\n");
      typeCheckTYPE(symbolTable, list->val.varL);
      break;

    default:
      printf("default case in typeCheckLIST\n");
      break;
  }

  return 0;
}
