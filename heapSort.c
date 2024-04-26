#include <stdio.h>
#include <stdlib.h>

void createHeap (int *A, int i, int f) {
  int aux = A[i];
  int j = i*2+1;
  
  while (j <= f) {
    // here it will organize the sons of every father (if son1 is greater than son2, 
    // then it puts in order son2 < son1)
    if (j < f) { 
      if (A[j] < A[j+1]) {
        j = j+1;
      }
    }
    // verify if the father is greater than their sons, if not, switch their places
    if (aux < A[j]) {
      A[i] = A[j];
      i = j;
      j = i*2+1;
    } else {
      // ends the iteration
      j = f +1;
    }
  }
  // old father occupies the plaace of the last son seen
  A[i] = aux;
}

void heapSort (int *A, int n) {
  int aux, i;

  // organizes the left subtree, as the createHeap only plays with the right part
  for (i=(n-1)/2; i >= 0; i--) {
    createHeap (A, i, n-1);
  }

  // transforms the father (biggest element) at the last element of the array, 
  // ordering at each iteraction
  for (i=n-1; i>= 1; i--) {
    aux = A[0];
    A[0] = A[i];
    A[i] = aux;
    createHeap(A, 0, i-1);
  }
}



int main(void) {
  int n;

  scanf("%d", &n);

  int *A = (int*)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  heapSort (A, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
  
  return 0;
}