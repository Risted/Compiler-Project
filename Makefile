CC	  = gcc #Compiler

CFLAGS   += -I headers#
CFLAGS   += -std=c11#
CFLAGS   += -Wall#
CFLAGS   += -Wextra#
CFLAGS   += -pedantic#

# Main
SOURCES   = sources/main.c#

# Functions
SOURCES  += sources/memory.c#
SOURCES  += sources/symbol.c#

OOBJECTS  = $(SOURCES:.c=.o)#Object files
OBJECTS = $(OOBJECTS:sources/=objects/)

EXECUTEABLE= a.out #Output name

all: $(SOURCES) $(EXECUTEABLE)

$(EXECUTEABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $(EXECUTEABLE)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:  ; rm $(OBJECTS) $(EXECUTEABLE)

run:	; ./$(EXECUTEABLE)
