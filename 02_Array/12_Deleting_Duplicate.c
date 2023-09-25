/*
  PROBLEM : Remove Duplicates From Sorted Array
*/

#include <stdio.h>

int removeDuplicates (int *arr, int n) {
  int res = 1;
  for(int i = 1; i<n; i++) {
    if(arr[i] != arr[res-1]) {
      arr[res] = arr[i];
      res++;
    }
  } return res;
}

int main() {
  // code here
  int n;
  scanf("%d", &n);
  int arr[n];
  for(int i = 0; i<n; i++) {
    scanf("%d", &arr[i]);
  }

  int size = removeDuplicates(arr, n);
  for(int i = 0; i<size; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}