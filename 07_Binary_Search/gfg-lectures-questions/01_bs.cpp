//
// Created by vivek on 21/12/23.
//

#include <bits/stdc++.h>
using namespace std;

int bsearch(int key, int n, const int arr[]) {
    int lo = 0;
    int hi = n-1;

    while(hi - lo > 1) {
        int mid = lo + (hi - lo)/2;
        if(arr[mid] == key) return mid;
        if(key > arr[mid]) {
            lo = mid + 1;
            continue;
        } else {
            hi = mid - 1;
            continue;
        }
    }
    if(arr[lo] == key) return lo;
    if(arr[hi] == key) return hi;
    return -1;
}

void solve() {
    // question here
    int n = 0, key = 0;
    cin >> n >> key;

    int arr[n];
    for(auto& x: arr) cin >> x;

    // solution
    cout << "The element " << key << " is present at index " <<
        bsearch(key, n, arr) << endl;
}

// driver's code here
int main() {
    // code here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 0;
    cin >> t;

    while(t--) solve();
    return 0;
}

///**
// * @file 01_BS.cpp
// * @brief Problem 01: Binary Search Implementation
// * @brief Given a sorted array of integers, return the index of the given key. Return -1 if not found.
// * @date 2023-10-03
// **/
//
//#include <iostream>
//
//// Binary Search Algorithm (iterative)
//int binarySearch(int *arr, int n, int key) {
//    int low = 0;
//    int high = n-1;
//
//    while (low <= high) {
//        int mid = (low + high) / 2;
//        if(arr[mid] == key) {
//            return mid; // key found
//        } else if (arr[mid] < key) {
//            low = mid + 1; // key is in the upper half
//        } else {
//            high = mid - 1; // key is in the lower half
//        }
//    }
//    return -1; // key not found
//}
//
//int main() {
//    // code here
//
//    int arr[] = {1, 2, 3, 4, 5, 6, 7};
//    int n = sizeof(arr)/sizeof(arr[0]);
//
//    int key = 5;
//    int index = binarySearch(arr, n, key);
//    std::cout << "Key " << key << " found at index " << index << std::endl;
//    return 0;
//}
//
///**
// * @brief Output
// * Key 5 found at index 4
// *
// * @note Time Complexity
// * O(log n)
// *
// * @note Space Complexity
// * O(1)
// *
// */
//
///**
// * Idea behind Binary Search Algorithm is to eliminate half of the array at each iteration.
// **/

///**
// * @file 02_BS.cpp
// * @brief a recursive binary search
// * @date 2023-10-03
// **/
//
//#include <iostream>
//
//// recursive binary search
//int binarySearch(int *arr, int low, int high, int key) {
//    // base case
//    if(low > high) return -1; // key not found
//
//    int mid = (low + high) / 2;
//
//    // base case
//    if(arr[mid] == key) return mid;
//
//    // recursive cases
//    else if(arr[mid] > key) {
//        return binarySearch(arr, low, mid - 1, key);
//    } else {
//        return binarySearch(arr, mid + 1, high, key);
//    }
//}
//
//int main() {
//    // code here
//    int n;
//    std::cin >> n;
//
//    int arr[n];
//    for(int i = 0; i < n; i++) std::cin >> arr[i];
//
//    int key;
//    std::cin >> key;
//
//    std::cout << binarySearch(arr, 0, n - 1, key) << std::endl;
//    return 0;
//}
//
//// Time Complexity: O(log n)
//
///**
// * @note idea is to divide the array into two parts and check if the key
// *  is in the left or right part.
// **/
