#include <stdio.h>
#include "headers/symbol.h"

int main(int argc, char const *argv[]) {

  char *string = "kitty";
  int value = 42;

  char *string1 = "kitty";
  int value1 = 9000;

  // int result = Hash(string);
  // printf("String hash value: %i\n", result);

  SymbolTable *newTable;
  newTable = initSymbolTable();

  Symbol *newSymbol;
  newSymbol = putSymbol(newTable, string, value);

  Symbol *alsoNewSymbol;
  alsoNewSymbol = putSymbol(newTable, string1, value1);

  return 0;
}
