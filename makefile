CC = gcc
CFLAGS = -Wall

all: treino mago

treino: treino.o doom.o tempo.o
	$(CC) -o treino treino.o doom.o tempo.o

mago: mago.o doom.o
	$(CC) -o mago mago.o doom.o tempo.o
	
mago.o: mago.c doom.h
	$(CC) -c $(CFLAGS) mago.c -o mago.o

treino.o: treino.c doom.h tempo.h
	$(CC) -c $(CFLAGS) treino.c -o treino.o
	
doom.o: doom.c doom.h
	$(CC) -c $(CFLAGS) doom.c -o doom.o
	
tempo.o: tempo.c tempo.h
	$(CC) -c $(CFLAGS) tempo.c -o tempo.o 
	
clean: 
	rm -f doom.o treino.o tempo.o
	
purge: clean
	rm -f treino
