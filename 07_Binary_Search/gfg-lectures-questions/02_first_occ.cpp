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
        
    }
}

void solve() {
    // question here
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 0;
    cin >> t;

    while(t--) solve();
    return 0;
}