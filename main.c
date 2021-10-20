#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int tamanho = 0;

int eatLine(FILE *fp) {
    for(;;) {
        int ch = getc(fp);
        if (ch == '\n' || ch < 0) return ch;
    }
}

void createRandomData() {
  // Todo: Cria dados randomicos
}

int * selectRandomData() {
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
    } while (a <= b);
    // troca pivo
    v[0] = v[b];
    v[b] = x;
    // ordena sub-vetires restantes
    quickSort(v, b);
    quickSort(&v[a], tam - a);
  }
}

void shellSort(int v[], int tam) {
  // Rearrange elements at each n/2, n/4, n/8, ... intervals
  for (int interval = tam / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < tam; i += 1) {
      int temp = v[i];
      int j;
      for (j = i; j >= interval && v[j - interval] > temp; j -= interval) {
        v[j] = v[j - interval];
      }
      v[j] = temp;
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
  }
  // copia vetor intercalado para o vetor original
  for (i = inicio; i <= fim; i++)
    v[i] = t[i - inicio];
  free(t);
}

void chooseAlgorithm(int* vetor) {
  int option;
  char showResults;
  printf("\nSelecione uma algoritmo\n");
  printf("Opcoes: \n");
  printf("1 - Quick Sort\n");
  printf("2 - Shell Sort\n");
  printf("3 - Merge Sort\n");

  printf("Selecione uma opcao acima digitando o numero correspondente: ");
  scanf("%d", &option);

  switch(option) {
    case 1:
      quickSort(vetor, tamanho);
      break;
    case 2:
      shellSort(vetor, tamanho);
      break;
    case 3:
      mergeSort(vetor, 0, tamanho - 1);
      break;
  }

  printf("\nMostrar resultados? S/N ");
  scanf("%d", &showResults);

  if (toupper(showResults) == 'S') {
    // To do: Mostrar resultadados de performance dos algorítmos
  }

  return;
}

int main(void) {
  while(1) {
    int option;
    int * vetor;

    printf("\nTeste de performance de algoritmos\n\n");
    printf("Opcoes: \n");
    printf("1 - Selecionar arquivo estatico para analise dos dados\n");
    printf("2 - Gerar vetor para analise dos dados\n\n");

    printf("Selecione uma opcao acima digitando o numero correspondente: ");
    scanf("%d", &option);
    
    switch(option) {
      case 1:
        vetor = selectRandomData();
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
  
    switch(option) {
      case 1:
        chooseAlgorithm(vetor);
        goto EndWhile;
      case 2:
        // To do: Testar essa opção
        goto EndWhile;
      case 3:
        goto EndWhile;
    }
  }
  EndWhile: ;
}