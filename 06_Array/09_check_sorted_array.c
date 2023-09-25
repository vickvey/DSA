/*
-> Problem : 
  You have given an array of N elements. You have to check whether the array is
  sorted in non-decreasing order or not.
*/

#include <stdio.h>
#include <stdbool.h>

bool isSorted(int *arr, int n) {
  int test[n];
  test[0] = arr[0];
  for(int i = 1; i<n; i++) {
    if(test[i-1] > arr[i]) {
      return false;
    }
    if(test[i-1] <= arr[i]) {
      test[i] = arr[i];
    }
  }
  for(int i = 0; i<n; i++) {
    if(test[i] != arr[i]) {
      return false;
    }
  } return true;
}


int main() {
  // code here
  int n;
  scanf("%d", &n);
  int arr[n];
  for(int i = 0; i<n; i++) {
    scanf("%d", &arr[i]);
  } // array input is completer

  // solution
  if(isSorted(arr, n)) {
    printf("The array is sorted in non-descending order.\n");
  } else {
    printf("The array is not sorted in non-descending order.\n");
  }
  return 0;
}