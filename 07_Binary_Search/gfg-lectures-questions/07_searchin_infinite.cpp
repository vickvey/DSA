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

int searchInInfiniteArray(int x, int arr[]) {
    if(arr[0] == x) return 0;
    int i = 1;
    while(arr[i] <= x) i = i*i;
    if(arr[i] == x) return i;
    return binarySearch(arr, x, i/2, i);
}

/////////////////////////////////////////////////////////////////////
void solve() {
    // code here
    int n = 0, x = 0;
    cin >> n >> x;

    int arr[n];
    for(auto &x: arr) cin >> x;

    cout << searchInInfiniteArray(x, arr) << endl;
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