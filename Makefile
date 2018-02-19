CC = gcc

CFLAGS  = -std=c11
CLFAGS += -Wall
CFLAGS +=	-Wextra
CFLAGS += -pedantic

DEPS  = headers/memory.h
DEPS += headers/pretty.h
DEPS += headers/tree.h

OBJ  = y.tab.o
OBJ += lex.yy.o
OBJ += main.o
OBJ += tree.o
OBJ += pretty.o
OBJ += memory.o

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
