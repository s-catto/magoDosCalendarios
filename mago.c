#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "doom.h"

int valido (int d, int m, int a) {
    
    // vetor de dias por mes em um ano nao-bissexto
    int diasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (a < 1553) {
        printf("Ano %d inválido.", a); 
        return 0;
    }
    
    if ((m < 1) || (m > 12)){
        printf("Mes %d inválido.", m);
        return 0;
    }
    
    if (d < 1) {
        printf("Dia %d inválido. (1)", d);
        return 0;
    }

    if ((m == 2) && leap(a)) {
        if (d > 29) {
            printf("Dia %d inválido. (2)", d);
            return 0;
        }
    } else if (d > diasMes[m-1]) {
        printf("Dia %d inválido. (3)", d);
        return 0;
    }

    return 1;
}

int main() {
    char data[64], dia[3], mes[3], ano[5];
    char* diadasemana = "Sábado";
    int d, m, a;
    Doomsdays* doom;

    printf("EU SOU O ★ MAGO DOS CALENDÀRIOS ★ !!!\n");
    printf("Me fale uma data (a partir de 1553) e eu te respondo o dia da semana!\n");
    printf("Formato: DDMMYYYY\n");
    
    scanf("%s", data);

    strncpy(dia, data, 2);
    strncpy(mes, data+2, 2);
    strncpy(ano, data+4, 4);

    dia[2] = '\0';
    mes[2] = '\0';
    ano[4] = '\0';

    d = atoi(dia);
    m = atoi(mes);
    a = atoi(ano);
    
    if (! valido(d, m, a))
        return 1;

    doom = calcDiaSemana(d, m, a);

    switch (doom->dia) {
        case 0:
            diadasemana = "Doomingo";
        break;
        case 1:
            diadasemana = "Segunda";
        break;
        case 2:
            diadasemana = "Terça";
        break;
        case 3:
            diadasemana = "Quarta";
        break;
        case 4:
            diadasemana = "Quinta";
        break;
        case 5:
            diadasemana = "Sexta";
        break;

        default:
        break;
    }

    printf("Esse dia é %s\n", diadasemana);

    return 0;
}
