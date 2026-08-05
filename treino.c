#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "doom.h"
#include "tempo.h"

// funções de log ==============================================================

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

// funções de print ============================================================

void printTut () {
    printf("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
    
    printf("\nSeja bem vindo, pequeno gafanhoto!\n\n");
    
    printf("CASO ESCOLHA MODO MESTRE:\n");
    printf("Uma data irá aparecer, calcule o dia da semana e responda.\n\n");
    
    printf("CASO ESCOLHA MODO GAFANHOTO:\n");
    printf("- Uma data irá aparecer.\n");
    printf("- Calcule e responda a doomsday do século até acertar.\n");
    printf("- Com base nela, calcule e responda a doomsday do ano até acertar.\n");
    printf("- Enfim tente calcular o dia da semana e responda.\n");
    printf("obs.: nesse modo, também aparecem diversas colinhas para te ajudar\n\n");
    
    
    printf("-----------------------------------------------------------\n");
    
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
    
    return;
} 

// atualiza AT e printa stats
void upPrintStats (int tenta, int* tentaAT, int win, int* winAT, float* ratioAT, 
                 float minTempo, float minTempoAT, 
                 float somaTempo, float* somaTempoAT) {
    
    *tentaAT += tenta;
    *winAT += win;
    *somaTempoAT += somaTempo;
    
    if (tenta > 0 && *tentaAT > 0) {
        float ratio = ((float) win / tenta) * 100;
        *ratioAT = ((float) *winAT / *tentaAT) * 100;
        printf("===========================================================\n");
        
        printf(":D %5d / %5d :( | A.T.: :D %5d / %5d :(", 
               win, tenta-win, *winAT, *tentaAT-*winAT);
        printf("\n:D %6.2f%%          | A.T.: %6.2f%%", 
               ratio, *ratioAT);
               
        printf("\n\nTempo Medio : %5.2f | A.T.: %5.2f", 
               somaTempo/(win*1000), *somaTempoAT/(*winAT*1000));
        printf("\nMelhor Tempo: %5.2f | ", minTempo/1000);
        if (minTempo < minTempoAT) {
            printf("A.T.: %5.2f RAPIDASSO!!!\n", minTempoAT/1000);
        } else {
            printf("A.T.: %5.2f\n", minTempoAT/1000);
        }
    }
    
    return;
}

void modoGafanhoto (int dia, int mes, int ano, Doomsdays* doomsdays) {
    int s = -1;
    int a = -1;
    
    printf("\n%% 4 = 0 -> 2\n");
    printf("    = 1 -> 0\n");
    printf("    = 2 -> 5\n");
    printf("    = 3 -> 3\n\n");
    
    printf("-> %d  %d\n\n", ano/100, ano % 100);
    while (s != doomsdays->sec) {
        if (s >= 0) {
            printf("Tente novamente!!!\n");
        } 
        
        printf("Qual é a dooomsday do século? ");
        
        scanf("%d", &s);
    }
    
    printf("\n!!!BOA!!! --> %d\n\n", s);
    printf("-----------------------------------------------------------\n");
    
    
    printf("+0 -> 28  56  84\n");
    printf("+1 -> 12      96\n");
    printf("+2 -> 24\n");
    printf("+3 -> 36\n");
    printf("+4 -> 48\n");
    printf("+5 -> 60\n");
    printf("+6 -> 72\n");
    
    printf("\n +1 ano normal   == +1\n");
    printf(" +1 ano bissexto == +2\n");
    printf("!!!CUIDADO COM ANOS BISSEXTOS!!! (múltiplos de 4)\n\n");
    
    printf("Século: %d", s);
    printf("\n%d  %d <-\n\n", ano/100, ano % 100);
    
    while (a != doomsdays->ano) {
        if (a >= 0) {
            printf("Tente novamente!!!\n");
        } 
        
        printf("Qual é a dooomsday do ano? ");
        
        scanf("%d", &a);
    }
    
    printf("\n!!!BOA!!! --> %d\n\n", doomsdays->ano);
    printf("-----------------------------------------------------------\n");
    
    
    printf("DOOMSDAYS:\n\n");
    printf("03/01             bi-> 04/01");
    if (mes == 1) printf(" ★ ");
    printf("\n");
    printf("28/02             bi-> 29/02\n");
    if (mes == 2) printf(" ★ ");
    printf("\n");
    printf("14/03\n");
    if (mes == 3) printf(" ★ ");
    printf("\n");
    printf("04/04    09/05");
    if ((mes == 4) || (mes == 5)) printf(" ★ ");
    printf("\n");
    printf("06/06    11/07");
    if ((mes == 6) || (mes == 7)) printf(" ★ ");
    printf("\n");
    printf("08/08    05/09");
    if ((mes == 8) || (mes == 9)) printf(" ★ ");
    printf("\n");
    printf("10/10    07/11");
    if ((mes == 10) || (mes == 11)) printf(" ★ ");
    printf("\n");
    printf("12/12");
    if (mes == 12) printf(" ★ ");
    printf("\n");
    
    printf("\nAno: %d\n", a); 
    printf("-->  %d / %d  <-- \n\n", dia, mes);
    printf("MANDA A VER!!!\n");
    printf("Qual é o dia da semana???");
    
    return;
}

// treino ======================================================================

void treino (int tut, int* tenta, int* win, 
             float* minTempo, float* minTempoAT, float* somaTempo) {   
    int dia, mes, ano;
    int r;
    Doomsdays* doomsdays;
    
    float tempo;
     
    char go = '\n';    
    while (go == '\n') {
            
        // aleatoriza data
        ano = (rand() % 2417) + 1583;
        mes = (rand() % 12) + 1;
        dia = diaAleat(mes, ano);
        
        printf("%d / %d / %d\n", dia, mes, ano);
        
        tempo = timestamp(); // início do tempo
        
        doomsdays = calcDiaSemana(dia, mes, ano);
        
        if (tut) {
            modoGafanhoto(dia, mes, ano, doomsdays);
        }
        
        scanf("%d", &r); 
        
        tempo = timestamp() - tempo; // fim do tempo
        *somaTempo = *somaTempo + tempo;
        
        // se a resposta está certa
        if (r == doomsdays->dia) {
            
            printf(":D\n");
            printf("%.2f ", tempo / 1000); // printa tempo
            
            if (tempo < *minTempo) { 
            
                *minTempo = tempo;
             
                if (tempo < *minTempoAT) {
                    *minTempoAT = tempo;
                    printf("RAPIDASSO!!!"); // se bateu recorde all time
                } else {
                    printf("RAPIDAO!"); // se bateu recorde dessa jogada
                }
            
            }
            printf("\n\n");
            (*win)++;
        
        // se a resposta está errada
        } else {
            printf("%d :(\n\n", doomsdays->dia); 
        }
        (*tenta)++;
        
        printf("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
        
        printf("next->");
        
        getc(stdin);
        go = getc(stdin);

    }
    
    return;
}

int main () {
    // início ==============================
    
    int tut;
    printf(" bora?\n");
    printf("0 = bora\n1 = como usar\n2 = modo pequeno gafanhoto\n");
    
    scanf("%d", &tut);
    
    if (tut) {
        if ((tut != 1) && (tut != 2)) {
            printf("eu falei ZERO OU UM OU 2 seu bobalhão >:(\n");
            printf("toma teu tutorial pq vc mal sabe ler \n");
            printf("que dirá controlar magias poderosas\n\n");
        }
        
        printTut(&tut);
        
        printf("\n agora bora?\n");
        printf("0 = modo mestre\n1 = modo pequeno gafanhoto\n2 = não bora\n");
        scanf("%d", &tut);
        
        if (tut > 1) {
            printf("então que se lasque >:(\n");
            return 0;
        }
    }
    
    printf("\n");
    
    // le log ==============================
    
    int winAT, tentaAT;
    float somaTempoAT, minTempoAT, ratioAT;
    
    FILE* log = fopen("log", "r");
    if (!log) {
        perror("Erro ao acessar log\n");
        return 1;
    } 
    leLog(log, &tentaAT, &winAT, &somaTempoAT, &minTempoAT);
    fclose(log);

    srand(time(NULL));
    
    // treino =============================
    
    int win = 0;
    int tenta = 0;
    float somaTempo = 0;
    float minTempo = 3000000; // 50min
    
    treino(tut, &tenta, &win, &minTempo, &minTempoAT, &somaTempo);
    
    upPrintStats(tenta, &tentaAT, win, &winAT, &ratioAT, 
                 minTempo, minTempoAT, 
                 somaTempo, &somaTempoAT);
    
    log = fopen("log", "w");
    if (!log) {
        perror("Erro ao acessar log\n");
        return 1;
    } 
    logaLog(log, tentaAT, winAT, somaTempoAT, minTempoAT);
    fclose(log);
    
    return 0;
}
