#ifndef CADASTRO_H
#define CADASTRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

#define MAXCHAR 1000

// amazenar quantidade de cidades, os nomes e a matriz para o programa executar

//void CadastroManual();

int cadastroCidades(matrizAdj *matrizAdj){
    int escolha;

    system("cls");
    printf("\n ========== CADASTRO-DE-CIDADES ==========");
    printf("\n > [1] Adicionar Manualmente");
    printf("\n > [2] Carregar Arquivo");
    printf("\n > [0] Voltar");
    printf("\n =========================================\n");
    printf(" -> Opcao: "); 
    scanf("%i",&escolha); 

    switch (escolha){
    case 1:
        escolha = cadastroManual(matrizAdj);
        break;
    case 2:
        escolha = carregarArquivo(matrizAdj);
        break;
    case 0:
        break;

    default:
        printf("\n #ERRO: sua escolha é invalida, tente novamente...\n");
        system("pause");
        break;
    }

    return escolha;
}

int cadastroManual(matrizAdj *m){

  do{
    system("cls");

    printf("- - - CADASTRO MANUAL - - -\n");
    
    printf("\n-> Quantas Cidades deseja cadastrar?: ");
    scanf("%i", &m->n);

    int n_cidades = m->n;

    for(int i = 0; i < n_cidades; i++){
      printf("\n--> Qual cidade você deseja Cadastrar?: ");
      scanf(" %[^\n]", m->nomes[i]);
    }

    printf("\n* Agora, cadastre a distancia entre os municípios.\n");
  
    for(int i = 0; i < n_cidades; i++){
      for(int j = i; j < n_cidades; j++){
        if(i==j){
          m->matriz[i][j] = 0;
          
        } else {
          printf("\n> De %s Para %s: ", m->nomes[i], m->nomes[j]);
          scanf("%lf", &m->matriz[i][j]);
          m->matriz[j][i] = m->matriz[i][j];
        }
      }
    }
    
    printf("\n");

//================================ Exbição =======================================
    
    system("cls");

    printf("\n -> ==== MATRIZ CADASTRADA COM SUCESSO !! ====\n");

    exibirMatrizAdj(m);
    
    int escolhas;
    printf("\n ==== Deseja Confirmar Valores? ====");
    printf("\n > [1] Confirmar");
    printf("\n > [2] Alterar");
    printf("\n > [0] Cancelar ");
    printf("\n ===================================");
    
    printf("\n -> Opcao: ");
    scanf("%i", &escolhas);

    system("cls");

    switch(escolhas){
      case 1:
        printf("\n* Valores Confirmados!");
        salvarMatriz();
        return 1;
        break;
      case 2:
        printf("\n* Alterar Valores!");
        break;
      case 0:
        printf("\n* Valores Cancelados!");
        return 0;
        break;
    }
      
  }while(1);
}

int carregarArquivo(matrizAdj *matrizAdj){
    FILE *arquivo;
    
    do{
        system("cls");
        char origem[500];
        printf("\n > Origem do arquivo: ");
        scanf(" %[^\n]", origem);
        
        arquivo = fopen(origem, "r");
        
        
        char linha[MAXCHAR];
        
        if (arquivo != NULL) {
            
            // Amazena - Numero de cidades
            if (fgets(linha, MAXCHAR, arquivo) != NULL) {
                matrizAdj->n = atoi(linha);
            }
                

            int n_cidades = matrizAdj->n;

            // Amazena - Nomes das cidades
            for (int i = 0; i < n_cidades; i++) {
                if (fgets(linha, MAXCHAR, arquivo) != NULL) {
                    strcpy(matrizAdj->nomes[i], linha);
                }
            }
            
            // Amazena - Matriz de adjacentes
            for (int i = 0; i < n_cidades; i++){
                fgets(linha, MAXCHAR, arquivo);
                
                char *token = strtok(linha, ";");
                
                for (int j = 0; j < n_cidades; j++){
                    matrizAdj->matriz[i][j] = atof(token);
                    token = strtok(NULL, ";");
                }
            }
//===================================================== EXIBIÇÃO =====================================================
            exibirMatrizAdj(matrizAdj);
            fclose(arquivo);
            system("pause");
            system("cls");            
            // vai executar o algoritimo?

            return 1;

        } else {
            int escolhas;
            printf("\n ====== ARQUIVO INDISPONIVEL ======");
            printf("\n > [1] Tentar novamente");
            printf("\n > [0] Cancelar");
            printf("\n =================================");
            printf("\n > Escolha: ");
            scanf("%i",&escolhas);
            
            switch(escolhas){
            case 1:
                system("cls");

                break;
                case 0:
                system("cls");
                printf("\n* Saindo...\n");
                return 1;
            }
        }
    }while (1);
}

void salvarMatriz(){
    int salvar;
    char nome_arquivo[1000];

    printf("\n-> Deseja salvar os dados em um arquivo?");
    printf("\nSim = 1");
    printf("\nNão = 0");
    printf("\nSalvar?: ");
    scanf("%i", &salvar);

    if(salvar == 1){
      printf("\n> Digite o nome do arquivo (ex.:arquivo.txt): ");
      scanf("%s", nome_arquivo);

      FILE *arquivo = NULL;

      arquivo = fopen(nome_arquivo, "w");

        if(arquivo != NULL){
          printf("** arquivo aberto com sucesso **");
        }
    } else {
      printf("Seus dados não foram salvos em arquivo.");
    }
}

#endif