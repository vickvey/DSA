#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n = 0, k = 0;
    cin >> n >> k;

    vector<int> v;
    for(int i = 0; i<n; i++) {
        int temp = 0;
        cin >> temp;
        v.push_back(temp);
    }

    // implementation of sliding window
    if(n <= k) {
        cout << accumulate(v.begin(), v.end(), 0LL) << endl;
        return;
    }

    // now n > k
    int max_sum = accumulate(v.begin(), v.begin() + k, 0);
    int prev_sum = max_sum;
    for(int i = 1; i+k-1 < n; i++) {
        prev_sum = prev_sum - v[i-1] + v[i+k-1];
        max_sum = max(prev_sum, max_sum);
    }
    cout << max_sum << endl;
}

int main() {
    // code here
    int t = 0;
    cin >> t;

    while(t--) {
        solve();
    }
    return 0;
}