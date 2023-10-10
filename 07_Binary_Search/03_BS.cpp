
/**
 * @file 03_BS.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-10
 */

#include <iostream>
using namespace std;

int first_index (int arr[], int low, int high, int x) {
    if(high >= low) {
        int mid = (low+high) / 2;

        if(mid == 0 || arr[mid] == x && arr[mid - 1] < x) {
            return mid;
        } else if(x > arr[mid]) {
            return first_index(arr, mid+1, high, x);
        } else {
            return first_index(arr, low, mid - 1, x);
        }
    }
    return -1; // element not found
}

int last_index(int arr[], int n, int low, int high, int x) {
    if (high >= low) {
        int mid = (low + high) / 2;

        if (arr[mid] == x && (mid == n - 1 || arr[mid + 1] > x)) {
            return mid;
        } else if (x < arr[mid]) {
            return last_index(arr, n, low, mid - 1, x);
        } else {
            return last_index(arr, n, mid + 1, high, x);
        }
    }
    return -1; // element not found
}

int count_occurences (int arr[], int n, int x) {
    int first = first_index(arr, 0, n-1, x);
    int last  = last_index (arr, n, 0, n-1, x);

    if(first == -1) {
        return 0;
    } else {
        return last - first + 1;
    }
}

int main() {
    // code here
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    cout << count_occurences(arr, n, x) << endl;
    return 0;
}