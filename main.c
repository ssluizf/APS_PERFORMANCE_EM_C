#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tamanho = 0;

void createRandomData() {
  // Todo: Cria dados randomicos
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int * selectRandomData() {
  char c, file_name[255];
  int number = 0;
  FILE *file;

  printf("Selecione o arquivo que deseja usar no algoritmo:\n");
  gets(file_name);

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

  for (int i = 0; i < tamanho; i++) {
    fscanf(file, "%d", &number);
    vetor[i] = number;
  }

  fclose(file);

  // Cópia do vetor para retornar na função
  int * copy = malloc(sizeof(int) * tamanho);
  memcpy(copy, vetor, tamanho * sizeof(int));

  return copy;
}

void quickSort(int* v, int tam) {
  int j = tam, k;
  if (tam <= 1)
    return;
  else {
    int x = v[0];
    int a = 1;
    int b = tam - 1;
    do {
      while ((a < tam) && (v[a] <= x))
        a++;
      while (v[b] > x)
        b--;
      if (a < b) {
        int temp = v[a];
        v[a] = v[b];
        v[b] = temp;
        a++;
        b--;
      }
      for (k = 0; k < j; k++)
        printf("%d ", v[k]);
      printf("\n");
    } while (a <= b);
    // troca pivo
    v[0] = v[b];
    v[b] = x;
    // ordena sub-vetires restantes
    quickSort(v, b);
    quickSort(&v[a], tam - a);
    for (k = 0; k < j; k++)
      printf("%d ", v[k]);
    printf("\n");
  }
}

void shellSort(int vetor[], int tamanho) {
  // Rearrange elements at each n/2, n/4, n/8, ... intervals
  for (int interval = tamanho / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < tamanho; i += 1) {
      int temp = vetor[i];
      int j;
      for (j = i; j >= interval && vetor[j - interval] > temp; j -= interval) {
        vetor[j] = vetor[j - interval];
      }
      vetor[j] = temp;
    }
  }
}

void mergeSort(int* v, int inicio, int fim) {
  int i, j, k, meio, * t, z;
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
  t = (int*)malloc(sizeof(int) * (fim - inicio + 1));
  while (i < meio + 1 || j < fim + 1) {
    if (i == meio + 1) { // i passou do final da primeira metade, pegar v[j]
      t[k] = v[j];
      j++; k++;
    }
    else if (j == fim + 1) { // j passou do final da segunda metade, pegar v[i]
      t[k] = v[i];
      i++; k++;
    }
    else if (v[i] < v[j]) { // v[i] < v[j], pegar v[i]
      t[k] = v[i];
      i++; k++;
    }
    else {
      t[k] = v[j];
      j++; k++;
    }
    for (z = 0; z < tamanho; z++)
      printf("%d ", v[z]);
    printf("\n");
  }
  // copia vetor intercalado para o vetor original
  for (i = inicio; i <= fim; i++)
    v[i] = t[i - inicio];
  for (z = 0; z < tamanho; z++)
    printf("%d ", v[z]);
  printf("\n");
  free(t);
}

void chooseAlgorithm(int* vetor) {
  int option;
  printf("\nSelecione uma algoritmo\n");
  printf("Opcoes: \n");
  printf("1 - Quick Sort\n");
  printf("2 - Shell Sort\n");
  printf("3 - Merge Sort\n");

  printf("Selecione uma opcao acima digitando o numero correspondente: ");
  scanf("%d", &option);

  switch(option) {
    case 1:
      printf("\n--------- COMECO DO QUICK SORT ---------\n\n");
      quickSort(vetor, tamanho);
      break;
    case 2:
      printf("\n--------- RESULTADO DO SHELL SORT ---------\n\n");
      shellSort(vetor, tamanho);
      printArray(vetor, tamanho);
      break;
    case 3:
      printf("\n--------- COMECO DO MERGE SORT ---------\n\n");
      mergeSort(vetor, 0, tamanho - 1);
      break;
  }

  return;
}

int main(void) {
  int * vetor;
  vetor = selectRandomData();

  while(1) {
    int option;
    printf("\nTeste de performance de algoritmos\n");
    printf("Opcoes: \n");
    printf("1 - Executar algoritmos individualmente\n");
    printf("2 - Executar todos os algoritmos\n");
    printf("3 - Fim\n");
  
    printf("Selecione uma opcao acima digitando o numero correspondente: ");
    scanf("%d", &option);
  
    switch(option) {
      case 1:
        chooseAlgorithm(vetor);
        break;
      case 2:
        // To do: Testar essa opção
        break;
      case 3:
        goto EndWhile;
    }
  }
  EndWhile: ;
}