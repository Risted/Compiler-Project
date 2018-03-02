#include "stdio.h"
#include "../headers/memory.h"
#include "../headers/tree.h"

extern int lineno;

EXP *makeEXPequalto(EXP *left, EXP *right){
  EXP *e;
  e = NEW(EXP);
  e->lineno = lineno;
  e->kind = equaltoK;
  e->val.equaltoE.left = left;
  e->val.equaltoE.right = right;
  return e;
}

EXP *makeEXPnoequalto(EXP *left, EXP *right){
  EXP *e;
  e = NEW(EXP);
  e->lineno = lineno;
  e->kind = nequaltoK;
  e->val.nequaltoE.left = left;
  e->val.nequaltoE.right = right;
  return e;
}

EXP *makeEXPand(EXP *left, EXP *right){
  EXP *e;
  e = NEW(EXP);
  e->lineno = lineno;
  e->kind = andK;
  e->val.andE.left = left;
  e->val.andE.right = right;
  return e;
}

EXP *makeEXPsmaller(EXP *left, EXP *right){
  EXP *e;
  e = NEW(EXP);
  e->lineno = lineno;
  e->kind = smallerK;
  e->val.smallerE.left = left;
  e->val.smallerE.right = right;
  return e;
}

EXP *makeEXPbigger(EXP *left, EXP *right){
  EXP *e;
  e = NEW(EXP);
  e->lineno = lineno;
  e->kind = biggerK;
  e->val.biggerE.left = left;
  e->val.biggerE.right = right;
  return e;
}

EXP *makeEXPsmalequal(EXP *left, EXP *right){
  EXP *e;
  e = NEW(EXP);
  e->lineno = lineno;
  e->kind = smalequalK;
  e->val.smalequalE.left = left;
  e->val.smalequalE.right = right;
  return e;
}

EXP *makeEXPbigequal(EXP *left, EXP *right){
  EXP *e;
  e = NEW(EXP);
  e->lineno = lineno;
  e->kind = bigequalK;
  e->val.bigequalE.left = left;
  e->val.bigequalE.right = right;
  return e;
}

EXP *makeEXPmodulo(EXP *left, EXP *right){
  EXP *e;
  e = NEW(EXP);
  e->lineno = lineno;
  e->kind = moduloK;
  e->val.moduloE.left = left;
  e->val.moduloE.right = right;
  return e;
}

EXP *makeEXPtimes(EXP *left, EXP *right){
  EXP *e;
  e = NEW(EXP);
  e->lineno = lineno;
  e->kind = timesK;
  e->val.timesE.left = left;
  e->val.timesE.right = right;
  return e;
}

EXP *makeEXPdiv(EXP *left, EXP *right){
  EXP *e;
  e = NEW(EXP);
  e->lineno = lineno;
  e->kind = divK;
  e->val.divE.left = left;
  e->val.divE.right = right;
  return e;
}

EXP *makeEXPplus(EXP *left, EXP *right){
  EXP *e;
  e = NEW(EXP);
  e->lineno = lineno;
  e->kind = plusK;
  e->val.plusE.left = left;
  e->val.plusE.right = right;
  return e;
}

EXP *makeEXPminus(EXP *left, EXP *right){
  EXP *e;
  e = NEW(EXP);
  e->lineno = lineno;
  e->kind = minusK;
  e->val.minusE.left = left;
  e->val.minusE.right = right;
  return e;
}

EXP* makeEXPterm(TERM* term){
  EXP *e;
  e = NEW(EXP);
  e->lineno = lineno;
  e->kind = termK;
  e->val.termE = term;
  return e;
}

LIST* makeLISTact(LIST* exp_list){
  LIST *list;
  list = NEW(LIST);
  list->lineno = lineno;
  list->kind = actlistK;
  list->val.actlistL = exp_list;
  return list;
}

LIST* makeLISTexp(EXP* expression){
  LIST *list;
  list = NEW(LIST);
  list->lineno = lineno;
  list->kind = expressionK;
  list->val.expressionL = expression;
  return list;
}

LIST* makeLISTexplist(EXP* expression, LIST* exp_list){
  LIST *list;
  list = NEW(LIST);
  list->lineno = lineno;
  list->kind = explistK;
  list->val.explistL.expression = expression;
  list->val.explistL.exp_list = exp_list;
  return list;
}
EXP* makeEXPor(EXP *left, EXP *right){
  EXP *e;
  e = NEW(EXP);
  e->lineno = lineno;
  e->kind = orK;
  e->val.orE.left = left;
  e->val.orE.right = right;
  return e;
}
