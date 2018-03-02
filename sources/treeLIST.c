#include "stdio.h"
#include "../headers/tree.h"
#include "../headers/memory.h"

extern int lineno;

LIST* makeLISTpar(LIST* var_decl_list){
  LIST *list;
  list = NEW(LIST);
  list->lineno = lineno;
  list->kind = parK;
  list->val.parL = var_decl_list;
  return list;
}

LIST *makeLISTdecl(DEC* declaration, LIST* decl_list){
  LIST *head;
  head = NEW(LIST);
  head->lineno = lineno;
  head->kind = decK;
  head->val.decL.declaration = declaration;
  head->val.decL.decl_list = decl_list;
  return head;
}

LIST* makeLISTvarlist(TYPE* var_type, LIST* var_decl_list){
  LIST *list;
  list = NEW(LIST);
  list->lineno = lineno;
  list->kind = varlistK;
  list->val.varlistL.var_type = var_type;
  list->val.varlistL.var_decl_list = var_decl_list;
  return list;
}
LIST* makeLISTvar(TYPE* var_type){
  LIST *list;
  list = NEW(LIST);
  list->lineno = lineno;
  list->kind = varK;
  list->val.varL= var_type;
  return list;
}

LIST* makeLISTstate(STM* statement){
  LIST *list;
  list = NEW(LIST);
  list->lineno = lineno;
  list->kind = stateK;
  list->val.stateL = statement;
  return list;
}

LIST* makeLISTstatelist(STM* statement, LIST* statement_list){
  LIST *list;
  list = NEW(LIST);
  list->lineno = lineno;
  list->kind = statelistK;
  list->val.statelistL.statement = statement;
  list->val.statelistL.statement_list = statement_list;
  return list;
}
