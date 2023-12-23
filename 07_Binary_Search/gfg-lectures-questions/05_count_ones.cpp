#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
#define max(x, y) (x > y ? x : y)
#define min(x, y) (x < y ? x : y)
/////////////////////////////////////////////////////////////////////


// code here
int count_ones(int n, const vector<int>& arr) {
    int lo = 0;
    int hi = n-1;
    int res = -1;

    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        if(arr[mid] == 0) lo = mid + 1;
        else {
            if(mid == 0 || arr[mid-1] == 0) return n-mid;
            else hi = mid - 1;
        }
    }
    return 0;
}


/////////////////////////////////////////////////////////////////////
void solve() {
    // code here
    int n = 0;
    cin >> n;
    vector<int> arr(n, 0);
    for(auto& x: arr) cin >> x;

    cout << "The number of ones in the array are : " << count_ones(n, arr) << endl;
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