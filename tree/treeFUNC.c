#include "stdio.h"
#include "../headers/memory.h"
#include "../headers/tree.h"

extern int lineno;

FUNC* makeFUNC(FUNC* head, FUNC* body, FUNC* tail){
  FUNC *func;
  func = NEW(FUNC);
  func->lineno = lineno;
  func->kind = functionK;
  func->val.functionF.head = head;
  func->val.functionF.body = body;
  func->val.functionF.tail = tail;
  return func;
}

FUNC* makeFUNChead(char* id, LIST* par_decl_list, TYPE* type){
  FUNC *func;
  func = NEW(FUNC);
  func->lineno = lineno;
  func->kind = headK;
  func->val.headF.id = id;
  func->val.headF.par_decl_list = par_decl_list;
  func->val.headF.type = type;
  return func;
}

FUNC* makeFUNCbody(LIST* decl_list, LIST* statement_list){
  FUNC *func;
  func = NEW(FUNC);
  func->lineno = lineno;
  func->kind = bodyK;
  func->val.bodyF.decl_list = decl_list;
  func->val.bodyF.statement_list = statement_list;
  return func;
}

FUNC* makeFUNCtail(char* id){
  FUNC *func;
  func = NEW(FUNC);
  func->lineno = lineno;
  func->kind = tailK;
  func->val.tailF = id;
  return func;
}
