
// Contains implementation of lower bound and upper bound

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<long long>;

int lower_bound(const vll& v, int elem) {
    int lo = 0;
    int hi = v.size() - 1; 

    while(hi - lo > 1) {
        int mid = (lo + hi) / 2;

        if(v[mid] < elem) {
            lo = mid+1;
        } else {
            hi = mid;
        }
    }

    if(mid )
}

void solve() {
    // code here


}

// Driver program
int main() {
    // code here
    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }
    return 0;
}
