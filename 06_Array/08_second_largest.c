/*
-> PROBLEM : Second largest element in array
  Find the index of second largest element in the given array, 
  if it doesn't exist, then print -1.
*/

#include <stdio.h>
#define and &&

int secondLargest(int *arr, int n) {
  int L = 0;
  int sL = -1;
  
  for(int i = 1; i<n; i++){
    if(arr[i] > L) {
      sL = L;
      L = i;
    }
    if(arr[i] == L) {
      continue;
    }
    if(arr[i] < L) {
      if(sL == -1) {
        sL = i;
      }
      if(arr[sL] < arr[i]) {
        sL = i;
      }
    }
  } 
  return sL;
}

int main() {
  // code here
  int n; 
  scanf("%d", &n);
  int arr[n];
  for(int i = 0; i<n; i++) {
    scanf("%d", &arr[i]);
  }

  // solution
  printf("Index of second largest element in array is : %d\n", secondLargest(arr, n));
  return 0;
}