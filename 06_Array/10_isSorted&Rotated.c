/*
  PROBLEM : isSortedAndRotated
  Here you will be given an array of n distinct integers, 
  you have to tell if the array is rotated(counter clockwise) and
  before rotating either the array was non-decreasing or non-increasing.
  If both sorted and rotated condition satisfies, then return true, else 
  return false.
*/

#include <stdio.h>
#include <stdbool.h>

bool checkRotatedAndSorted(int arr[], int n)
{
  int count = 0;
  if (arr[0] < arr[n - 1])
  {
    for (int i = 1; i < n; i++)
    {
      if (arr[i - 1] < arr[i])
      {
        count++;
      }
    }
    if (count != 1)
    {
      return false;
    }
    return true;
  }
  else
  {
    count = 0;
    for (int i = 1; i < n; i++)
    {
      if (arr[i - 1] > arr[i])
      {
        count++;
      }
    }
    if (count != 1)
    {
      return false;
    }
    return true;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for(int i = 0; i<n; i++) {
    scanf("%d", &arr[i]);
  }

  if(checkRotatedAndSorted(arr, n)) {
    printf("True\n");
  } else {
    printf("False\n");
  }
}