#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include "selectRandomData.h"
#include "eatLine.h"
extern int tamanho;

int *selectRandomData()
{
  char c, file_name[255];
  int number = 0;
  FILE *file;

  printf("\nSelecione o arquivo que deseja usar no algoritmo: ");
  eatLine(stdin);
  scanf("%[^\n]%*c", &file_name);

  // Leitura do arquivo
  file = fopen(file_name, "r");

  if (file == NULL)
  {
    perror("Erro ao tentar abrir o arquivo.\n");
    return 0;
  }

  // Criando um vetor com o tamanho do arquivo
  for (c = getc(file); c != EOF; c = getc(file))
    if (c == '\n')
      tamanho = tamanho + 1;

  int vetor[tamanho];

  // Adicionando os números ao vetor
  fseek(file, 0, SEEK_SET);

  for (int i = 0; i < tamanho; i++)
  {
    fscanf(file, "%d", &number);
    vetor[i] = number;
  }

  fclose(file);

  // Cópia do vetor para retornar na função
  int *copy = malloc(sizeof(int) * tamanho);
  memcpy(copy, vetor, tamanho * sizeof(int));

  return copy;
}