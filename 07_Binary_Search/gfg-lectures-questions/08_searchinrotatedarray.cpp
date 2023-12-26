#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
#define max(x, y) (x > y ? x : y)
#define min(x, y) (x < y ? x : y)
/////////////////////////////////////////////////////////////////////

// code here

int binarySearch(int arr[], int x, int lo, int hi) {
    if(lo > hi) return -1;
    int mid = lo + (hi - lo)/2;
    if(arr[mid] == x) return mid;
    if(arr[mid] > x) return binarySearch(arr, x, lo, mid-1);
    return binarySearch(arr, x, mid + 1, hi);
}

int searchInRotatedArray(int x, int lo, int hi, int n, int arr[]) {
    if(lo > hi) return -1;
    int mid = lo + (hi - lo)/2;
    if(arr[mid] == x) return mid;
    if(arr[mid] > x) {
        if(arr[0] == x) return 0;
        if(arr[0] < x) return searchInRotatedArray(x, lo, mid-1, n, arr);
        return searchInRotatedArray(x, mid + 1, hi, n, arr);
    } else {
        if(arr[n-1] == x) return n-1;
        if(arr[n-1] > x) return searchInRotatedArray(x, mid+1, hi, n, arr);
        return searchInRotatedArray(x, lo, hi-1, n, arr);
    }
    return -1;
}

int search_short_implementation(int x, int n, int arr[]) {
    int lo = 0;
    int hi = n-1;
    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        if(arr[mid] == x) return mid;

        if(arr[lo] <= arr[mid]) {
            if(x >= arr[lo] && x < arr[mid]) hi = mid - 1;
            else lo = mid + 1;
        } else {
            if(x > arr[mid] && x <= arr[hi]) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    return -1;
}

/////////////////////////////////////////////////////////////////////
void solve() {
    // code here
    int n = 0, x = 0;
    cin >> n >> x;

    int arr[n];
    for(auto &x: arr) cin >> x;

    // cout << searchInRotatedArray(x, 0, n-1, n, arr) << endl;
    cout << search_short_implementation(x, n, arr) << endl;
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