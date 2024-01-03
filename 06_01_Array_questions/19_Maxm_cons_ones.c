/**
 * @file 19_Maxm_cons_ones.c  
 * @date 2023-09-25
 * 
 * PROBLEM STATEMENT :
 * Given a binary array, find the maximum number of consecutive 1s in this array.
 * 
 */

#include <stdio.h>

// function to find the maximum number of consecutive 1s in the array
int maxm_cons_ones (int *arr, int n) {
    // code here
    int max_till_here = 0;
    int count_max = 0;

    for(int i = 0; i<n; i++) {
        if(arr[i] == 1) {
            // count the number of 1s
            while(i < n && arr[i] == 1) {
                max_till_here++;
                i++;
            }
            // update count_max if required 
            count_max = max(max_till_here, count_max);
            // reset max_till_here to 0
            max_till_here = 0;
        } else {
            continue;
        }
    }
    return count_max;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    // calling the function
    printf("Maximum number of consecutive 1s in the array are: %d\n\n", \
    maxm_cons_ones(arr, n));
    return 0;
}

// Time Complexity: O(n)

// Test Case 1:
// Input: 5
//        1 1 0 1 1
// Output: Maximum number of consecutive 1s in the array are: 2

// Test Case 2:
// Input: 6
//        1 0 1 1 0 1
// Output: Maximum number of consecutive 1s in the array are: 2