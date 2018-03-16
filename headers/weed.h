#ifndef __weed_h
#define __weed_h
#include "tree.h"


void* checkForDevideByZero(EXP* exp);
void* checkForTautaulogy(STM* stm);
void* checkForReturns(FUNC* func);
int EXPtautology(EXP *e);
//statements that always return true

#endif
