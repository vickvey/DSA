
#include <stdio.h>
#include <limits.h>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)


// naive solution
int maxSumCircSA_eff(int arr[], int n) {
    int res = arr[0];
    for(int i = 0; i<n; i++) {
        int curr_max = arr[i];
        int curr_sum = arr[i];

        for(int j = 1; j<n; j++) {
            int index = (i+j) % n;
            curr_sum += arr[index];
            curr_max = max(curr_max, curr_sum);
        }
        res = max(res, curr_max);
    } return res;
}

int maxSumCircSA_eff (int arr[], int n) {
    if(n == 1) {
        return arr[0];
    }

    int total_sum = arr[0];
    int max_sum = INT_MIN;
    int min_sum = INT_MAX;

    int max_till_here = arr[0];
    int min_till_here = arr[0];

    for(int i = 1; i<n; i++) {
        total_sum += arr[i];

        max_till_here = max(arr[i], max_till_here + arr[i]);
        min_till_here = min(arr[i], min_till_here + arr[i]);

        max_sum = max(max_sum, max_till_here);
        min_sum = min(min_sum, min_till_here);
    }

    if(max_sum < 0) {
        return max_sum;
    }

    // Calculate and return the maximum of two cases:
    // 1. Maximum subarray sum (non-circular)
    // 2. Total sum minus the minimum subarray sum (circular)
    return max(max_sum, total_sum - min_sum);
}

//-----------------------------------------------------------------
// better approach

int normalMaxSum (int arr[], int n) {
    int res = arr[0];
    int maxEnding = arr[0];

    for(int i = 0; i<n; i++) {
        maxEnding = max(maxEnding, maxEnding + arr[i]);
        res = max(res, maxEnding);
    }
}

int overallMaxSum (int arr[], int n) {
    int max_Normal = normalMaxSum(arr, n);
    if(max_Normal < 0) {
        return max_Normal;
    }

    int arr_sum = 0;
    for(int i = 0; i<n; i++) {
        arr_sum += arr[i];
        arr[i] = -arr[i];
    }

    int max_Circular = arr_sum + normalMaxSum(arr, n);
    return max(max_Normal, max_Circular);
}
//-----------------------------------------------------------------

int main() {
    // code here
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    // solution
    printf("Maxm sum of circular subarray is: %d\n\n", 
        maxmSumCircSA(arr, n));
    return 0;
}