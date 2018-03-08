#ifndef TYPECHECK_H
#define TYPECHECK_H

#include "tree.h"

#define INTEGER 0
#define STRING 1
#define FUNCTION 2
#define ID 3


int typeCheckFUNC(FUNC* body, SymbolTable* symbolTable);

int typeCheckTYPE(TYPE* type, SymbolTable* symbolTable);

int typeCheckDEC(DEC* declaration, SymbolTable* symbolTable);

int typeCheckSTM(STM* statement, SymbolTable* symbolTable);

int typeCheckTERM(TERM* term, SymbolTable* symbolTable);

int typeCheckEXP(EXP* expression, SymbolTable* symbolTable);

int typeCheckLIST(LIST* list, SymbolTable* symbolTable);

SymbolTable* decCheck(SymbolTable* parent, STM* decleration);


#endif
