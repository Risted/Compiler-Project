#ifndef __treeLIST_h
#define __treeLIST_h

typedef struct LIST {
  int lineno;
  enum {parK, varlistK, varK, decK, stateK, statelistK, actlistK, expK, explistK} kind;
  union {
    struct LIST* var_decl_list parL;
    struct {struct TYPE* var_type; struct LIST* var_decl_list;} varlistL;
    struct TYPE* var_type varL;
    struct {struct DEC* declaration; struct LIST* decl_list;} decL;
    struct STM* statement stateL;
    struct {struct STM* statement; struct LIST* statement_list;} statelistL;
    struct LIST* exp_list actlistL;
    struct EXP* expression expL;
    struct {struct EXP* expression; struct LIST* exp_list;} explistL;
  } val;
} LIST;

LIST* makeLISTpar(LIST* var_decl_list);

LIST* makeLISTvarlist(TYPE* var_type, LIST* var_decl_list);

LIST* makeLISTvar(TYPE* var_type);

LIST* makeLISTdecl(DEC* declaration, LIST* decl_list);

LIST* makeLISTstate(STM* statement);

LIST* makeLISTstatelist(STM* statement, LIST* statement_list);

LIST* makeLISTact(LIST* exp_list);

LIST* makeLISTexp(EXP* expression);

LIST* makeLISTexplist(EXP* expression, LIST* exp_list);

#endif
