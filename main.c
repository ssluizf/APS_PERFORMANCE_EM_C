#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>

int tamanho = 0;

int eatLine(FILE *fp)
{
  for (;;)
  {
    int ch = getc(fp);
    if (ch == '\n' || ch < 0)
      return ch;
  }
}

void createRandomData()
{
  // Todo: Cria dados randomicos
}

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

int selectFolderData()
{
  DIR *FD;
  struct dirent *in_file;
  FILE *common_file;
  FILE *entry_file;
  char buffer[BUFSIZ];

  /* Opening common file for writing */
  // common_file = fopen(path_to_your_common_file, "w");
  // if (common_file == NULL)
  // {
  //     fprintf(stderr, "Error : Failed to open common_file - %s\n", strerror(errno));

  //     return 1;
  // }

  /* Scanning the in directory */
  if (NULL == (FD = opendir(argv[1])))
  {
    fprintf(stderr, "Erro ao tentar abrir a pasta. - %s\n", strerror(errno));
    // fclose(common_file);

    return 1;
  }
  while ((in_file = readdir(FD)))
  {
    /* On linux/Unix we don't want current and parent directories
         * On windows machine too, thanks Greg Hewgill
         */
    if (!strcmp(in_file->d_name, "."))
      continue;
    if (!strcmp(in_file->d_name, ".."))
      continue;
    /* Open directory entry file for common operation */
    /* TODO : change permissions to meet your need! */
    entry_file = fopen(in_file->d_name, "r");
    if (entry_file == NULL)
    {
      fprintf(stderr, "Erro ao tentar abrir o arquivo. - %s\n", strerror(errno));
      // fclose(common_file);

      return 1;
    }

    for (c = getc(file); c != EOF; c = getc(file))
      if (c == '\n')
        tamanho = tamanho + 1;

    int vetor[tamanho];

    fseek(file, 0, SEEK_SET);

    /* Doing some struf with entry_file : */
    /* For example use fgets */
    while (fgets(vetor, tamanho, entry_file) != NULL)
    {
      puts(vetor);
    }

    /* When you finish with the file, close it */
    fclose(entry_file);
  }

  /* Don't forget to close common file before leaving */
  // fclose(common_file);

  int *copy = malloc(sizeof(int) * tamanho);
  memcpy(copy, vetor, tamanho * sizeof(int));

  return copy;
}

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
  fflush(stdin);
  printf("\nFim... [Pressione ENTER para finalizar]");
  getchar();
}

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

int main(void)
{
  while (1)
  {
    int option;
    int *vetor;

    printf("\nTeste de performance de algoritmos\n\n");
    printf("Opcoes: \n");
    printf("1 - Selecionar arquivo estatico para analise dos dados\n");
    printf("2 - Gerar vetor para analise dos dados\n\n");

    printf("Selecione uma opcao acima digitando o numero correspondente: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      vetor = selectFolderData();
    case 2:
      // To do: Testar essa opção
      break;
    }

    printf("\nOpcoes: \n");
    printf("1 - Executar algoritmos individualmente\n");
    printf("2 - Executar todos os algoritmos\n");
    printf("3 - Fim\n\n");

    printf("Selecione uma opcao acima digitando o numero correspondente: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      chooseAlgorithm(vetor);
      goto EndWhile;
    case 2:
      execAll(vetor);
      goto EndWhile;
    case 3:
      goto EndWhile;
    }
  }
EndWhile:;
}