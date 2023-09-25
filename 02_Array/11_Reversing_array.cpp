/*
  Problem : Reverse an array in groups of k elements and store it in itself.
*/

#include <stdio.h>
#include <iostream>
#include <vector>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void reverseArray(int *arr, int n) {
  int low = 0;
  int high = n-1;
  while(low < high) {
    swap(&arr[low], &arr[high]);
    low++;
    high--;
  }
} // Time Complexity : Theta of n

void printArray(int *arr, int n) {
  for(int i = 0; i<n; i++) {
    printf("%d ", arr[i]);
  }
}

void reverseInGroups(std::vector<long long>& arr, int n, int k){
  // code here
  int low = 0;
  int high = k-1;
  int last_high = high;
  if(k > n) {
    low = 0;
    high = n-1;
    last_high = n-1;
  }
  while(low < high) {
    long long temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;
    low++;
    high--;

    if(low >= high) {
      if(last_high + 1 > n) {
        break;
      } low = last_high + 1;
      if(last_high + k <= n-1) {
        high = last_high + k;
        last_high = high;
      } else if(last_high + k > n-1){
        high = n-1;
        last_high = high;
      }
    }
  }
}

int main() {
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);
  std::vector<long long> arr;
  int temp = 0;
  for(int i = 0; i<n; i++) {
    scanf("%d", &temp);
    arr.push_back(temp);
  }

  reverseInGroups(arr, n, k);

  for(int i = 0; i<n; i++) {
    std::cout << arr[i] << " ";
  }
  return 0;
}