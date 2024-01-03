/*
-> Problem :
  Given an array A[] of N positive integers. The task is to find the maximum 
  of j - i subjected to the constraint of A[i] <= A[j] and i <= j.
*/

#include <stdio.h>

#define and &&
#define or ||
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b

// brute force solution which has quadratic time complexity( O(n^2) )
int maxIndexDiff_brute_force(int A[], int N) {
  // Your code here
  int max_diff = 0;
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (A[i] <= A[j] && j - i > max_diff) {
        max_diff = j - i;
      }
    }
  }
  if (max_diff != 0) {
    return max_diff;
  }
  return 0;
}

int maxIndexDiff_OP(int A[], int N) {
  // code here
  int larr[N], rarr[N];
  // filling the prefix array
  larr[0] = A[0];
  for(int i = 1; i<N; i++) {
    larr[i] = min(A[i], larr[i-1]);
  } // filled prefix array

  // filling the suffix array
  rarr[N-1] = A[N-1];
  for(int i = N-2; i>=0; i--) {
    rarr[i] = max(A[i], rarr[i+1]);
  } // filled the suffix array

  int i = 0, j = 0, max_till = -1;
  while(i < N and j < N) {
    if(rarr[j] >= larr[i]) {
      max_till = max(max_till, j-i);
      j++;
    } else {
      i++;
    }
  } 
  if(max_till == -1) {
    return 0;
  } 
  return max_till;
} // this approach has linear time complexity

int main() {
  // code here
  int t;
  scanf("%d", &t);

  while (t--) {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
    }

    printf("%d\n", maxIndexDiff_OP(arr, n));
  }

  return 0;
}