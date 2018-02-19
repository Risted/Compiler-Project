#ifndef __treeTERM_h
#define __treeTERM_h

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

TERM* makeTERMidtype(char* id, TYPE* type);

TERM* makeTERMabsolute(EXP* expression);

TERM* makeTERMnot(TERM* term);

TERM* makeTERMnum(int num);

TERM* makeTERMexpression(EXP* expression);

TERM* makeTERMboolean(int value);

#endif
