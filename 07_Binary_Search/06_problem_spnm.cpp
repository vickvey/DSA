#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
#define max(x, y) (x > y ? x : y)
#define min(x, y) (x < y ? x : y)
/////////////////////////////////////////////////////////////////////


// code here

/**
 * Problem : You are given an array of N integers. The task is to
 * find the smallest positive integer number missing from the 
 * array. 
 */

int missingNumber(int arr[], int n) {
    // let's first sort the array
    sort(arr, arr+n);

    int curr = 1;
    for(int i = 0; i<n; i++) {
        if(arr[i] <= curr) {
            if(arr[i] != curr) continue;
            if(arr[i] == curr) {
                curr += 1;
            }
        } else {
            return curr;
        }
    }
    return max(arr[n-1] + 1, 1);
}

/////////////////////////////////////////////////////////////////////
void solve() {
    // code here
    int n = 0;
    cin >> n;

    int arr[n];
    for(auto &x: arr) cin >> x;

    cout << missingNumber(arr, n) << endl;
}

// driver's code
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 0;
    cin >> t;

    while(t--) solve();
    return 0;
}