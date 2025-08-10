#ifndef FLOYD_H
#define FLOYD_H

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
}

#endif