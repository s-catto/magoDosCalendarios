#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "doom.h"

int leap (int ano) {
    if (ano % 400 == 0) {
        return 1;
    } else if (ano % 100 == 0) {
        return 0;
    } else if (ano % 4 == 0) {
        return 1;
    }
    
    return 0;
}

int diaAleat (int mes, int ano) {
    // vetor de dias por mes em um ano nao-bissexto
    int diasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (mes == 2 && leap(ano)) 
        return rand() % 29 + 1;
        
    return rand() % diasMes[mes - 1] + 1;    
}

Doomsdays* calcDiaSemana (int d, int m, int a) {
    
    // vetor de doomsdays 
    // (estão em zero ou - para nao fazer mod com numero -)
    int doom[12] = {-4, 0, 0, -3, -5, -1, -3, -6, -2, -4, 0, -2};
    Doomsdays* doomsdays = malloc(sizeof(Doomsdays));
    
    switch ((a / 100) % 4) {
        case 0: doomsdays->sec = 2; break;
        case 1: doomsdays->sec = 0; break;
        case 2: doomsdays->sec = 5; break;
        default:  doomsdays->sec = 3; 
    }
    
    // doomsday do ano
    doomsdays->ano = doomsdays->sec + (a % 100) + ((a % 100) / 4);
    
    
    if ((m <= 2) && (leap(a))) {
        doomsdays->dia = (doomsdays->ano + (d - doom[m-1]) - 1) % 7;
        doomsdays->ano = doomsdays->ano % 7;
        // printf("sec: %d, ano: %d, dia: %d \n", doomsdays->sec, doomsdays->ano, doomsdays->dia);
        return doomsdays;
    }   
        
    doomsdays->dia = (doomsdays->ano + (d - doom[m-1])) % 7;
    doomsdays->ano = doomsdays->ano % 7;
    // printf("sec: %d, ano: %d, dia: %d \n", doomsdays->sec, doomsdays->ano, doomsdays->dia);    

    return doomsdays;
}
