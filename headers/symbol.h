#ifndef SYMBOL_H
#define SYMBOL_H

#define HashSize 317

/* SYMBOL will be extended later.
   Function calls will take more parameters later.
*/

typedef struct Symbol {
  char *name;
  int value;
  struct Symbol *next;
} Symbol;

typedef struct SymbolTable {
  Symbol *table[HashSize];
  struct SymbolTable *next;
} SymbolTable;

int Hash(char *str);

SymbolTable *initSymbolTable();

SymbolTable *scopeSymbolTable(SymbolTable *t);

Symbol *putSymbol(SymbolTable *t, char *name, int value);

Symbol *getSymbol(SymbolTable *t, char *name);

void dropLinkedList(Symbol *s);

void dumpSymbolTable(SymbolTable *t);

#endif
