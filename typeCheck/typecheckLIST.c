#include "../headers/symbol.h"
#include "../headers/tree.h"
#include "../headers/typecheck.h"
#include <stdio.h>


int typeCheckLIST(SymbolTable* symbolTable, LIST* list){
  if (debug){
    printf("LIST kind: %i\n", list->kind);
  }
  switch (list->kind) {
    case parK:
      // printf("par\n");
      typeCheckLIST(symbolTable, list->val.parL);
      break;

    case varlistK:
      // printf("varlist\n");
      typeCheckTYPE(symbolTable, list->val.varlistL.var_type);
      typeCheckLIST(symbolTable, list->val.varlistL.var_decl_list);
      break;

    case varK:
      // printf("var\n");
      typeCheckTYPE(symbolTable, list->val.varL);
      break;

    case decK:
      // printf("dec\n");
      typeCheckDEC(symbolTable, list->val.decL.declaration);

      if (list->val.decL.decl_list != NULL){
        typeCheckLIST(symbolTable, list->val.decL.decl_list);
      }
      break;

    case stateK:
      // printf("state\n");
      typeCheckSTM(symbolTable, list->val.stateL);
      break;

    case statelistK:
      // printf("statelist\n");
      typeCheckSTM(symbolTable, list->val.statelistL.statement);
      typeCheckLIST(symbolTable, list->val.statelistL.statement_list);
      break;

    case actlistK:
      // printf("actlist\n");
      typeCheckLIST(symbolTable, list->val.actlistL);
      break;

    case expressionK:
      // printf("expression\n");
      typeCheckEXP(symbolTable, list->val.expressionL);
      break;

    case explistK:
      // printf("explist\n");
      typeCheckEXP(symbolTable, list->val.explistL.expression);
      typeCheckLIST(symbolTable, list->val.explistL.exp_list);
      break;

    default:
      printf("default case in typeCheckLIST\n");
      break;
  }

  return 0;
}
