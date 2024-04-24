#include <stdio.h>
#include <stdlib.h>

void insertionSort (int n, int *A) {
  int key;
  int i, j;
  
  for (i = 0; i < n; i++) {
    key = A[i];
    j = i-1;

    // here is compared the key with the elements in the left side
    // of the array, if the element to the left is bigger, it is 
    // moved to the right
    while (A[j] > key && j >= 0) {
      A[j+1] = A[j];
      j = j-1;
    }

    // when the element is found, it is put in its right place in
    // the array
    A[j+1] = key;
    
  }
  
}

int main(void) {
  int n, i;


  n = 0;
  scanf("%d", &n);

  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  
  insertionSort (n, A);

  for (i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
  
  return 0;
}