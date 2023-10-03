/**
 * @file 02_BS.cpp
 * @brief a recursive binary search
 * @date 2023-10-03
 **/

#include <iostream>

// recursive binary search
int binarySearch(int *arr, int low, int high, int key) {
    // base case
    if(low > high) return -1; // key not found

    int mid = (low + high) / 2;

    // base case
    if(arr[mid] == key) return mid;

    // recursive cases
    else if(arr[mid] > key) {
        return binarySearch(arr, low, mid - 1, key);
    } else {
        return binarySearch(arr, mid + 1, high, key);
    }
}

int main() {
    // code here
    int n;
    std::cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) std::cin >> arr[i];

    int key;
    std::cin >> key;

    std::cout << binarySearch(arr, 0, n - 1, key) << std::endl;
    return 0;
}

// Time Complexity: O(log n)

/**
 * @note idea is to divide the array into two parts and check if the key
 *  is in the left or right part.
 **/