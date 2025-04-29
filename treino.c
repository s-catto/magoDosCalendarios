#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "doom.h"

int main () {

    int dia, mes, ano;
    int doomsday, r;
    
    char go = '\n';
    
    int win = 0;
    int lose = 0; 
    float ratio; // razão acertos/tentativas
    
    srand(time(NULL));

     while (go == '\n') {
        
        ano = (rand() % 2418) + 1582;
        mes = (rand() % 12) + 1;
        dia = diaAleat(mes, ano);
        
        printf("%d / %d / %d\n", dia, mes, ano);
        
        doomsday = calcDiaSemana(dia, mes, ano);
        
        scanf("%d", &r);   
        
        if (r == doomsday) {
            printf(":D\n\n");
            win++;
        } else {
            printf("%d :(\n\n", doomsday);
            lose++;
        }
        
        printf("next->");
        
        getc(stdin);
        go = getc(stdin);
    }
    
    if ((win+lose) > 0) {
        ratio = ((float) win / (win+lose)) * 100;
        printf(":D %d / %d :( \n %.2f%% \n", win, lose, ratio);
    }
    
    return 0;
}
