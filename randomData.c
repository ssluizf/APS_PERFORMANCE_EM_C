#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createRandomData() {
  // Todo: Cria dados randomicos
}

int * selectRandomData() {
  char c, file_name[255];
  int number = 0;
  int lengthOfFile = 0;
  FILE *file;

  printf("Selecione o arquivo que deseja usar no algoritmo:\n");
  gets(file_name);

  file = fopen(file_name, "r");

  if (file == NULL)
  {
    perror("Erro ao tentar abrir o arquivo.\n");
    return;
  }
  
  for (c = getc(file); c != EOF; c = getc(file))
    if (c == '\n')
        lengthOfFile = lengthOfFile + 1;

  int vetor[lengthOfFile];

  fseek(file, 0, SEEK_SET);

  for (int i = 0; i < lengthOfFile; i++) {
    fscanf(file, "%d", &number);
    vetor[i] = number;
  }

  fclose(file);

  int * copy = malloc(sizeof(int) * lengthOfFile);
  memcpy(copy, vetor, lengthOfFile * sizeof(int));

  return copy;
}