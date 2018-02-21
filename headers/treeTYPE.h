#ifndef __treeTYPE_h
#define __treeTYPE_h

typedef struct TYPE {
  int lineno;
  enum {idK, intconstK, varK} kind;
  union {
    char *idT;
    int intconstT;
    struct {char* id; struct TYPE* type;} varT;
  } val;
} TYPE;

TYPE* makeTYPEid(char* id);

TYPE* makeTYPEintconst(int intconst);

TYPE* makeTYPEvar(char* id, TYPR* type);

#endif
