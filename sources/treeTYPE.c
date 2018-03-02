#include "stdio.h"
#include "../headers/memory.h"
#include "../headers/tree.h"

extern int lineno;

TYPE* makeTYPEid(char* id){
  TYPE *t;
  t = NEW(TYPE);
  t->lineno = lineno;
  t->kind = idK;
  t->val.idT = id;
  return t;
}

TYPE* makeTYPEintconst(){
  TYPE *t;
  t = NEW(TYPE);
  t->lineno = lineno;
  t->kind = intconstK;
  return t;
}

TYPE* makeTYPEbool(){
  TYPE *t;
  t = NEW(TYPE);
  t->lineno = lineno;
  t->kind = boolK;
}

TYPE* makeTYPEarray(TYPE *type){
  TYPE *t;
  t = NEW(TYPE);
  t->lineno = lineno;
  t->kind = arrayK;
  t->val.arrayT = type;
  return t;
}

TYPE* makeTYPErecord(LIST *var_decl_list){
  TYPE *t;
  t = NEW(TYPE);
  t->lineno = lineno;
  t->kind = recordK;
  t->val.recordT = var_decl_list;
  return t;
}
TYPE* makeTYPEtype(char* id,TYPE *variable){
  TYPE *t;
  t = NEW(TYPE);
  t->lineno = lineno;
  t->kind = typeK;
  t->val.typeT.variable = variable;
  t->val.typeT.id = id;
  return t;
}
TYPE* makeTYPEvar(TYPE *variable, char* id){
  TYPE *t;
  t = NEW(TYPE);
  t->lineno = lineno;
  t->kind = vareK;
  t->val.varT.variable = variable;
  t->val.varT.id = id;
  return t;
}

TYPE* makeTYPEvarexp(TYPE* variable, EXP *expression){
  TYPE *t;
  t = NEW(TYPE);
  t->lineno = lineno;
  t->kind = varexpK;
  t->val.varexpT.variable = variable;
  t->val.varexpT.expression = expression;
  return t;
}
