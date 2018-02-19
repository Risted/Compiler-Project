#include "stdio.h"
#include "../headers/memory.h"
#include "../headers/tree.h"

extern int lineno;

DEC_LIST *makeDEClist(DEC *dec){
  DEC_LIST *dl;
  dl = NEW(DEC_LIST);
  dl->lineno = lineno;
  dl->head = dec;
  return dl;
}

DEC *makeDECint(int integer){
  DEC *d;
  d = NEW(DEC);
  d->lineno = lineno;
  d->kind = integerK;
  d->val.integerE = integer;
  d->next = NULL;
  return d;
}

DEC *makeDECstring(char *string){
  DEC *d;
  d = NEW(DEC);
  d->lineno = lineno;
  d->kind = stringK;
  d->val.stringE = string;
  d->next = NULL;
  return d;
}

void *addDEC(DEC_LIST *list, DEC *dec){
  DEC *current = list->head;
  while(current->next != NULL){
    current = current->next;
  }
  current->next = dec;
}
