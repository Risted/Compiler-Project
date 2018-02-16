#ifndef __tree_h
#define __tree_h

typedef struct STM {
  int lineno;
  enum {returnK, ifThenK} kind;
  union {
    struct {struct EXP *right;} returnS;
    struct {struct EXP *left; struct STM *right} ifThenS;
  } val;
} STM;

typedef struct EXP {
  int lineno;
  enum {idK,intconstK,timesK,divK,plusK,minusK} kind;
  union {
    char *idE;
    int intconstE;
    struct {struct EXP *left; struct EXP *right;} timesE;
    struct {struct EXP *left; struct EXP *right;} divE;
    struct {struct EXP *left; struct EXP *right;} plusE;
    struct {struct EXP *left; struct EXP *right;} minusE;
  } val;
} EXP;

STM *makeSTMreturn(EXP *right);

STM *makeSTMifThen(EXP *left, STM *right);

EXP *makeEXPid(char *id);

EXP *makeEXPintconst(int intconst);

EXP *makeEXPtimes(EXP *left, EXP *right);

EXP *makeEXPdiv(EXP *left, EXP *right);

EXP *makeEXPplus(EXP *left, EXP *right);

EXP *makeEXPminus(EXP *left, EXP *right);


#endif
