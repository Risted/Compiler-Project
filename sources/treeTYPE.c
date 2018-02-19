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
