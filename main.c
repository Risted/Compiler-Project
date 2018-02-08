#include <stdio.h>
#include "headers/symbol.h"

int main(int argc, char const *argv[]) {

  char *string = "hello";
  int value = 42;

  char *string1 = "kitty";
  int value1 = 9000;

  char *string2 = "hello";
  int value2 = 666;

  char *string3 = "prince";
  int value3 = 21;

  SymbolTable *table;
  table = initSymbolTable();

  SymbolTable *newTable;
  newTable = scopeSymbolTable(table);

  Symbol *symbol;
  symbol = putSymbol(table, string, value);

  Symbol *newSymbol;
  newSymbol = putSymbol(table, string1, value1);

  Symbol *alsoNewSymbol;
  alsoNewSymbol = putSymbol(newTable, string2, value2);

  Symbol *newNewSymbol;
  newNewSymbol = putSymbol(newTable, string3, value3);

  dumpSymbolTable(newTable);

  return 0;
}
