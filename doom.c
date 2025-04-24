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
    int dia;
    
    if (mes < 8) {
            if (mes % 2 == 0) {
                if (mes != 2) {
                    dia = (rand() % 30) + 1;
                } else {
                    if (leap(ano)) {
                        dia = (rand() % 29) + 1;
                    } else {
                        dia = (rand() % 28) + 1;    
                    }
                }
            } else {
                dia = (rand() % 31) + 1;       
            }
        } else {
            if (mes % 2 == 0) {
                dia = (rand() % 30) + 1;    
            } else {
                dia = (rand() % 31) + 1;       
            }    
        }
        
    return dia;    
}

int calcDoomsday (int d, int m, int a) {
    
    int doom[12] = {-4, 0, 0, -3, -5, -1, -3, -6, -2, -4, 0, -2};
    int doomsday;
    
    switch ((a / 100) % 4) {
        case 0: doomsday = 2; break;
        case 1: doomsday = 0; break;
        case 2: doomsday = 5; break;
        default:  doomsday = 3; 
    }
    
    doomsday = doomsday + (a % 100) + ((a % 100) / 4);
    
    
    if ((m <= 2) && (leap(a))) 
        return (doomsday + (d - doom[m-1]) + 1) % 7;   
        
    return (doomsday + (d - doom[m-1])) % 7;
}
