#ifndef __tree_h
#define __tree_h

typedef struct EXP {
  int lineno;
  enum {idK, intconstK, equaltoK, nequaltoK, andK, smallerK, biggerK,
    smalequalK, bigequalK, moduloK, timesK, divK, plusK, minusK} kind;
  union {
    char *idE;
    int intconstE;
    struct {struct EXP *left; struct EXP *right;} equaltoE;
    struct {struct EXP *left; struct EXP *right;} nequaltoE;
    struct {struct EXP *left; struct EXP *right;} andE;
    struct {struct EXP *left; struct EXP *right;} smallerE;
    struct {struct EXP *left; struct EXP *right;} biggerE;
    struct {struct EXP *left; struct EXP *right;} smalequalE;
    struct {struct EXP *left; struct EXP *right;} bigequalE;
    struct {struct EXP *left; struct EXP *right;} moduloE;
    struct {struct EXP *left; struct EXP *right;} timesE;
    struct {struct EXP *left; struct EXP *right;} divE;
    struct {struct EXP *left; struct EXP *right;} plusE;
    struct {struct EXP *left; struct EXP *right;} minusE;
  } val;
} EXP;

typedef struct STM {
  int lineno;
  enum {returnK, writeK, allocateK, allocateoflengthK, assignK, ifthenK,
    ifelseK, whileK} kind;
  union {
    struct EXP* returnS;
    struct EXP* writeS;
    struct EXP* allocateS;
    struct {struct EXP *variable; struct EXP *expression;} allocateoflengthS;
    struct {struct EXP *variable; struct EXP *expression;} assignS;
    struct {struct EXP *ifState; struct STM* thenState;} ifthenS;
    struct {struct EXP* ifState; struct STM* thenState; struct STM* elseState;} ifelseS;
    struct {struct EXP* expression; struct STM* statement;} whileS;
  } val;
} STM;

EXP *makeEXPid(char *id);

EXP *makeEXPintconst(int intconst);

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

STM* makeSTMreturn(EXP* expression);

STM* makeSTMwrite(EXP* expression);

STM* makeSTMallocate(EXP* expression);

STM* makeSTMallocateoflength(EXP* variable, EXP* expression);

STM* makeSTMassign(EXP* variable, EXP* expression);

STM* makeSTMifthen(EXP* expression, STM* statement);

STM* makeSTMifelse(EXP* expression, STM* statement, STM* elseStatement);

STM* makeSTMwhile(EXP* expression, STM* statement);

#endif
