#ifndef TYPECHECK_H
#define TYPECHECK_H

#include "tree.h"

#define INTEGER 0
#define STRING 1
#define FUNCTION 2
#define ID 3


int typeCheck(FUNC* body, SymbolTable* symbolTable);

SymbolTable* decCheck(SymbolTable* parent, STM* decleration);

#endif
