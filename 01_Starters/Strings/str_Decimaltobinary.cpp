#include <bits/stdc++.h>
using namespace std;

string DecimalToBinary (int n) {
    string s = "";
    while (n>0){
        int rem = n%2;
        s = s + to_string(rem);
        n = n/2;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    int n;
    cin>>n;
    string s = DecimalToBinary(n);
    cout<<s<<endl;
    return 0;
}