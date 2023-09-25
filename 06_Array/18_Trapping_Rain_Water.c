/*
 * Problem : Trapping Rain Water
 */

#include <stdio.h>

#define max(x, y) (x>y?x:y)
#define min(x, y) (x<y?x:y)

// Quadratic time complexity
__attribute_maybe_unused__ void naive_getWater(int *arr, int n) {
  int res = 0;
  for(int i = 1; i<n; i++) {
    int lMax = arr[i];
    for(int j = 0; j<i; i++) {
      lMax = max(lMax, arr[j]);
    }
    int rMax = arr[i];
    for(int j = i+1; j<n; j++) {
      rMax = max(rMax, arr[i]);
    }
    res = res + (min(lMax, rMax) - arr[i]);
  } return res;
}

int maxWaterTrapped(int *arr, int n) {
  int amount = 0, i = 0, size;
  int left_height = arr[0], right_height;
  enum monotonic_type {
    inc = 0, dec = 1, equal = 2
  } condition;

  // to eat up starting iterations with equal heights
  while(i < n) {
    if(arr[i] == arr[++i]) {
      i++;
    } else {
      break;
    }
  }

  if(arr[i] < arr[i+1]) {
    left_height = arr[i];
    condition = inc;
    i++;
  } else {
    condition = dec;
    i++;
  }

  // now checking for the thing
  // continue from here
}

int main() {
  // code here
  int n;
  scanf("%d", &n);

  int arr[n];
  for(int i = 0; i<n; i++) {
    scanf("%d", &arr[i]);
  }

  // logic of the question

  return 0;
}