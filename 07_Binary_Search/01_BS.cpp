/**
 * @file 01_BS.cpp
 * @brief Problem 01: Binary Search Implementation
 * @brief Given a sorted array of integers, return the index of the given key. Return -1 if not found.
 * @date 2023-10-03
 **/

#include <iostream>

// Binary Search Algorithm (iterative)
int binarySearch(int *arr, int n, int key) {
    int low = 0;
    int high = n-1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == key) {
            return mid; // key found
        } else if (arr[mid] < key) {
            low = mid + 1; // key is in the upper half
        } else {
            high = mid - 1; // key is in the lower half
        }
    }
    return -1; // key not found
}

int main() {
    // code here

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    int key = 5;
    int index = binarySearch(arr, n, key);
    std::cout << "Key " << key << " found at index " << index << std::endl;
    return 0;
}

/**
 * @brief Output
 * Key 5 found at index 4
 *
 * @note Time Complexity
 * O(log n)
 *
 * @note Space Complexity
 * O(1)
 *
 */

/**
 * Idea behind Binary Search Algorithm is to eliminate half of the array at each iteration.
 **/