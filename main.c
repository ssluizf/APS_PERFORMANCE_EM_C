#include <stdio.h>
#include <stdlib.h>
#include "algorithms.h"
#include "chooseAlgorithm.h"
#include "execAll.h"
#include "selectRandomData.h"
#include "selectFolderData.h"
#include "eatLine.h"

int tamanho = 0;

int main()
{
  while (1)
  {
    int option;
    int *vetor;
    char basePath[255];

    printf("\nTeste de performance de algoritmos\n\n");
    printf("Opcoes: \n");
    printf("1 - Selecionar arquivo estatico para analise dos dados\n");
    printf("2 - Selecionar pasta estatica para analise dos dados\n\n");

    printf("Selecione uma opcao acima digitando o numero correspondente: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      vetor = selectRandomData();

      printf("\nOpcoes: \n");
      printf("1 - Executar algoritmos individualmente\n");
      printf("2 - Executar todos os algoritmos\n");
      printf("3 - Fim\n\n");

      printf("Selecione uma opcao acima digitando o numero correspondente: ");
      scanf("%d", &option);

      switch (option)
      {
      case 1:
        chooseAlgorithm(vetor);
        goto EndWhile;
      case 2:
        execAll(vetor);
        goto EndWhile;
      case 3:
        goto EndWhile;
      }
    case 2:
      printf("\nSelecione a pasta que deseja usar no algoritmo: ");
      eatLine(stdin);
      scanf("%[^\n]%*c", &basePath);

      selectFolderData(basePath);
      goto EndWhile;
    }
  }
EndWhile:;
}