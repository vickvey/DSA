
/*
 * PROBLEM : Left Rotate An Array By D Places
 */

#include <stdio.h>

void swap(int *a, int *b);
void reverse(int *arr, int low, int high);
void leftRotate(int *arr, int n, int d);

void printArray(int *arr, int n);

int main() {
  // code here
  int n, d;
  scanf("%d", &n);

  int arr[n];
  for(int i = 0; i<n; i++) {
    scanf("%d", &arr[i]);
  }

  scanf("%d", &d);

  leftRotate(arr, n, d);

  printArray(arr, n);
  return 0;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void reverse(int *arr, int low, int high) {
  while(low < high) {
    swap(&arr[low], &arr[high]);
    low++;
    high--;
  }
}

void leftRotate(int *arr, int n, int d) {
  reverse(arr, 0, d-1);
  reverse(arr, d, n-1);
  reverse(arr, 0, n-1);
}

void printArray(int *arr, int n) {
  for(int i = 0; i<n; i++) {
    printf("%d ", arr[i]);
  } printf("\n");
}