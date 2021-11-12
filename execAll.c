#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/time.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include "execAll.h"
#include "algorithms.h"

extern int tamanho;

void execAll(int *vetor)
{
  clock_t start, end;
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
  start = clock();
  for (i = 0; i < num_runs; i++)
  {
    quickSort(copy, tamanho);
  }
  end = clock();

  double quick_time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);

  memcpy(copy, vetor, tamanho * sizeof(int));
  start = clock();
  for (i = 0; i < num_runs; i++)
  {
    shellSort(copy, tamanho);
  }
  end = clock();
  // gettimeofday(&end, NULL);

  double shell_time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);

  memcpy(copy, vetor, tamanho * sizeof(int));
  // gettimeofday(&start, NULL);
  start = clock();
  for (i = 0; i < num_runs; i++)
  {
    mergeSort(copy, 0, tamanho - 1);
  }
  end = clock();
  // gettimeofday(&end, NULL);

  double merge_time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
  // double merge_time_taken = (end.tv_sec - start.tv_sec) * 1e6;
  // merge_time_taken = ((merge_time_taken + end.tv_usec - start.tv_usec) * 1e-6) / num_runs;


  printf("\nResultados do QuickSort:\n");
  printf("Segundos: %f\n", quick_time_taken);
  printf("\nResultados do ShellSort:\n");
  printf("Segundos: %f\n", shell_time_taken);
  printf("\nResultados do MergeSort:\n");
  printf("Segundos: %f\n", merge_time_taken);
}