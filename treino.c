#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "doom.h"
#include "tempo.h"

void leLog (FILE* log, int* tenta, int* win, float* somaTempo, float* minTempo) {
    char eba[4];
    
    if (!fgets(eba, 4, log)) {
        *win = 0;
        *tenta = 0;
        *somaTempo = 0;
        *minTempo = 300000; // 5min
    } else {
        fscanf(log, "%d %d %f %f", tenta, win, somaTempo, minTempo);
    }
    
    return;
}

void logaLog (FILE* log, int tenta, int win, float somaTempo, float minTempo) {
    fprintf(log, "eba %d %d %.2f %.2f", tenta, win, somaTempo, minTempo); 
    
    return;  
}

int main () {

    int dia, mes, ano;
    int doomsday, r;
    
    int win = 0;
    int tenta = 0;
    float ratio; // razão acertos/tentativas
    float tempo;
    float somaTempo = 0;
    float minTempo = 300000; // 5min
    
    int winAT, tentaAT;
    float somaTempoAT, minTempoAT, ratioAT;
    
    int tut;
    printf(" bora?\n");
    printf("0 = bora\n1 = como usar\n");
    
    scanf("%d", &tut);
    
    if (tut) {
        if (tut != 1) {
            printf("eu falei ZERO OU UM seu bobalhão >:(\n");
            printf("toma teu tutorial pq vc claramente não sabe \n");
            printf("oq vc tá fazendo aqui\n\n");
        }
        
        printf("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
        
        printf("\nSeja bem vindo, pequeno gafanhoto!\n\n");
        printf("Uma data irá aparecer, calcule o dia da semana e responda.\n");
        printf("Como ensinado no manual:\n\n");
        printf("0 = DOM\n");
        printf("1 = SEG 2 = TER\n");
        printf("3 = QUA 4 = QUI\n");
        printf("5 = SEX 6 = SAB\n\n");
        
        printf("-----------------------------------------------------------\n");
        
        printf("Ao aparecer \"next->\":\n");
        printf("> pressione ENTER caso queira continuar\n");
        printf("> ou pressione qualquer coisa e ENTER para finalizar.\n\n");
        
        printf("★★★★★★★★★★★★★★★★★★★★★★★ bom treino! ★★★★★★★★★★★★★★★★★★★★★★★\n");
        
        printf("\n agora bora?\n");
        printf("0 = bora\n1 = não bora\n");
        scanf("%d", &tut);
        
        if (tut) {
            printf("então que se lasque >:(\n");
            return 0;
        }
    }
    
    printf("\n");
    
    char go = '\n';
    
    FILE* log = fopen("log", "r");
    if (!log) {
        perror("Erro ao acessar log\n");
        return 1;
    } 
    leLog(log, &tentaAT, &winAT, &somaTempoAT, &minTempoAT);
    fclose(log);

    srand(time(NULL));
    
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
                if (tempo < minTempoAT) {
                    printf("RAPIDASSO!!!");
                } else {
                    printf("RAPIDAO!");
                }
            }
            printf("\n\n");
            win++;
        } else {
            printf("%d :(\n\n", doomsday);
        }
        tenta++;
        
        printf("next->");
        
        getc(stdin);
        go = getc(stdin);
    }
    
    tentaAT += tenta;
    winAT += win;
    somaTempoAT += somaTempo;
    
    if (tenta > 0) {
        ratio = ((float) win / tenta) * 100;
        ratioAT = ((float) winAT / tentaAT) * 100;
        printf("===========================================================\n");
        
        printf(":D %5d / %5d :( | A.T.: :D %5d / %5d :(", 
               win, tenta-win, winAT, tentaAT-winAT);
        printf("\n:D %6.2f%%          | A.T.: %6.2f%%", 
               ratio, ratioAT);
               
        printf("\n\nTempo Medio : %5.2f | A.T.: %5.2f", 
               somaTempo/(win*1000), somaTempoAT/(winAT*1000));
        printf("\nMelhor Tempo: %5.2f | ", minTempo/1000);
        if (minTempo < minTempoAT) {
            minTempoAT = minTempo;
            printf("A.T.: %5.2f RAPIDASSO!!!\n", minTempoAT/1000);
        } else {
            printf("A.T.: %5.2f\n", minTempoAT/1000);
        }
    }
    
    log = fopen("log", "w");
    if (!log) {
        perror("Erro ao acessar log\n");
        return 1;
    } 
    logaLog(log, tentaAT, winAT, somaTempoAT, minTempoAT);
    fclose(log);
    
    return 0;
}
