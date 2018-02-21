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

TYPE* makeTYPEintconst(int intconst){
  TYPE *t;
  t = NEW(TYPE);
  t->lineno = lineno;
  t->kind = intconstK;
  t->val.intconstT = intconst;
  return t;
}
TYPE* makeTYPEbool(char *boolean){
  TYPE *t;
  t = NEW(TYPE);
  t->lineno = lineno;
  t->kind = boolK;
  if(boolean == "true"){
    t->val.boolT = 0; //i think
  }else{
    t->val.boolT = 1;
  }
}

TYPE* makeTYPEarray(TYPE *type){
  return NULL;
}

TYPE* makeTYPErecord(LIST *var_decl_list){
  return NULL;
}

TYPE* makeTYPEvarexp(char *id, EXP *expression){
  TYPE *t;
  t = NEW(TYPE);
  t->lineno = lineno;
  t->kind = varexpK;
  t->val.varexpT.id = id;
  t->val.varexpT.expression = expression;
  return t;
}

TYPE* makeTYPEvar(char *id, TYPE *type){
  TYPE *t;
  t = NEW(TYPE);
  t->lineno = lineno;
  t->kind = vareK;
  t->val.varT.id = id;
  t->val.varT.type = type;
  return t;
}
