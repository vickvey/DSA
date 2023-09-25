/*
  Problem : 
  You have an array of n elements then you have to return the index of largest
  element.
*/


#include <stdio.h>
#include <limits.h>

int largestElement_idx(int *arr, int n) {
  int req_idx = 0;
  int largest = arr[0];
  for(int i = 1; i<n; i++) {
    if(largest < arr[i]) {
      largest = arr[i];
      req_idx = i;
    }
  } return req_idx;
}

int main() {
  // code here
  int n;
  puts("Enter the number of elements in the array : ");
  scanf("%d", &n);

  int arr[n];
  puts("Enter the array elements one by one : \n");
  for(int i = 0; i<n; i++) {
    scanf("%d", &arr[i]);
  } // array input is complete

  printf("\n\nIndex of the largest element in the ");
  printf("given array is : %d\n\n", largestElement_idx(arr, n));

  return 0;
}