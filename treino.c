#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "doom.h"
#include "tempo.h"

int main () {

    int dia, mes, ano;
    int doomsday, r;
    
    char go = '\n';
    
    int win = 0;
    int lose = 0; 
    float ratio; // razão acertos/tentativas
    float tempo, somaTempo, minTempo;
    
    srand(time(NULL));
    somaTempo = 0;
    minTempo = 300000; // 5min

    while (go == '\n') {
        
        ano = (rand() % 2418) + 1582;
        mes = (rand() % 12) + 1;
        dia = diaAleat(mes, ano);
        
        printf("%d / %d / %d\n", dia, mes, ano);
        
        tempo = timestamp();
        
        doomsday = calcDiaSemana(dia, mes, ano);
        
        scanf("%d", &r); 
        
        tempo = timestamp() - tempo; 
        somaTempo = somaTempo + tempo;
        
        if (r == doomsday) {
            printf(":D\n");
            printf("%.2f ", tempo / 1000);
            if (tempo < minTempo) { 
                minTempo = tempo;
                printf("RAPIDASSO!!!");
            }
            printf("\n\n");
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
        printf("===========================================================\n");
        printf(":D %d / %d :( \n:D %.2f%% \n\n", win, lose, ratio);
        printf("Tempo Medio : %.2f \nMelhor Tempo: %.2f \n", 
                somaTempo/(win*1000), minTempo/1000);
    }
    
    return 0;
}
