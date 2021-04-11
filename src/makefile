### 
## Makefile skeleton
## INFO0030: Projet 1
## 
### 

## Variables

# Tools & flags
CC=gcc
CFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes
LD=gcc
LDFLAGS=
PACKAGE=`pkg-config --cflags --libs gtk+-2.0`
LIBS=`pkg-config --libs gtk+-2.0`

# Files
EXEC=GUI
MODULES=main.c
OBJECTS=main.o

## Rules

all: $(EXEC)

GUI: $(OBJECTS)
	$(LD) -o $(EXEC) $(OBJECTS) $(LDFLAGS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

clean:
	rm -f *.o $(EXEC) *~

