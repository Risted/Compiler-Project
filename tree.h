#ifndef __tree_h
#define __tree_h


typedef struct BODY {
  int lineno;
  struct decl_list *decl_list;
  struct STM_list *statement_list;
}BODY;

typedef struct STM_list {
  int lineno;
  struct STM *statement;
  struct STM_list *statement_list;
}STM_list;

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

STM_list *initSTM(STM *head, STM *tail);

STM_list *linkSTM(STM *stm);

STM *makeSTMreturn(EXP *e);

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

EXP *makeEXPmodulo(EXP *left, EXP *right);

STM* makeSTMreturn(EXP* expression);

#endif
