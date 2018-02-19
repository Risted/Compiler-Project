#ifndef __treeTYPE_h
#define __treeTYPE_h

typedef struct TYPE {
  int lineno;
  enum {idK, intconstK} kind;
  union {
    char *idT;
    int intconstT;
  } val;
} TYPE;

TYPE* makeTYPEid(char* id);

TYPE* makeTYPEintconst(int intconst);

#endif
