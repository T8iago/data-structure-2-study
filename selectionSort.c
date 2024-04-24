#include <stdio.h>
#include <stdlib.h>

// Funcao de troca para ser usada no Selection Sort
void swap (int *a, int *b) {
  int aux;
  
  aux = *a;
  *a = *b;
  *b = aux;
  
}

// Funcao de ordenacao utilizado que reorganiza o vetor
void selectionSort (int n, int *A) {

  // Este 'for' vai ver, em ordem, cada elemento do vetor, e vai selecionar o elemento pra ser comparado com o resto
  for (int j = 0; j < n-1; j++) {
    
    int min = j;

    // Enquanto isso, este 'for' vai comparar os elementos a direita do elemento selecionado, sempre que achar um elemento menor, coloca ele na posicao do elemento selecionado
    for (int i = j + 1; i < n; i++) {
        if (A[i] < A[min]) {
            min = i;
        }
    }

    // Verifica se alguma troca e necessaria, se sim, a troca ocorre
    if (min != j) {
        swap(&A[j], &A[min]);
    }
  }
}

int main(void) {
  int n;

  // Declara o tamanho do vetor
  n = 0;
  scanf ("%d", &n);

  // Alocacao dinamica da memoria
  int *A = (int *)malloc(n * sizeof(int));
  if (A == NULL) {
    printf("Falha na alocacao da memoria \n");
    return -1;
  }

  // Coloca os elementos nao-ordenados dentro do vetor
  for (int i = 0; i < n; i++) {
    scanf ("%d", &A[i]);
  }

  // Chama a funcao para reordenar os elementos
  selectionSort(n, A);

  // Imprime a matriz ordenada
  for (int i = 0; i < n; i++) {
    printf ("%d ", A[i]);
  }

  printf("\n");

  // Libera a memoria alocada de forma dinamica
  free(A);
  
  return 0;
}
