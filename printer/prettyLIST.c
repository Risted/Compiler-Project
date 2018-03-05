#include <stdio.h>
#include "../headers/pretty.h"

void prettyLIST(LIST *l){
  //printf("entering pretty list\n");
  switch (l->kind) {
    case parK:
      //printf("par: \n");
      prettyLIST(l->val.parL);
      break;
    case varlistK:
      //printf("varlist: \n");
      prettyTYPE(l->val.varlistL.var_type);
      prettyLIST(l->val.varlistL.var_decl_list);
      break;
    case varK:
      //printf("var: \n");
      prettyTYPE(l->val.varL);
      //printf("end of var\n");
      break;
    case decK:
      //printf("dec: \n");
      prettyDEC(l->val.decL.declaration);
      //printf("dec_list: \n");
      //TODO this has been out commented because it caused dublicating prints
      //but I think it i a problem with our structures
      //prettyLIST(l->val.decL.decl_list);
      break;
    case stateK:
      //printf("state: \n");
      prettySTM(l->val.stateL);
      break;
    case statelistK:
      //printf("statelist: \n");
      prettySTM(l->val.statelistL.statement);
      prettyLIST(l->val.statelistL.statement_list);
      break;
    case actlistK:
      //printf("actlist: \n");
      prettyLIST(l->val.actlistL);
      break;
    case expressionK:
      //printf("expression: \n");
      prettyEXP(l->val.expressionL);
      break;
    case explistK:
      //printf("explist: \n");
      prettyEXP(l->val.explistL.expression);
      prettyLIST(l->val.explistL.exp_list);
      break;
  }
}
