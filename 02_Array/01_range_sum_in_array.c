/*
  Problem : 
  You have given an array of n elements along with q queries where each query
  contains a pair (l, r) where l and r are possible indexes of the array with 
  l <= r , then you have to find the sum of elements of the array indexed from 
  l to r.
*/

#include <stdio.h>

int main() {
  // code here
  int n, q, l, r;
  puts("Enter the size of array :");
  scanf("%d", &n);
  int arr[n];

  int prefixArr[n];
  puts("Enter the elements of the array : ");
  scanf("%d", &arr[0]);
  prefixArr[0] = arr[0];
  for(int i = 1; i<n; i++) {
    scanf("%d", &arr[i]);
    prefixArr[i] = arr[i] + prefixArr[i-1];
  } // prefix array is ready

  puts("Enter the number of queries: ");
  scanf("%d", &q);
  while(q--) {
    puts("Enter left index : ");
    scanf("%d", &l);
    puts("Enter right index : ");
    scanf("%d", &r);    

    printf("\nThe sum of elements b/w index %d and %d is : \n", l, r);
    if(l == 0) {
      printf("Sum = %d\n\n", prefixArr[r]);
    } else {
      printf("Sum = %d\n\n", prefixArr[r]-prefixArr[l-1]);
    }
  }  
  return 0;
}