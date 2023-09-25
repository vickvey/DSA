/*
 * Problem : Stock buy and sell
 */

#include <stdio.h>

int maxProfit(int *price, int n) {
  int profit = 0;
  for(int i = 0; i<n; i++) {
    if(price[i] > price[i-1]) {
      profit += (price[i] - price[i-1]);
    }
  } return profit;
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
  int res = maxProfit(arr, n);
  printf("\nMax profit : %d\n", res);
  return 0;
}