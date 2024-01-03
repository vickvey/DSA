/*
  Problem :
  You have given two sorted arrays arr1 and arr2 of sizes m and n respectively.
  Merge the two arrays into a third array arr3 of size m+n;
*/

#include <stdio.h>

void printArray(int *arr, int n) {
  puts("\nHere is your array : \n");
  for(int i = 0; i<n; i++) {
    printf("The index %d has element : %d.\n", i, arr[i]);
  } puts("\n\n");
}

void merge_sorted_arrays(int *arr1, int *arr2, int m, int n) {
  int arr3[m+n];
  int i = 0, j = 0, k = 0;
  while(i < m && j < n) {
    if(arr1[i] < arr2[j]) {
      arr3[k++] = arr1[i++];
    } else {
      arr3[k++] = arr2[j++];
    }
  }
  while(i < m) {
    arr3[k++] = arr1[i++];
  }
  while(j < n) {
    arr3[k++] = arr2[j++];
  } printArray(arr3, m+n);
}

int main() {
  // code here
  puts("\nYou can merge two sorted arrays through this program.\n");
  int m, n;
  puts("Enter the size of first array : ");
  scanf("%d", &m);
  int arr1[m];
  puts("Enter the first array elements : ");
  for(int i = 0; i<m; i++) {
    scanf("%d", &arr1[i]);
  } // first array input is complete

  puts("\nNow, Enter the size of second array : ");
  scanf("%d", &n);
  int arr2[n];
  puts("Enter the second array elements : ");
  for(int i = 0; i<n; i++) {
    scanf("%d", &arr2[i]);
  } // second array input is complete 

  merge_sorted_arrays(arr1, arr2, m, n);
  return 0;
}