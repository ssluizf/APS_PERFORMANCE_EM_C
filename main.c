#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createRandomData() {
  // Todo: Cria dados randomicos
}

void selectRandomData() {
  // Todo: Seleciona dados randomicos de arquivos estaticos
}

void quickSort() {
  // Todo: Fazer um quickSort
}

void shellSort() {
  // Todo: Fazer um shellSort
}

void mergeSort() {
  // Todo: Fazer um mergeSort
}

void chooseAlgorithm() {
  int option;
  printf("\nSelecione uma algoritmo\n");
  printf("Opcoes: \n");
  printf("1 - Quick Sort\n");
  printf("2 - Shell Sort\n");
  printf("3 - Merge Sort\n");

  printf("Selecione uma opcao acima digitando o numero correspondente: ");
  scanf("%d", &option);

  switch(option) {
    case 1:
      quickSort();
      break;
    case 2:
      shellSort();
      break;
    case 3:
      mergeSort();
      break;
  }

  return;
}

int main(void) {
  while(1) {
    int option;
    printf("\nTeste de performance de algoritmos\n");
    printf("Opcoes: \n");
    printf("1 - Executar algoritmos individualmente\n");
    printf("2 - Executar todos os algoritmos\n");
    printf("3 - Fim\n");
  
    printf("Selecione uma opcao acima digitando o numero correspondente: ");
    scanf("%d", &option);
  
    switch(option) {
      case 1:
        chooseAlgorithm();
        break;
      case 2:
        quickSort();
        shellSort();
        mergeSort();
        break;
      case 3:
        goto EndWhile;
    }
  }
  EndWhile: ;
}