#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include "selectFolderData.h"
#include "execAll.h"

extern int tamanho;

int selectFolderData(char* basePath)
{
  char path[1000];
  DIR *FD;
  struct dirent *in_file;
  FILE *entry_file;
  char c;

  if (NULL == (FD = opendir(basePath)))
  {
    fprintf(stderr, "Erro ao tentar abrir a pasta. - %s\n", strerror(errno));

    return 1;
  }
  while ((in_file = readdir(FD)))
  {
    if (!strcmp(in_file->d_name, "."))
      continue;
    if (!strcmp(in_file->d_name, ".."))
      continue;

    strcpy(path, basePath);
    strcat(path, "/");
    strcat(path, in_file->d_name);
    
    printf("\nExecutando arquivo: %s\n", path);
    entry_file = fopen(path, "r");
    if (entry_file == NULL)
    {
      return 1;
    }

    for (c = getc(entry_file); c != EOF; c = getc(entry_file))
      if (c == '\n')
        tamanho = tamanho + 1;

    int vetor[tamanho];

    fseek(entry_file, 0, SEEK_SET);

    execAll(vetor);
    printf("\n---- Fim da execução ----\n");

    tamanho = 0;
    fclose(entry_file);
  }

  return 0;
}