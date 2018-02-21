#ifndef __treeFUNC_h
#define __treeFUNC_h

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

FUNC* makeFUNC(HEAD* head, BODY* body, TAIL* tail);

FUNC* makeFUNChead(char* id, LIST* par_decl_list, TYPE* type);

FUNC* makeFUNCbody(LIST* decl_list, LIST* statement_list);

FUNC* makeFUNCtail(char* id);

#endif
