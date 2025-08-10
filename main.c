#include <stdio.h>
#include <stdlib.h>
#include "functions/cadastro.h"
#include "functions/matriz.h"
#include "functions/floyd.h"
#include "functions/exibir.h"


int main(void) {
    int escolha;
    matrizAdj matrizADJ;

    do{
        escolha = cadastroCidades(&matrizADJ);
    }while (escolha != 1);

    int N = matrizADJ.n;
    double d[N][N];
    int p[N][N];
    
    floydWarshall(&matrizADJ,N,d,p);

    do {
        system("cls");
        printf("\n ============= ROTAS-AQUI-PERTO =============");
        printf("\n > [1] Alterar Banco de Cidades");
        printf("\n > [2] Exibir Matrizes");
        printf("\n > [3] Calcular Rota");
        printf("\n > [0] Sair do Programa");
        printf("\n ============================================\n");
        printf(" Opcao: ");
        scanf("%d",&escolha);
        switch (escolha){
        
        case 1:
            // (chamar aquivo cadastro)
            cadastroCidades(&matrizADJ);
            break;
            
        case 2:
            Exibir
            break;

        /*case 3: 
            do {
                printf("\n =========== CALCULAR-ROTA ===========");
                printf("\n > Seu Ponto de Partida: ");
                scanf("%i", &escolha);

                printf("\n > Seu Destino: ");
                scanf("%i", &escolha);

                printf("\n > [0] Cancelar");
                printf("\n ================================");
                printf("\n Opcao: ");
                scanf("%i", &escolha);
                
                } while (1);
                
                break;
                */
        case 0:
            // saindo
            return 0;
            
        default:
            printf(" ERRO: escolha fora do escopo");
            break;
        }
        
        system("cls");

    } while (1);

}