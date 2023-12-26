#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
#define max(x, y) (x > y ? x : y)
#define min(x, y) (x < y ? x : y)
/////////////////////////////////////////////////////////////////////


// code here

int sq_root_floor(int x) {
    int lo = 1;
    int hi = x;
    int res = -1;
    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        int mSq = mid * mid;
        if(mSq == x) return mid;
        else if(mSq > x) hi = mid - 1;
        else {
            lo = mid + 1; 
            res = mid;
        }
    } 
    return res;
}


/////////////////////////////////////////////////////////////////////
void solve() {
    // code here
    int x = 0;
    cin >> x;

    cout << sq_root_floor(x) << endl;
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