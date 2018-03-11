#ifndef TYPECHECK_H
#define TYPECHECK_H

#include "tree.h"

int typeCheckFUNC(SymbolTable* symbolTable, FUNC* body);

int typeCheckTYPE(SymbolTable* symbolTable, TYPE* type);

int typeCheckDEC(SymbolTable* symbolTable, DEC* declaration);

int typeCheckSTM(SymbolTable* symbolTable, STM* statement);

int typeCheckTERM(SymbolTable* symbolTable, TERM* term);

int typeCheckEXP(SymbolTable* symbolTable, EXP* expression);

int typeCheckLIST(SymbolTable* symbolTable, LIST* list);

//Help functions
int findType(TYPE* type);

#endif
