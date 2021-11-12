#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include "selectFolderData.h"
#include "execAll.h"

extern int tamanho;

int selectFolderData(char* basePath)
{
  char path[1000];
  DIR *FD = opendir(basePath);
  struct dirent *in_file;
  FILE *entry_file;

  if (NULL == FD)
  {
    fprintf(stderr, "Erro ao tentar abrir a pasta. - %s\n", strerror(errno));

    return 1;
  }
  while ((in_file = readdir(FD)) != NULL)
  {
    struct stat st;

    if (!strcmp(in_file->d_name, "."))
      continue;
    if (!strcmp(in_file->d_name, ".."))
      continue;

    if (fstatat(dirfd(FD), in_file->d_name, &st, 0) < 0)
    {
        perror(in_file->d_name);
        continue;
    }

    strcpy(path, basePath);
    strcat(path, "/");
    strcat(path, in_file->d_name);
    entry_file = fopen(path, "r");

    if (!(S_ISDIR(st.st_mode))) {
      char c;
      int number = 0;
    
      printf("\nExecutando arquivo: %s\n", path);

      if (entry_file == NULL)
      {
        return 1;
      }

      for (c = getc(entry_file); c != EOF; c = getc(entry_file))
        if (c == '\n')
          tamanho = tamanho + 1;

      int vetor[tamanho];

      fseek(entry_file, 0, SEEK_SET);

      for (int i = 0; i < tamanho; i++)
      {
        fscanf(entry_file, "%d", &number);
        vetor[i] = number;
      }

      execAll(vetor);
      tamanho = 0;
      printf("\n---- Fim da execução ----\n");
    } else {
      selectFolderData(path);
    };

    fclose(entry_file);
  }
  closedir(FD);

  return 0;
}