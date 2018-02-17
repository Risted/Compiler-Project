#include "tree.h"
#include "pretty.h"
#include <stdio.h>

int lineno;

void yyparse();
STM *thestatement;
//EXP *theexpression;

int main()
{ lineno = 1;
  yyparse();
  prettySTM(thestatement);
  printf("\n");
  return 0;
}
