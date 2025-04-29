CC = gcc
CFLAGS = -Wall

all: treino

treino: treino.o doom.o
	$(CC) -o treino treino.o doom.o
    
treino.o: treino.c doom.h
	$(CC) -c $(CFLAGS) treino.c -o treino.o
    
doom.o: doom.c doom.h
	$(CC) -c $(CFLAGS) doom.c -o doom.o
    
clean: 
	rm -f doom.o treino.o
    
purge: clean
	rm -f treino
