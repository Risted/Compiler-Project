#ifndef __tree_h
#define __tree_h
typedef struct Type{
  int type;
}type;

typedef struct Par_decl_list {
  struct par_decl_list *next;
}par_decl_list;

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

par_decl_list *makeParList();
EXP *makeEXPid(char *id);

EXP *makeEXPintconst(int intconst);

EXP *makeEXPtimes(EXP *left, EXP *right);

EXP *makeEXPdiv(EXP *left, EXP *right);

EXP *makeEXPplus(EXP *left, EXP *right);

EXP *makeEXPminus(EXP *left, EXP *right);

EXP *makeEXPmodulo(EXP *left, EXP *right);

#endif
