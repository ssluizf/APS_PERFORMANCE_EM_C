#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include "algorithms.h"
#include "chooseAlgorithm.h"
#include "execAll.h"
#include "selectRandomData.h"
#include "selectFolderData.h"

int tamanho = 0;

void createRandomData()
{
  // Todo: Cria dados randomicos
}

int main()
{
  while (1)
  {
    int option;
    int *vetor;

    printf("\nTeste de performance de algoritmos\n\n");
    printf("Opcoes: \n");
    printf("1 - Selecionar arquivo estatico para analise dos dados\n");
    printf("2 - Gerar vetor para analise dos dados\n\n");

    printf("Selecione uma opcao acima digitando o numero correspondente: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      vetor = selectRandomData();
    case 2:
      // To do: Testar essa opção
      break;
    case 3:
      selectFolderData("data/1k/Com Duplicidade/Aleatorio");
    }

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
  }
EndWhile:;
}