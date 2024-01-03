/*
  Problem :
  You have given an array A of n integers. You have to find equilibrium 
  index i from left such that
  A[0] + A[1] +... + A[i-1] = A[i+1] + A[i+2] +... + A[n-1]
*/

#include <stdio.h>
#include <limits.h>

int eqmIndex(int *arr, int n) {
  if(n < 3) {
    puts("Equilibrium index is not defined for array of size less than 3.\n");
    return INT_MIN;
  }
  int i;
  int left_sum = 0, sum = 0;
  for(i = 0; i<n; i++) {
    sum += arr[i];
  } // sum = sum of all elements in the array

  for(i = 0; i<n; i++) {
    sum -= arr[i];
    if(sum == left_sum) {
      return i;
    } left_sum += arr[i];
  } puts("Equilibrium index doesn't exist for this array.\n");
  return INT_MIN;
}

int main() {
  //code here
  int n;
  puts("Enter the number of elements in the array : ");
  scanf("%d", &n);
  puts("\n");

  int arr[n];
  puts("Enter the array elements : \n");
  for(int i = 0; i<n; i++) {
    scanf("%d", &arr[i]);
  } // array input is taken 

  // work
  printf("The equilibrium index for this array is : %d.\n\n", eqmIndex(arr, n));
  return 0;
}