/*
  Problem :
  This is the famous maximum subarray problem.
*/

#include <stdio.h>
#include <limits.h>

int max_subarray_sum(int *arr, int n) {
  int max_so_far = INT_MIN;
  int max_ending_here = 0;
  for(int i = 0; i<n; i++) {
    max_ending_here += arr[i];

    if(max_so_far < max_ending_here) {
      max_so_far = max_ending_here;
    }

    if(max_ending_here < 0) {
      max_ending_here = 0;
    } 
  } return max_so_far;
}

int main() {
  // code here
  int n;
  puts("Enter the number of elements in the array : ");
  scanf("%d", &n);
  puts("\n");

  int arr[n];
  puts("Enter the array elements : \n");
  for(int i = 0; i<n; i++) {
    scanf("%d", &arr[i]);
  } // array input is taken 

  printf("\n\nThe maximum subarray sum is : %d.\n\n", max_subarray_sum(arr, n));
  return 0;
}