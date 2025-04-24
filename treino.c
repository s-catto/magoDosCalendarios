#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "doom.h"

int main () {

    int dia, mes, ano;
    int doomsday, r;
    
    int win =0;
    int lose = 0; 
    float ratio;
    
    srand(time(NULL));
    
    ano = (rand() % 2600) + 1400;
    mes = (rand() % 12) + 1;
    dia = diaAleat(mes, ano);
    
    printf("%d / %d / %d\n", dia, mes, ano);
    
    doomsday = calcDoomsday(dia, mes, ano);
    
    scanf("%d", &r);

     while (r < 7) {
        if (r == doomsday) {
            printf(":D\n\n");
            win++;
        } else {
            printf("%d :(\n\n", doomsday);
            lose++;
        }
        
        ano = (rand() % 2600) + 1400;
        mes = (rand() % 12) + 1;
        dia = diaAleat(mes, ano);
        
        printf("%d / %d / %d\n", dia, mes, ano);
        
        doomsday = calcDoomsday(dia, mes, ano);
        
        scanf("%d", &r);   
    }
    
    if ((win+lose) > 0) {
        ratio = ((float) win / (win+lose)) * 100;
        printf(":D %d / %d :( \n %.2f%% \n", win, lose, ratio);
    }
    
    return 0;
}
