#include "stdio.h"
#include "../headers/memory.h"
#include "../headers/tree.h"

extern int lineno;

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
TERM* makeTERMvar(LIST* act_list){
  return NULL; //was not certain what do to
}
TERM* makeTERMact(LIST* act_list){
  return NULL; //was not certain what do to
}
