#include <stdio.h>
#include "../headers/pretty.h"

void prettyLIST(LIST *l){
  switch (l->kind) {
    case parK:
      printf("par: ");
      prettyLIST(l->val.parL);
      break;
    case varlistK:
      printf("varlist");
      prettyTYPE(l->val.varlistL.var_type);
      prettyLIST(l->val.varlistL.var_decl_list);
      break;
    case varK:
      printf("var");
      prettyTYPE(l->val.varL);
      break;
    case decK:
      printf("dec");
      prettyDEC(l->val.decL.declaration);
      prettyLIST(l->val.decL.decl_list);
      break;
    case stateK:
      printf("state");
      prettySTM(l->val.stateL);
      break;
    case statelistK:
      printf("statelist");
      prettySTM(l->val.statelistL.statement);
      prettyLIST(l->val.statelistL.statement_list);
      break;
    case actlistK:
      printf("actlist");
      prettyLIST(l->val.actlistL);
      break;
    case expressionK:
      printf("expression");
      prettyEXP(l->val.expressionL);
      break;
    case explistK:
      printf("explist");
      prettyEXP(l->val.explistL.expression);
      prettyLIST(l->val.explistL.exp_list);
      break;
  }
}
