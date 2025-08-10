#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "salvar.h"

int ExibirADJ();
//int ExibirDM();
//int ExibirPDC();

int ExibirMatrizes(matrizAdj *matrizAdj) {
    int escolha;

    do {
        system("cls");
        printf("\n =========== EXIBIR-MATRIZES ===========");
        printf("\n > [1] Matriz Adjacencias");
        printf("\n > [2] Matriz Distancias Minimas");
        printf("\n > [3] Matriz de Predecessores");
        printf("\n > [0] Voltar");
        printf("\n =======================================");
        printf("\n -> Opcao: "); 
        scanf("%d", &escolha);

        switch (escolha){
        case 1:
            ExibirADJ(matrizADJ);
            SalvarDadosIniciais(matrizADJ);
            return 0;
            break;
        /*case 2:
            ExibirDM();
            break;
        case 3:
            ExibirPDC();
            break;*/
        
        default:

            break;
        }

    } while (1);
}

void exibirMatrizAdj(matrizAdj *m){
    int n_cidades = m->n; // m-> n (valor de n que está na matriz m, sendo n o n_cidades);
    // Exibição - Lista de nomes de cidades
    printf("\n > LISTA-DE-CIDADES:\n"); 
    for (int i = 0; i < n_cidades; i++){
        printf(" %.02d. %s\n",i+1,m->nomes[i]);
    }

    // Exibição - Matriz de Adjacentes
    printf("\n > MATRIZ-DE-ADJACENTES:\n\n");
    for (int i = 0; i < n_cidades; i++){
        printf(" | ");
        for (int j = 0; j < n_cidades; j++){
            printf(" %7.2f ",m->matriz[i][j]);
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