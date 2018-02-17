#ifndef __tree_h
#define __tree_h

typedef struct STM {
  int lineno;
  enum{returnK,writeK,expK}kind;
  union{
    struct EXP *returnE;
    struct EXP *writeE;
    struct EXP *expE;
  } val;
} STM;

typedef struct EXP {
  int lineno;
  enum {idK,intconstK,timesK,divK,plusK,minusK,moduloK} kind;
  union {
    char *idE;
    int intconstE;
    struct {struct EXP *left; struct EXP *right;} timesE;
    struct {struct EXP *left; struct EXP *right;} divE;
    struct {struct EXP *left; struct EXP *right;} plusE;
    struct {struct EXP *left; struct EXP *right;} minusE;
    struct {struct EXP *left; struct EXP *right;} moduloE;
  } val;
} EXP;

STM *makeSTMreturn(EXP *e);

EXP *makeEXPid(char *id);

EXP *makeEXPintconst(int intconst);

EXP *makeEXPtimes(EXP *left, EXP *right);

EXP *makeEXPdiv(EXP *left, EXP *right);

EXP *makeEXPplus(EXP *left, EXP *right);

EXP *makeEXPminus(EXP *left, EXP *right);

EXP *makeEXPmodulo(EXP *left, EXP *right);

#endif
