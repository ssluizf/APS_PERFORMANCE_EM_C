#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include "execAll.h"
#include "algorithms.h"

extern int tamanho;

void execAll(int *vetor)
{
  struct timeval start, end;
  int i, num_runs = 20;
  int *copy = malloc(sizeof(int) * tamanho);

  if (tamanho >= 5e3)
  {
    num_runs = 10;
  }

  if (tamanho >= 1e4)
  {
    num_runs = 1;
  }

  memcpy(copy, vetor, tamanho * sizeof(int));
  gettimeofday(&start, NULL);
  for (i = 0; i < num_runs; i++)
  {
    quickSort(vetor, tamanho);
  }
  gettimeofday(&end, NULL);

  double quick_time_taken = (end.tv_sec - start.tv_sec) * 1e6;
  quick_time_taken = ((quick_time_taken + end.tv_usec - start.tv_usec) * 1e-6) / num_runs;

  memcpy(copy, vetor, tamanho * sizeof(int));
  gettimeofday(&start, NULL);
  for (i = 0; i < num_runs; i++)
  {
    shellSort(copy, tamanho);
  }
  gettimeofday(&end, NULL);

  double shell_time_taken = (end.tv_sec - start.tv_sec) * 1e6;
  shell_time_taken = ((shell_time_taken + end.tv_usec - start.tv_usec) * 1e-6) / num_runs;

  memcpy(copy, vetor, tamanho * sizeof(int));
  gettimeofday(&start, NULL);
  for (i = 0; i < num_runs; i++)
  {
    mergeSort(copy, 0, tamanho - 1);
  }
  gettimeofday(&end, NULL);

  double merge_time_taken = (end.tv_sec - start.tv_sec) * 1e6;
  merge_time_taken = ((merge_time_taken + end.tv_usec - start.tv_usec) * 1e-6) / num_runs;

  printf("\nResultados do QuickSort:\n");
  printf("Segundos: %f\n", quick_time_taken);
  printf("\nResultados do ShellSort:\n");
  printf("Segundos: %f\n", shell_time_taken);
  printf("\nResultados do MergeSort:\n");
  printf("Segundos: %f\n", merge_time_taken);
}
