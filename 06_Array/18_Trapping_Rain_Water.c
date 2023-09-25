/*
 * Problem : Trapping Rain Water
 */

#include <stdio.h>

#define max(x, y) (x>y?x:y)
#define min(x, y) (x<y?x:y)

// Quadratic time complexity (Naive Solution)
int naive_getWater(int *arr, int n) {
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

// Linear time complexity (Efficient Solution)
int efficient_getWater(int *arr, int n) {
  int res = 0;
  int lMax[n], rMax[n];

  // pre-compute lMax and rMax for a particular index
  lMax[0] = arr[0];
  for(int i = 1; i<n; i++) {
    lMax[i] = max(arr[i], lMax[i-1]);
  }
  rMax[n-1] = arr[n-1];
  for(int i = n-2; i>=0; i--) {
    rMax[i] = max(arr[i], rMax[i+1]);
  }

  // calculate the water
  for(int i = 1; i<n-1; i++) {
    res = res + (min(lMax[i], rMax[i]) - arr[i]);
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

  // logic of the question
  printf("Naive Solution: %d\n", naive_getWater(arr, n));          // O(n^2)
  printf("Efficient Solution: %d\n", efficient_getWater(arr, n));  // O(n)
  // OUTPUT: Naive Solution: 10 
  //         Efficient Solution: 10
  return 0;
}

// Extra notes:
/**
 * @brief 
 * The key thing to note here is that water trapped at any element = min(lMax, rMax) - arr[i]) 
 * where lMax = maximum element on the left of arr[i] including arr[i]
 *       and rMax = maximum element on the right of arr[i] including arr[i]
 * 
 * So, we can pre-compute lMax and rMax for a particular index
 * 
 */