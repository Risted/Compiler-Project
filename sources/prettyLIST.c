#include <stdio.h>
#include "../headers/pretty.h"

void prettyLIST(LIST *l){
  switch (l->kind) {
    case parK:
      printf("parK\n");
      prettyLIST(l->val.parL);
      break;
    case varlistK:
      printf("varlistK\n");
      prettyTYPE(l->val.varlistL.var_type);
      prettyLIST(l->val.varlistL.var_decl_list);
      break;
    case varK:
      printf("varK\n");
      prettyTYPE(l->val.varL);
      break;
    case decK:
      printf("decK\n");
      prettyDEC(l->val.decL.declaration);
      prettyLIST(l->val.decL.decl_list);
      break;
    case stateK:
      printf("stateK\n");
      prettySTM(l->val.stateL);
      break;
    case statelistK:
      printf("statelistK\n");
      prettySTM(l->val.statelistL.statement);
      prettyLIST(l->val.statelistL.statement_list);
      break;
    case actlistK:
      printf("actlistK\n");
      prettyLIST(l->val.actlistL);
      break;
    case expressionK:
      printf("expressionK\n");
      prettyEXP(l->val.expressionL);
      break;
    case explistK:
      printf("explistK\n");
      prettyEXP(l->val.explistL.expression);
      prettyLIST(l->val.explistL.exp_list);
      break;
  }
}
