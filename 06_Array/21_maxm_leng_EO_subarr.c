/**
 * @file 21_maxm_leng_EO_subarr.c
 * @date 2021-10-13
 * 
 * PROBLEM STATEMENT :
 * You have to find maximum length of subarray with alternating even odd elements.
 **/

#include <stdio.h>
 
int maxLengthSubarr(int *arr, int n) {

    int res = 1;
    int curr = 1;
    for(int i = 0; i<n; i++) {
        if((arr[i]%2 == 0 && arr[i-1]%2 != 0) || 
            (arr[i]%2 != 0 && arr[i-1]%2 == 0)) {
            curr++;
            res = max(res, curr);        
        } else {
            curr = 1;
        } 
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

    // calling the function
    printf("Maximum length of subarray with alternating even odd elements is: %d\n\n", \
    maxLengthSubarr(arr, n));

    return 0;
}