#include "tree.h"
#include "pretty.h"
#include <stdio.h>

int lineno;

void yyparse();

EXP *theexpression;
STM* thestatement;

int main()
{ lineno = 1;
  yyparse();
  prettySTM(thestatement);
  printf("\n");
  return 0;
}
