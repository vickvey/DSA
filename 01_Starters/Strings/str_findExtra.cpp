//the time complexity of this program is O(nlogn)
/*#include <bits/stdc++.h>
using namespace std;

char findExtra (string s1, string s2){
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    int i = 0;
    for (auto it = s1.begin(); it<=s1.end(); it++) {
        if ((*it)!=s2[i]) {
            return s2[i];
        } 
        i++;
    }
    return s2[s2.length()-1];
}

int main(){
    string s1,s2;
    cout<<"Enter both strings with a space between them: \n";
    cin>>s1>>s2;

    cout<<"the extra character is: ";
    cout<<findExtra(s1, s2)<<endl;
    return 0;
}
*/
//better solution using hashing
#include <bits/stdc++.h>
using namespace std;

char findExtra (string s1, string s2) {
    int count[256] = {0};
    for (char x: s2) {
        count[x]++;
    }
    for (char x: s1) {
        count[x]--;
    }
    for (int i=0; i<256; i++) {
        if (count[i]==1){
            return (char)i;
        }
    }
    return 0;
}

char findExtraByBitwise (const string &s1, const string &s2) {
    int n = s1.length();
    char res = '\0';
    for(int i=0; i<n; i++) {
        res = res^s1[i]^s2[i];
    }
    res = res^s2[n];
    return (char)res;
}

int main() {
    string s1, s2;
    cin>>s1>>s2;
    cout<<findExtraByBitwise(s1, s2)<<endl;
    return 0;
}