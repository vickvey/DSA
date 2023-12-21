#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
#define max(x, y) (x > y ? x : y)
#define min(x, y) (x < y ? x : y)
/////////////////////////////////////////////////////////////////////
// code here

int first_occ(int key, int n, const int arr[]) {
    int lo = 0;
    int hi = n-1;

    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        if (arr[mid] > key) hi = mid - 1;
        else if (arr[mid] < key) lo = mid + 1;

        else {
            if(mid == 0 || arr[mid-1] != arr[mid]) return mid;
            else hi = mid - 1;
        }
    }
    return -1;
}

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

int count_occ(int key, int n, const int arr[]) {
    int first_occurence = first_occ(key, n, arr);
    int last_occurence = last_occ(key, n, arr);
    return max(last_occurence-first_occurence+1, 0);
}

/////////////////////////////////////////////////////////////////////
void solve() {
    // code here
    int n = 0, key = 0;
    cin >> n >> key;

    int arr[n];
    for(auto& x: arr) cin >> x;

    cout << count_occ(key, n, arr) << endl;
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