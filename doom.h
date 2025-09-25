#ifndef __DOOM_H__
#define __DOOM_H__

typedef struct Doomsdays {
    int sec; // doomsday do século
    int ano; // doomsday do ano
    int dia; // dia da semana
} Doomsdays;

// recebe o ano e retorna 1 se ele eh bissexto, 0 caso contrário
int leap (int ano);

// recebe o mes e o ano e retorna um dia aleatorio desse mes nesse ano
int diaAleat (int mes, int ano);

// recebe dia mes e ano e retorna struct Doomsdays
Doomsdays* calcDiaSemana (int d, int m, int a);

#endif // __DOOM_H__
