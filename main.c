#include <stdio.h>
#include "headers/symbol.h"

int main() {

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

  putSymbol(table, string, value);

  putSymbol(table, string1, value1);

  putSymbol(newTable, string2, value2);

  putSymbol(newTable, string3, value3);

  dumpSymbolTable(newTable);

  return 0;
}
