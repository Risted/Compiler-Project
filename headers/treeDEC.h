#ifndef __treeDEC_h
#define __treeDEC_h

typedef struct DEC_LIST{
  int lineno;
  struct DEC *head;
}DEC_LIST;

typedef struct DEC{
  int lineno;
  enum{integerK, stringK}kind;
  char *id;
  union{
    char *stringE;
    int integerE;
  }val;
  struct DEC *next;
}DEC;

DEC_LIST *makeDEClist(DEC *dec);

DEC *makeDECint(int integer);

DEC *makeDECstring(char *string);

void *addDEC(DEC_LIST *list, DEC *dec);

#endif
