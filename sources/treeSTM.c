#include "stdio.h"
#include "../headers/memory.h"
#include "../headers/tree.h"

extern int lineno;

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

STM* makeSTMallocate(TYPE* variable){
  STM *s;
  s = NEW(STM);
  s->lineno = lineno;
  s->kind = allocateK;
  s->val.allocateS = variable;
  return s;
}

STM* makeSTMallocateoflength(TYPE* variable, EXP* expression){
  STM *s;
  s = NEW(STM);
  s->lineno = lineno;
  s->kind = allocateoflengthK;
  s->val.allocateoflengthS.variable = variable;
  s->val.allocateoflengthS.expression = expression;
  return s;
}

STM* makeSTMassign(TYPE* variable, EXP* expression){
  STM *s;
  s = NEW(STM);
  s->lineno = lineno;
  s->kind = assignK;
  s->val.assignS.variable = variable;
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
  return s;
}
STM* makeSTMlist(LIST *statement_list){
  STM *s;
  s = NEW(STM);
  s->lineno;
  s->kind = stmlistK;
  s->val.listT = statement_list;
  return s;
}
