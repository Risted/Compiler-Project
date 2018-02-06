#include <stdio.h>
#include "headers/symbol.h"

int main(int argc, char const *argv[]) {

  char *string = "kitty";
  int value = 42;

  // int result = Hash(string);
  // printf("String hash value: %i\n", result);

  SymbolTable *newTable;
  printf("newTable address: %d\n", newTable);

  newTable = initSymbolTable();

  printf("newTable address: %d\n", newTable);


  printf("Size of table: %li\n", sizeof(newTable->table));

  SYMBOL *newSymbol;

  newSymbol = putSymbol(newTable, string, value);

  return 0;
}
