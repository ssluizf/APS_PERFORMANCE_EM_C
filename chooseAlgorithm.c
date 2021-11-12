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
extern int tamanho;

void chooseAlgorithm(int *vetor)
{
  int option;
  char *algorithm;
  char showResults;
  struct timeval start, end;
  int i, num_runs = 20;

  if (tamanho >= 5e3)
  {
    num_runs = 10;
  }

  if (tamanho >= 1e4)
  {
    num_runs = 1;
  }

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
    for (i = 0; i < num_runs; i++)
    {
      quickSort(vetor, tamanho);
    }
    gettimeofday(&end, NULL);
    break;
  case 2:
    algorithm = "ShellSort";

    gettimeofday(&start, NULL);
    for (i = 0; i < num_runs; i++)
    {
      shellSort(vetor, tamanho);
    }
    gettimeofday(&end, NULL);
    break;
  case 3:
    algorithm = "MergeSort";

    gettimeofday(&start, NULL);
    for (i = 0; i < num_runs; i++)
    {
      mergeSort(vetor, 0, tamanho - 1);
    }
    gettimeofday(&end, NULL);
    break;
  }

  double time_taken = (end.tv_sec - start.tv_sec) * 1e6;
  time_taken = ((time_taken + end.tv_usec - start.tv_usec) * 1e-6) / num_runs;

  printf("\nResultados do %s:\n", algorithm);
  printf("\nSegundos: %f\n", time_taken);
  fflush(stdin);
  printf("\nFim... [Pressione ENTER para finalizar]");
  getchar();

  return;
}