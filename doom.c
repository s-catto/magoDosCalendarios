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

int calcDiaSemana (int d, int m, int a) {
    
    // vetor de doomsdays 
    // (estão em zero ou - para nao fazer mod com numero -)
    int doom[12] = {-4, 0, 0, -3, -5, -1, -3, -6, -2, -4, 0, -2};
    int doomsday;
    
    switch ((a / 100) % 4) {
        case 0: doomsday = 2; break;
        case 1: doomsday = 0; break;
        case 2: doomsday = 5; break;
        default:  doomsday = 3; 
    }
    
    // doomsday do ano
    doomsday = doomsday + (a % 100) + ((a % 100) / 4);
    
    
    if ((m <= 2) && (leap(a))) 
        return (doomsday + (d - doom[m-1]) + 1) % 7;   
        
    return (doomsday + (d - doom[m-1])) % 7;
}
