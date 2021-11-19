#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "algorithms.h"
#include "chooseAlgorithm.h"
extern int tamanho;

void chooseAlgorithm(int *vetor)
{
  int option;
  char *algorithm;
  struct timeval start, end;

  printf("\nSelecione um algoritmo\n");
  printf("\nOpcoes: \n");
  printf("1 - Quick Sort\n");
  printf("2 - Shell Sort\n");
  printf("3 - Merge Sort\n");

  printf("\nSelecione uma opcao acima digitando o numero correspondente: ");
  scanf("%d", &option);

  switch (option)
  {
  case 1:
    algorithm = "QuickSort";

    gettimeofday(&start, NULL);
    quickSort(vetor, tamanho);
    gettimeofday(&end, NULL);
    break;
  case 2:
    algorithm = "ShellSort";

    gettimeofday(&start, NULL);
    shellSort(vetor, tamanho);
    gettimeofday(&end, NULL);
    break;
  case 3:
    algorithm = "MergeSort";

    gettimeofday(&start, NULL);
    mergeSort(vetor, 0, tamanho - 1);
    gettimeofday(&end, NULL);
    break;
  }

  double time_taken = (end.tv_sec - start.tv_sec) * 1e6;
  time_taken = ((time_taken + end.tv_usec - start.tv_usec) * 1e-6);

  printf("\nResultados do %s:\n", algorithm);
  printf("\nSegundos: %f\n", time_taken);
  fflush(stdin);
  printf("\nFim... [Pressione ENTER para finalizar]");
  getchar();

  return;
}