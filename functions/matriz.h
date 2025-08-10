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

void 

#endif