/*
 * Problem : Print leader elements in an array.
 * An element is called leader if there is nothing which is greater than 
 * this element on right of it.
 */

#include <stdio.h>

// Theta(n) : time and space complexity
void printLeaders(int *arr, int n);

// Theta(n) : time complexity and Theta(1) : space complexity
void gfgLeader(int *arr, int n);

int main() {
  // code here
  int n;
  scanf("%d", &n);

  int arr[n];
  for(int i = 0; i<n; i++) {
    scanf("%d", &arr[i]);
  }

  // logic
  printLeaders(arr, n);

  gfgLeader(arr, n);
  return 0;
}

void printLeaders(int *arr, int n) {
  printf("\n");

  int suffix[n];
  suffix[n-1] = arr[n-1];
  for(int i = n-2; i >= 0; i--) {
    if(arr[i] > suffix[i+1]) {
      suffix[i] = arr[i];
    } else {
      suffix[i] = suffix[i+1];
    }
  }

  // now print unique elements
  printf("%d ", suffix[0]);
  for(int i = 1; i<n; i++) {
    if(suffix[i] != suffix[i-1]) {
      printf("%d ", suffix[i]);
    }
  }
  printf("\n");
}

void gfgLeader(int *arr, int n) {
  printf("\n\n");
  int currLdr = arr[n-1];
  printf("%d ", currLdr);

  for(int i = n-2; i >= 0; i--) {
    if(currLdr < arr[i]) {
      currLdr = arr[i];
      printf("%d ", currLdr);
    }
  }
  printf("\n\n");
}