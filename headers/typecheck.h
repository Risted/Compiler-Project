
#ifndef TYPECHECK_H
#define TYPECHECK_H

#include "tree.h"

#define INTEGER 0
#define STRING 1

SymbolTable* typeCheck(FUNC* body);

#endif
