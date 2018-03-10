#include <stdio.h>
#include "../headers/pretty.h"

void prettyLIST(LIST *l){
  switch (l->kind) {
    case parK:
      prettyLIST(l->val.parL);
      break;

    case varlistK:
      prettyTYPE(l->val.varlistL.var_type);
      prettyLIST(l->val.varlistL.var_decl_list);
      break;

    case varK:
      prettyTYPE(l->val.varL);
      break;

    case decK:
      prettyDEC(l->val.decL.declaration);
      break;

    case stateK:
      prettySTM(l->val.stateL);
      break;

    case statelistK:
      prettySTM(l->val.statelistL.statement);
      prettyLIST(l->val.statelistL.statement_list);
      break;

    case actlistK:
      prettyLIST(l->val.actlistL);
      break;

    case expressionK:
      prettyEXP(l->val.expressionL);
      break;

    case explistK:
      prettyEXP(l->val.explistL.expression);
      prettyLIST(l->val.explistL.exp_list);
      break;

    default:
      printf("in default case in LIST\n");
      break;
  }
}
