CC	=	gcc
CFLAGS	+=	-std=c11
CFLAGS	+=	-Wall
CFLAGS	+=	-Wextra
CFLAGS	+=	-pedantic

SOURCES	+= main.c
SOURCES	+= sources/symbol.c

default: main.c
	$(CC) -o main $(SOURCES) $(CFLAGS)

run:
	./main

clean:
	rm -f main.o main
