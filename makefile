CC = gcc
CFLAGS = -Wall

all: treino

treino: treino.o
	$(CC) -o treino treino.o doom.o
    
treino.o: treino.c 
	$(CC) -c $(CFLAGS) treino.c -i doom.h -o treino.o
    
doom.o: 
	$(CC) -c $(CFLAGS) doom.c -i doom.h -o doom.o
    
clean: 
	rm -f doom.o treino.o
    
purge: clean
	rm -f treino
