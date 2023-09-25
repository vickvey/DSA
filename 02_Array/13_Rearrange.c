/*
 * PROBLEM: Rearrange an array with O(1) extra space
 * LEVEL : Medium
 * Given an array arr[] of size N where every element is in the range
 * from 0 to n-1. Rearrange the given array so that the transformed
 * array arrT[i] becomes arr[arr[i]].
 */

#include <stdio.h>

void printArray(int *arr, int n) {
  for(int i = 0; i<n; i++) {
    printf("%d ", arr[i]);
  }
}

void arrange (int *arr, int n) {
  for(int i = 0; i<n; i++) {
    // divisor = (divident * quotient) + remainder
    /*
      here:
      divisor = arr[i]
      divident = arr[arr[i]]%n
      quotient = n
      remainder = arr[i]
    */
    arr[i] =  (arr[arr[i]]%n)*n + arr[i]; 
  }
  for(int i = 0; i<n; i++) {
    arr[i] = arr[i]/n;
  }
}

int main() {
  // code here
  int n;
  scanf("%d", &n);
  int arr[n];
  for(int i = 0; i<n; i++) {
    scanf("%d", &arr[i]);
  }
  // making rearrangement and solving the array
  printArray(arr, n);
  puts("\n\n");
  arrange(arr, n);
  printArray(arr, n);
  return 0;
}
