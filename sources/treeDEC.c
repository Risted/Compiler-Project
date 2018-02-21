#include "stdio.h"
#include "../headers/memory.h"
#include "../headers/tree.h"

extern int lineno;

LIST *makeDEClist(DEC *dec){
  LIST *declist;
  declist = NEW(LIST);
  declist->lineno = lineno;
  declist->kind = decK;
  declist->val.decL.declaration = dec;
  declist->val.decL.decl_list = NULL;
  return declist;
}

DEC *makeDECint(int integer){
  DEC *dec;
  dec = NEW(DEC);
  dec->lineno = lineno;
  dec->kind = integerK;
  dec->val.integerE = integer;
  return dec;
}

DEC *makeDECstring(char *string){
  DEC *dec;
  dec = NEW(DEC);
  dec->lineno = lineno;
  dec->kind = stringK;
  dec->val.stringE = string;
  return dec;
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
/*
void *addDEC(LIST *list, DEC *dec){
  makeDEClist(dec);

  LIST *current = list->val.decL;
  while(current->decl_list != NULL){
    current = current->decl_list.decL;
  }
  current->decl_list = makeDEClist(dec);
}*/
