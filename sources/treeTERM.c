#include "stdio.h"
#include "../headers/memory.h"
#include "../headers/tree.h"

extern int lineno;

TERM* makeTERMidtype(char* id, TYPE* type){
  TERM *t;
  t = NEW(TERM);
  t->lineno = lineno;
  t->kind = idtypeK;
  t->val.idtypeT.id = id;
  t->val.idtypeT.type = type;
  return t;
}

TERM* makeTERMnot(TERM* term){
  TERM *t;
  t = NEW(TERM);
  t->lineno = lineno;
  t->kind = notK;
  t->val.notT = term;
  return t;
}

TERM* makeTERMabsolute(EXP* expression){
  TERM *t;
  t = NEW(TERM);
  t->lineno = lineno;
  t->kind = absoluteK;
  t->val.absoluteT = expression;
  return t;
}

TERM* makeTERMnum(int num){
  TERM *t;
  t = NEW(TERM);
  t->lineno = lineno;
  t->kind = numK;
  t->val.numT = num;
  return t;
}

TERM* makeTERMexpression(EXP* expression){
  TERM *t;
  t = NEW(TERM);
  t->lineno = lineno;
  t->kind = expK;
  t->val.expT = expression;
  return t;
}
TERM* makeTERMboolean(int value){
  TERM *t;
  t = NEW(TERM);
  t->lineno = lineno;
  t->kind = booleanK;
  t->val.booleanT = value;
  return t;
}
