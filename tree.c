#include "memory.h"
#include "tree.h"

extern int lineno;

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

STM* makeSTMreturn(EXP* expression){
  STM *s;
  s = NEW(STM);
  s->lineno = lineno;
  s->kind = returnK;
  s->val.returnS = expression;
  return s;
}

STM* makeSTMwrite(EXP* expression){
  STM *s;
  s = NEW(STM);
  s->lineno = lineno;
  s->kind = writeK;
  s->val.writeS = expression;
  return s;
}

STM* makeSTMallocate(EXP* variable){
  STM *s;
  s = NEW(STM);
  s->lineno = lineno;
  s->kind = allocateK;
  s->val.allocateS = variable;
  return s;
}

STM* makeSTMallocateoflength(EXP* variable, EXP* expression){
  STM *s;
  s = NEW(STM);
  s->lineno = lineno;
  s->kind = allocateoflengthK;
  s->val.allocateoflengthS.variable = variable;
  s->val.allocateoflengthS.expression = expression;
  return s;
}

STM* makeSTMassign(EXP* variable, EXP* expression){
  STM *s;
  s = NEW(STM);
  s->lineno = lineno;
  s->kind = assignK;
  s->val.assignS.expression = variable;
  s->val.assignS.expression = expression;
  return s;
}

STM* makeSTMifthen(EXP* expression, STM* statement){
  STM *s;
  s = NEW(STM);
  s->lineno = lineno;
  s->kind = ifthenK;
  s->val.ifthenS.ifState = expression;
  s->val.ifthenS.thenState = statement;
  return s;
}

STM* makeSTMifelse(EXP* expression, STM* statement, STM* elseStatement){
  STM *s;
  s = NEW(STM);
  s->lineno = lineno;
  s->kind = ifelseK;
  s->val.ifelseS.ifState = expression;
  s->val.ifelseS.thenState = statement;
  s->val.ifelseS.elseState = elseStatement;
  return s;
}

STM* makeSTMwhile(EXP* expression, STM* statement){
  STM *s;
  s = NEW(STM);
  s->lineno = lineno;
  s->kind = whileK;
  s->val.whileS.expression = expression;
  s->val.whileS.statement = statement;
  return s;}
