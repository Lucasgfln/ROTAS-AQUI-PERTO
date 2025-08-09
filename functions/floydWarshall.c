#include "matriz.h"
#include <stdio.h>

int main (void) {
    double a[4][4] = {
        {   0,    3,  10000,    7},
        {   8,    0,    2, 10000},
        {   5,  10000,    0,    1},
        {   2,  10000,  10000,    0}
    };

    double d[4][4];
    int p[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            d[i][j] = a[i][j];
            if (i == j) p[i][j] = -1;
            else if (a[i][j] < 10000) p[i][j] = i;
            else p[i][j] = -1;
        }
    }

    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if((d[i][k] + d[k][j]) < d[i][j]){
                    d[i][j] = d[i][k]+d[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }


    printf("\n > MATRIZ-DE-ADJACENTES:\n\n");
    for (int i = 0; i < 4; i++){
        printf(" | ");
        for (int j = 0; j < 4; j++){
            printf(" %.2f ",a[i][j]);
            if(j < 4 - 1){
                printf("|");
            }
        }
        printf(" |\n");
    }
    printf("\n");

    printf("\n > MATRIZ-DE-DISTANCIAS_MINIMAS:\n\n");
    for (int i = 0; i < 4; i++){
        printf(" | ");
        for (int j = 0; j < 4; j++){
            printf(" %.2f ",d[i][j]);
            if(j < 4 - 1){
                printf("|");
            }
        }
        printf(" |\n");
    }
    printf("\n");


    printf("\n > MATRIZ-DE-PREDECESSORES:\n\n");
    for (int i = 0; i < 4; i++){
        printf(" | ");
        for (int j = 0; j < 4; j++){
            printf(" %i ",p[i][j]);
            if(j < 4 - 1){
                printf("|");
            }
        }
        printf(" |\n");
    }
    printf("\n");
}