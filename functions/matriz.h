#ifndef MATRIZ_H
#define MATRIZ_H //Vai definir o struct matrizAdj como uma "biblioteca", para poder ser usada em qualquer algoritmo;

typedef struct {
    int n; //Número de Cidades
    char nomes[100][255];
    double matriz[100][100];
} matrizAdj;

// Declara funções que usam a struct
int CarregarArquivo(matrizAdj *matriz);

#endif