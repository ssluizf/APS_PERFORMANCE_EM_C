#include <stdio.h>
#include <stdlib.h>
#include "algorithms.h"

void quickSort(int *v, int tam)
{
  int j = tam, k;
  if (tam <= 1)
    return;
  else
  {
    int x = v[0];
    int a = 1;
    int b = tam - 1;
    do
    {
      while ((a < tam) && (v[a] <= x))
        a++;
      while (v[b] > x)
        b--;
      if (a < b)
      {
        int temp = v[a];
        v[a] = v[b];
        v[b] = temp;
        a++;
        b--;
      }
    } while (a <= b);
    // troca pivo
    v[0] = v[b];
    v[b] = x;
    // ordena sub-vetires restantes
    quickSort(v, b);
    quickSort(&v[a], tam - a);
  }
}

void shellSort(int v[], int tam)
{
  // Rearrange elements at each n/2, n/4, n/8, ... intervals
  for (int interval = tam / 2; interval > 0; interval /= 2)
  {
    for (int i = interval; i < tam; i += 1)
    {
      int temp = v[i];
      int j;
      for (j = i; j >= interval && v[j - interval] > temp; j -= interval)
      {
        v[j] = v[j - interval];
      }
      v[j] = temp;
    }
  }
}

void mergeSort(int *v, int inicio, int fim)
{
  int i, j, k, meio, *t, z;
  if (inicio == fim)
    return;
  // ordenacao recursiva das duas metades
  meio = (inicio + fim) / 2;
  mergeSort(v, inicio, meio);
  mergeSort(v, meio + 1, fim);
  // intercalacao no vetor temporario t
  i = inicio;
  j = meio + 1;
  k = 0;
  t = (int *)malloc(sizeof(int) * (fim - inicio + 1));
  while (i < meio + 1 || j < fim + 1)
  {
    if (i == meio + 1)
    { // i passou do final da primeira metade, pegar v[j]
      t[k] = v[j];
      j++;
      k++;
    }
    else if (j == fim + 1)
    { // j passou do final da segunda metade, pegar v[i]
      t[k] = v[i];
      i++;
      k++;
    }
    else if (v[i] < v[j])
    { // v[i] < v[j], pegar v[i]
      t[k] = v[i];
      i++;
      k++;
    }
    else
    {
      t[k] = v[j];
      j++;
      k++;
    }
  }
  // copia vetor intercalado para o vetor original
  for (i = inicio; i <= fim; i++)
    v[i] = t[i - inicio];
  free(t);
}