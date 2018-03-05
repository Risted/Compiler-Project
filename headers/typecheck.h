#ifndef TYPECHECK_H
#define TYPECHECK_H

#include "tree.h"

#define INTEGER 0
#define STRING 1

int typeCheck(FUNC* body);

SymbolTable* decCheck(SymbolTable* parent, STM* decleration);

#endif
