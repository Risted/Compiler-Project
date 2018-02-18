
#include "stdio.h"
#include "memory.h"
#include "tree.h"

extern int lineno;


STM_list *initSTM(STM *head, STM *tail){
    STM_list *list;
    list = NEW(STM_list);
    list->lineno = lineno;
    list->statement = head;
    list->statement_list = linkSTM(tail);
    return list;
}
STM_list *linkSTM(STM *stm){
  STM_list *list;
  list = NEW(STM_list);
  list->lineno = lineno;
  list->statement = stm;
  list->statement_list = NULL;
  return list;
}

STM *makeSTMwrite(EXP *e){
  STM *stm;
  stm = NEW(STM);
  stm->lineno = lineno;
  stm->kind = writeK;
  stm->val.writeE = e;

  return stm;
}
STM *makeSTMreturn(EXP *e){
  STM *stm;
  printf("we make a return\n");
  stm = NEW(STM);
  stm->lineno = lineno;
  stm->kind = returnK;
  stm->val.returnE = e;

  printf("we return a return\n");
  return stm;
}
STM *makeSTMEXP(EXP *e){
  STM *stm;
  stm = NEW(STM);
  stm->lineno = lineno;
  stm->kind = expK;
  stm->val.expE = e;
  return stm;
}
EXP *makeEXPid(char *id)
{ EXP *e;
  e = NEW(EXP);
  e->lineno = lineno;
  e->kind = idK;
  e->val.idE = id;
  return e;
}

EXP *makeEXPintconst(int intconst)
{ EXP *e;
  e = NEW(EXP);
  e->lineno = lineno;
  e->kind = intconstK;
  e->val.intconstE = intconst;
  return e;
}


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
