CC = gcc

CFLAGS  = -std=c11
CLFAGS += -Wall
CFLAGS +=	-Wextra
CFLAGS += -pedantic

DEPS  = headers/memory.h
DEPS += headers/pretty.h
DEPS += headers/tree.h
DEPS += headers/typecheck.h
DEPS += headers/symbol.h

OBJ  = y.tab.o
OBJ += lex.yy.o
OBJ += main.o

OBJ += sources/treeDEC.o
OBJ += sources/treeEXP.o
OBJ += sources/treeSTM.o
OBJ += sources/treeTERM.o
OBJ += sources/treeTYPE.o
OBJ += sources/treeFUNC.o
OBJ += sources/treeLIST.o

OBJ += sources/prettyEXP.o
OBJ += sources/prettySTM.o
OBJ += sources/prettyTERM.o
OBJ += sources/prettyTYPE.o
OBJ += sources/prettyFUNC.o
OBJ += sources/prettyLIST.o
OBJ += sources/prettyDEC.o

OBJ += sources/memory.o
OBJ += sources/typecheck.o
OBJ += sources/symbol.o


main:             $(DEPS) $(OBJ)
	          $(CC) $(OBJ) -o compiler -lfl

y.tab.c y.tab.h:  exp.y
	          bison -y -d exp.y

lex.yy.c:         exp.l y.tab.h
	          flex exp.l

run:
	./compiler

clean:
	rm -f $(OBJ) compiler lex.yy.c y.tab.c y.tab.h
