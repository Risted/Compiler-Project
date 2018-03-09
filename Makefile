CC = gcc

CFLAGS  = -std=c11
CLFAGS += -Wall
CFLAGS +=	-Wextra
CFLAGS += -pedantic

DEPS  = headers/memory.h
DEPS += headers/pretty.h
DEPS += headers/tree.h
DEPS += headers/symbol.h
DEPS += headers/typecheck.h

OBJ  = y.tab.o
OBJ += lex.yy.o
OBJ += main.o

OBJ += printer/prettyDEC.o
OBJ += printer/prettyEXP.o
OBJ += printer/prettyFUNC.o
OBJ += printer/prettyLIST.o
OBJ += printer/prettySTM.o
OBJ += printer/prettyTERM.o
OBJ += printer/prettyTYPE.o

OBJ += tree/treeDEC.o
OBJ += tree/treeEXP.o
OBJ += tree/treeFUNC.o
OBJ += tree/treeLIST.o
OBJ += tree/treeSTM.o
OBJ += tree/treeTERM.o
OBJ += tree/treeTYPE.o

OBJ += typeCheck/typecheckDEC.o
OBJ += typeCheck/typecheckEXP.o
OBJ += typeCheck/typecheckFUNC.o
OBJ += typeCheck/typecheckLIST.o
OBJ += typeCheck/typecheckSTM.o
OBJ += typeCheck/typecheckTERM.o
OBJ += typeCheck/typecheckTYPE.o


OBJ += sources/symbol.o
OBJ += sources/memory.o


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
