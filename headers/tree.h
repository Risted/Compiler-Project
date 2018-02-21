#ifndef __tree_h
#define __tree_h

typedef struct FUNC {
  int lineno;
  enum {functionK, headK, bodyK, tailK} kind;
  union {
    struct {struct HEAD* head; struct BODY* body; struct TAIL* tail;} functionF;
    struct {char* id; struct LIST* par_decl_list; struct TYPE* type;} headF;
    struct {struct LIST* decl_list; struct LIST* statement_list;} bodyF;
    char* id tailF;
  } val;
} FUNC;

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

typedef struct LIST {
  int lineno;
  enum {parK, varlistK, varK, decK, stateK, statelistK, actlistK, expressionK, explistK} kind;
  union {
    struct LIST* var_decl_list parL;
    struct {struct TYPE* var_type; struct LIST* var_decl_list;} varlistL;
    struct TYPE* var_type varL;
    struct {struct DEC* declaration; struct LIST* decl_list;} decL;
    struct STM* statement stateL;
    struct {struct STM* statement; struct LIST* statement_list;} statelistL;
    struct LIST* exp_list actlistL;
    struct EXP* expression expressionL;
    struct {struct EXP* expression; struct LIST* exp_list;} explistL;
  } val;
} LIST;

typedef struct TERM {
  int lineno;
  enum {idtypeK, notK, absoluteK, numK, expK, booleanK} kind;
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

typedef struct DEC{
  int lineno;
  enum{integerK, stringK}kind;
  char *id;
  union{
    char *stringE;
    int integerE;
  }val;
  struct DEC *next;
} DEC;



FUNC* makeFUNC(HEAD* head, BODY* body, TAIL* tail);

FUNC* makeFUNChead(char* id, LIST* par_decl_list, TYPE* type);

FUNC* makeFUNCbody(LIST* decl_list, LIST* statement_list);

FUNC* makeFUNCtail(char* id);


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


LIST* makeLISTpar(LIST* var_decl_list);

LIST* makeLISTvarlist(TYPE* var_type, LIST* var_decl_list);

LIST* makeLISTvar(TYPE* var_type);

LIST* makeLISTdecl(DEC* declaration, LIST* decl_list);

LIST* makeLISTstate(STM* statement);

LIST* makeLISTstatelist(STM* statement, LIST* statement_list);

LIST* makeLISTact(LIST* exp_list);

LIST* makeLISTexp(EXP* expression);

LIST* makeLISTexplist(EXP* expression, LIST* exp_list);


TERM* makeTERMidtype(char* id, TYPE* type);

TERM* makeTERMabsolute(EXP* expression);

TERM* makeTERMnot(TERM* term);

TERM* makeTERMnum(int num);

TERM* makeTERMexpression(EXP* expression);

TERM* makeTERMboolean(int value);


TYPE* makeTYPEid(char* id);

TYPE* makeTYPEintconst(int intconst);



DEC *makeDECint(int integer);

DEC *makeDECstring(char *string);

void *addDEC(DEC_LIST *list, DEC *dec);

#endif
