#include <stdio.h>
#include "headers/symbol.h"

int main(int argc, char const *argv[]) {

  char *string = "hello";
  int value = 42;

  char *string1 = "kitty";
  int value1 = 9000;

  // int hashValue;
  // int hashValue1;
  // hashValue = Hash(string);
  // hashValue1 = Hash(string1);
  //
  // printf("hashValue %i\n", hashValue);
  // printf("hashValue %i\n", hashValue1);

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


  // printf("newSymbol name %s\n", newSymbol->name);
  // printf("newSymbol name using symbol %s\n", symbol->next->name);


  // printf("newSymbol value %i\n", newSymbol->value);
  // printf("newSymbol value using symbol %i\n", symbol->next->value);

  // printf("symbol->next pointer %p\n", symbol->next);
  // printf("newSymbol pointer %p\n", newSymbol);
  // printf("newSymbol->next pointer %p\n", newSymbol->next);

  Symbol *alsoNewSymbol;
  alsoNewSymbol = putSymbol(newTable, string2, value2);

  Symbol *newNewSymbol;
  newNewSymbol = putSymbol(newTable, string3, value3);

  // Symbol *getThisSymbol;
  // getThisSymbol = getSymbol(newTable, string);

  dumpSymbolTable(newTable);

  return 0;
}
