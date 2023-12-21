//
// Created by vivek on 21/12/23.
//

/**
 * Problem : Given a sorted array, find index of last occurrence of an element key.
 * */

#include <bits/stdc++.h>
using namespace std;

int last_occ(int key, int n, const int arr[]) {
    int lo = 0;
    int hi = n-1;

    while(lo <= hi) {
        int mid = lo + (hi-lo)/2;
        if(arr[mid] > key) {
            hi = mid - 1;
        } else if (arr[mid] < key) {
            lo = mid + 1;
        } else {
            if(mid == n-1 || arr[mid] != arr[mid+1]) {
                return mid;
            } else {
                lo = mid + 1;
            }
        }
    }
    return -1;
}

void solve() {
    // question here
    int n = 0, key = 0;
    cin >> n >> key;

    int arr[n];
    for(auto& x: arr) cin >> x;

    cout << last_occ(key, n, arr) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 0;
    cin >> t;

    while(t--) solve();
    return 0;
}