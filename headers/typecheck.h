#ifndef TYPECHECK_H
#define TYPECHECK_H

#include "tree.h"

#define INTEGER 0
#define BOOLEAN 1
#define FUNCTION 2
#define ID 3


int typeCheckFUNC(SymbolTable* symbolTable, FUNC* body);

int typeCheckTYPE(SymbolTable* symbolTable, TYPE* type);

int typeCheckDEC(SymbolTable* symbolTable, DEC* declaration);

int typeCheckSTM(SymbolTable* symbolTable, STM* statement);

int typeCheckTERM(SymbolTable* symbolTable, TERM* term);

int typeCheckEXP(SymbolTable* symbolTable, EXP* expression);

int typeCheckLIST(SymbolTable* symbolTable, LIST* list);

#endif
