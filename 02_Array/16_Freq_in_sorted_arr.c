/*
 * Problem : Frequencies in a sorted array
 */

#include <stdio.h>

void printFreq(int *arr, int n) {
  int freq = 1, i = 1;
  while (i < n)
  {
    while (i < n && arr[i] == arr[i-1]) {
      freq++;
      i++;
    }
    printf("%d %d\n", arr[i-1], freq);
    i++;
    freq = 1;
  }
  if(n == 1 || arr[n-1] != arr[n-2]) {
    printf("%d %d\n", arr[n-1], 1);
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

  printFreq(arr, n);
  return 0;
}