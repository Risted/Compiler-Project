#include "tree.h"
#include "pretty.h"

int lineno;

void yyparse();

EXP *theexpression;
STM *thestatement;

int main()
{ lineno = 1;
  yyparse();
  prettySTM(thestatement);
  return 0;
}
