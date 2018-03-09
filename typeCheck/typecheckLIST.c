#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckLIST(LIST* list, SymbolTable* symbolTable){
  DEC* declaration;
  switch (list->kind) {
    case decK:
      printf("LIST decK\n");
      declaration = list->val.decL.declaration;
      while(list != NULL){
        typeCheckDEC(declaration, symbolTable);
        list = list->val.decL.decl_list;
        declaration = list->val.decL.declaration;
      }
      break;
    case var_listK:
      printf("LIST var_list\n");
      break;
    case varK:
      printf("LIST var\n");
      typeCheckTYPE(list->val.varL,symbolTable);
      break;
  //TODO add the remaining cases
    default:
      break;
  }
  return 0;
}
