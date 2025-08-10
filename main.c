#include <stdio.h>
#include <stdlib.h>
#include "functions/cadastro.h"
#include "functions/matriz.h"

//Caminho do Arquivo Cidades.txt: C:\Users\lucas\OneDrive\Documentos\Vscode\Atividades\Trabalhos\ROTAS-AQUI-PERTO\Banco_de_Dados\cidades.txt

int main(void) {
    int escolha;
    matrizAdj matrizADJ;

    do{
        escolha = cadastroCidades(&matrizADJ);
    }while (escolha != 1);

    const int N = matrizADJ.n;
    double d[N][N];
    int p[N][N];
    
    floydWarshall(&matrizADJ,d,p);

    do {
        system("cls");
        printf("\n ============= ROTAS-AQUI-PERTO =============");
        printf("\n > [1] Alterar Banco de Cidades");
        printf("\n > [2] Exibir Matrizes");
        printf("\n > [3] Calcular Rota");
        printf("\n > [0] Sair do Programa");
        printf("\n ============================================\n");
        printf(" Opcao: ");
        scanf("%i",&escolha);
        switch (escolha){
        
        case 1:
            // (chamar aquivo cadastro)
            cadastroCidades(&matrizADJ);
            break;
            
        case 2:
            do {
                printf("\n =========== EXIBIR-MATRIZES ===========");
                printf("\n > [1] Matriz de Adjacencia");
                printf("\n > [2] Matriz Distancias Minimas");
                printf("\n > [3] Matriz de Predecessores");
                printf("\n > [0] Voltar");
                printf("\n ================================");
                printf("\n Opcao: ");
                scanf("%d", &escolha);

                switch(escolha) {
                case 1:
                    system("cls");
                    exibirMatrizAdj(&matrizADJ);                    
                    break;

                case 2:
                    system("cls");
                    exibirMatrizD(N,d);                   
                    break;

                case 3:
                    system("cls");
                    exibirMatrizP(N,p);                   
                    break;

                case 0:
                    break;
                
                default:
                    printf("!! Opção Inválida !!");
                    break;
                }

            } while (escolha != 0);

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