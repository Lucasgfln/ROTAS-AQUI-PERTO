#ifndef MATRIZ_H
#define MATRIZ_H //Vai definir o struct matrizAdj como uma "biblioteca", para poder ser usada em qualquer algoritmo;

typedef struct {
    int n; //Número de Cidades;
    char nomes[100][255];
    double matriz[100][100];
} matrizAdj; // Matriz de Adjacência;

// Declara funções que usam a struct
int carregarArquivo(matrizAdj *matriz);

int cadastroManual(matrizAdj *m);

void salvarMatriz();

void exibirMatrizAdj(matrizAdj *m){
    int n_cidades = m->n;
    // Exibição - Lista de noomes de cidades
    printf("\n > LISTA-DE-CIDADES:\n"); 
    for (int i = 0; i < n_cidades; i++){
        printf(" %.02d. %s\n",i+1,m->nomes[i]);
    }

    // Exibição - Matriz de Adjacentes
    printf("\n > MATRIZ-DE-ADJACENTES:\n\n");
    for (int i = 0; i < n_cidades; i++){
        printf(" | ");
        for (int j = 0; j < n_cidades; j++){
            printf(" %.2f ",m->matriz[i][j]);
            if(j < n_cidades - 1){
                printf("|");
            }
        }
        printf(" |\n");
    }
    printf("\n");
}

void exibirMatrizD(int n, double matriz[n][n]){
    printf("\n > MATRIZ-DE-DISTANCIAS-MINIMAS:\n\n");
    for (int i = 0; i < n; i++){
        printf(" | ");
        for (int j = 0; j < n; j++){
            printf(" %.2f ",matriz[i][j]);
            if(j < n - 1){
                printf("|");
            }
        }
        printf(" |\n");
    }
    printf("\n");
}

void exibirMatrizP(int n, int matriz[n][n]){
    printf("\n > MATRIZ-DE-PREDECESSORES:\n\n");
    for (int i = 0; i < n; i++){
        printf(" | ");
        for (int j = 0; j < n; j++){
            printf(" %i ",matriz[i][j]);
            if(j < n - 1){
                printf("|");
            }
        }
        printf(" |\n");
    }
    printf("\n");
}

void floydWarshall (matrizAdj *m, double d[m->n][m->n], int p[m->n][m->n]);

#endif