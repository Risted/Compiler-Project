#ifndef __treeSTM_h
#define __treeSTM_h

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

STM* makeSTMreturn(EXP* expression);

STM* makeSTMwrite(EXP* expression);

STM* makeSTMallocate(TYPE* variable);

STM* makeSTMallocateoflength(TYPE* variable, EXP* expression);

STM* makeSTMassign(TYPE* variable, EXP* expression);

STM* makeSTMifthen(EXP* expression, STM* statement);

STM* makeSTMifelse(EXP* expression, STM* statement, STM* elseStatement);

STM* makeSTMwhile(EXP* expression, STM* statement);

#endif
