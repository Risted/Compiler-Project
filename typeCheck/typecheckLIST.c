#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckLIST(SymbolTable* symbolTable, LIST* list){
  switch (list->kind) {
    case parK:
      typeCheckLIST(symbolTable, list->val.parL);
      break;

    case varlistK:
      typeCheckTYPE(symbolTable, list->val.varlistL.var_type);
      typeCheckLIST(symbolTable, list->val.varlistL.var_decl_list);
      break;

    case varK:
      typeCheckTYPE(symbolTable, list->val.varL);
      break;

    case decK:
      typeCheckDEC(symbolTable, list->val.decL.declaration);

      if (list->val.decL.decl_list != NULL){
        typeCheckLIST(symbolTable, list->val.decL.decl_list);
      }
      break;

    case stateK:
      typeCheckSTM(symbolTable, list->val.stateL);
      break;

    case statelistK:
      typeCheckSTM(symbolTable, list->val.statelistL.statement);
      typeCheckLIST(symbolTable, list->val.statelistL.statement_list);
      break;

    case actlistK:
      typeCheckLIST(symbolTable, list->val.actlistL);
      break;

    case expressionK:
      typeCheckEXP(symbolTable, list->val.expressionL);
      break;

    case explistK:
      typeCheckEXP(symbolTable, list->val.explistL.expression);
      typeCheckLIST(symbolTable, list->val.explistL.exp_list);
      break;

    default:
      printf("default case in typeCheckLIST\n");
      break;
  }

  return 0;
}
