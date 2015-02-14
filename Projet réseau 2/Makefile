CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS= -lm
EXEC=main
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

main: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)


liste.o: liste.c fonctions.h
affichage.o: affichage.c fonctions.h
%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
