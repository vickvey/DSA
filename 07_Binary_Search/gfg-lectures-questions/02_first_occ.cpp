//
// Created by vivek on 21/12/23.
//

/**
 * Problem : Given a sorted array, find first occurrence of an element key.
 * */

#include <bits/stdc++.h>
using namespace std;

int first_occ(int key, int n, const int arr[]) {
    int lo = 0;
    int hi = n-1;

    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        if(arr[mid] == key && (mid == 0 || arr[mid-1] != key)) return mid;
        else if (arr[mid] > key) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

void solve() {
    // question here
    int n = 0, key = 0;
    cin >> n >> key;

    int arr[n];
    for(auto& x: arr) cin >> x;

    cout << first_occ(key, n, arr) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 0;
    cin >> t;

    while(t--) solve();
    return 0;
}