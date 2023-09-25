
/**
 * @file 20_maxm_subarr_sum.c
 * @date 2021-10-13
 * 
 * PROBLEM STATEMENT :
 * Given an integer array nums, find the maximum sum of any contiguous subarray of the array.
 */

#include <stdio.h>
#include <limits.h>

int max_subarr_sum(int *arr, int n) {
    int max_till_here = 0;
    int max_so_far = INT_MIN;

    // Kadane's Algorithm
    for(int i = 0; i<n; i++) {
        // add the current element to max_till_here
        max_till_here += arr[i];

        // update max_so_far if required
        if(max_till_here > max_so_far) {
            max_so_far = max_till_here;
        }
        
        // if max_till_here is negative, reset it to 0
        if(max_till_here < 0) {
            max_till_here = 0;
        }
    } 

    // return the maximum sum of any contiguous subarray of the array
    return max_so_far;
}

int main() {
    // code here
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    // calling the function 
    printf("Maximum sum of any contiguous subarray of the array is: %d\n\n", \
    maxm_subarr_sum(arr, n));
    return 0;
}

// Time Complexity: O(n)

// Test Case 1:
// Input: 5
//        1 2 3 -2 5
// Output: Maximum sum of any contiguous subarray of the array is: 9

// Explanation of Kadane's Algorithm:
// 1. Initialize:
//     max_till_here = 0
//     max_so_far = INT_MIN
// 2. Loop for each element of the array
//     a. max_till_here = max_till_here + a[i]
//     b. if(max_so_far < max_till_here)
//             max_so_far = max_till_here
//     c. if(max_till_here < 0)
//             max_till_here = 0
// 3. return max_so_far
//