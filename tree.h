#ifndef __tree_h
#define __tree_h

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

typedef struct STM {
  int lineno;
  enum {returnK, writeK, allocateK, allocateoflengthK, assignK, ifthenK,
    ifelseK, whileK} kind;
  union {
    struct EXP* returnS;
    struct EXP* writeS;
    struct TYPE* allocateS;
    struct {struct TYPE *variable; struct EXP *expression;} allocateoflengthS;
    struct {struct TYPE *variable; struct EXP *expression;} assignS;
    struct {struct EXP *ifState; struct STM* thenState;} ifthenS;
    struct {struct EXP* ifState; struct STM* thenState; struct STM* elseState;} ifelseS;
    struct {struct EXP* expression; struct STM* statement;} whileS;
  } val;
} STM;

typedef struct EXP {
  int lineno;
  enum {equaltoK, nequaltoK, andK, orK, smallerK, biggerK, termK,
    smalequalK, bigequalK, moduloK, timesK, divK, plusK, minusK} kind;
  union {
    struct {struct EXP *left; struct EXP *right;} equaltoE;
    struct {struct EXP *left; struct EXP *right;} nequaltoE;
    struct {struct EXP *left; struct EXP *right;} andE;
    struct {struct EXP *left; struct EXP *right;} orE;
    struct {struct EXP *left; struct EXP *right;} smallerE;
    struct {struct EXP *left; struct EXP *right;} biggerE;
    struct {struct EXP *left; struct EXP *right;} smalequalE;
    struct {struct EXP *left; struct EXP *right;} bigequalE;
    struct {struct EXP *left; struct EXP *right;} moduloE;
    struct {struct EXP *left; struct EXP *right;} timesE;
    struct {struct EXP *left; struct EXP *right;} divE;
    struct {struct EXP *left; struct EXP *right;} plusE;
    struct {struct EXP *left; struct EXP *right;} minusE;
    struct TERM* termE;
  } val;
} EXP;

typedef struct TERM {
  int lineno;
  enum {idtypeK, notK, absoluteK, numK, expK,booleanK} kind;
  union {
    struct TERM* notT;
    struct EXP * absoluteT;
    int numT;
    struct {char* id; struct TYPE* type;} idtypeT;
    struct EXP* expT;
    int booleanT;
  } val;
} TERM;

typedef struct TYPE {
  int lineno;
  enum {idK, intconstK} kind;
  union {
    char *idT;
    int intconstT;
  } val;
} TYPE;

EXP *makeEXPequalto(EXP *left, EXP *right);

EXP *makeEXPnoequalto(EXP *left, EXP *right);

EXP *makeEXPand(EXP *left, EXP *right);

EXP *makeEXPsmaller(EXP *left, EXP *right);

EXP *makeEXPbigger(EXP *left, EXP *right);

EXP *makeEXPsmalequal(EXP *left, EXP *right);

EXP *makeEXPbigequal(EXP *left, EXP *right);

EXP *makeEXPmodulo(EXP *left, EXP *right);

EXP *makeEXPtimes(EXP *left, EXP *right);

EXP *makeEXPdiv(EXP *left, EXP *right);

EXP *makeEXPplus(EXP *left, EXP *right);

EXP *makeEXPminus(EXP *left, EXP *right);

EXP* makeEXPterm(TERM* term);

STM* makeSTMreturn(EXP* expression);

STM* makeSTMwrite(EXP* expression);

STM* makeSTMallocate(TYPE* variable);

STM* makeSTMallocateoflength(TYPE* variable, EXP* expression);

STM* makeSTMassign(TYPE* variable, EXP* expression);

STM* makeSTMifthen(EXP* expression, STM* statement);

STM* makeSTMifelse(EXP* expression, STM* statement, STM* elseStatement);

STM* makeSTMwhile(EXP* expression, STM* statement);

TERM* makeTERMidtype(char* id, TYPE* type);

TERM* makeTERMabsolute(EXP* expression);

TERM* makeTERMnot(TERM* term);

TERM* makeTERMnum(int num);

TERM* makeTERMexpression(EXP* expression);

TERM* makeTERMboolean(int value);

TYPE* makeTYPEid(char* id);

TYPE* makeTYPEintconst(int intconst);

DEC_LIST *makeDEClist(DEC *dec);

DEC *makeDECint(int integer);

DEC *makeDECstring(char *string);

void *addDEC(DEC_LIST *list, DEC *dec);

#endif
