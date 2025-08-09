#include "matriz.h"
#include <stdio.h>

void floydWarshall (matrizAdj *m, double d[m->n][m->n], int p[m->n][m->n]) {
    const int N = m->n;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            d[i][j] = m->matriz[i][j];
            if (i == j) {
                p[i][j] = -1;
            } else if (m->matriz[i][j] < 10000) p[i][j] = i;
            else p[i][j] = -1;
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if((d[i][k] + d[k][j]) < d[i][j]){
                    d[i][j] = d[i][k]+d[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }


    printf("\n > MATRIZ-DE-ADJACENTES:\n\n");
    for (int i = 0; i < N; i++){
        printf(" | ");
        for (int j = 0; j < N; j++){
            printf(" %.2f ",m->matriz[i][j]);
            if(j < N - 1){
                printf("|");
            }
        }
        printf(" |\n");
    }
    printf("\n");

    printf("\n > MATRIZ-DE-DISTANCIAS_MINIMAS:\n\n");
    for (int i = 0; i < N; i++){
        printf(" | ");
        for (int j = 0; j < N; j++){
            printf(" %.2f ",d[i][j]);
            if(j < N - 1){
                printf("|");
            }
        }
        printf(" |\n");
    }
    printf("\n");


    printf("\n > MATRIZ-DE-PREDECESSORES:\n\n");
    for (int i = 0; i < N; i++){
        printf(" | ");
        for (int j = 0; j < N; j++){
            printf(" %i ",p[i][j]);
            if(j < N - 1){
                printf("|");
            }
        }
        printf(" |\n");
    }
    printf("\n");
}