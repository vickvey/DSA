#include <bits/stdc++.h>
using namespace std;

void print7 (int n) {
    for(int i = 0; i<n; i++){
        //space
        for (int j = 0; j<n-i-1; j++){
            cout<<" ";
        }
        //stars
        for(int j = 0; j<2*i+1; j++){
            cout<<"*";
        }
        //space
        for (int j = 0; j<n-i-1; j++){
            cout<<" ";
        }
        cout<<endl; //next row
    }
}
void print8 (int n) {
    for(int i = 0; i<n; i++){
        //space
        for(int j = 0; j<i; j++){
            cout<<" ";
        }
        //stars
        for(int j = 0; j<(2*(n-i-1)-1); j++){
            cout<<"*";
        }
        //space 
        for(int j = 0; j<i; j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
void print9 (int n) {
    for(int i = 0; i<n; i++){
        //space
        for (int j = 0; j<n-i-1; j++){
            cout<<" ";
        }
        //stars
        for(int j = 0; j<i+1; j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
        for(int i = 0; i<n; i++){
        //space
        for(int j = 0; j<i; j++){
            cout<<" ";
        }
        //stars
        for(int j = 0; j<n-i; j++){
            cout<<"*"<<" ";
        }
        
        cout<<endl;
    }
}
void print10 (int n) {
    for (int i = 0; i<n; i++){
        for(int j = 0; j<=i; j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    for (int i = 1; i<n; i++){
        for(int j = n-i-1; j>=0; j--){
            cout<<"*"<<" ";
        } cout<<endl;
    }
}
void print11 (int n) {
    bool start = true;
    for(int i = 0; i<n; i++){
        if (i%2 == 0){
            start = true;
        } else {start = false;};
        for (int j = 0; j<=i; j++){
            if(j%2 == 0){
                cout<<start<<" ";
            } else {
                cout<<(!start)<<" ";
            }
        } cout<<endl;
    }
}
void print12 (int n) {
    for (int i = 1; i<=n; i++){
        //number
        for (int j = 1; j<=i; j++){
            cout<<j;
        }
        //space 
        for (int j = 1; j<=2*(n-i); j++){
            cout<<" ";
        }
        //numbers 
        for (int j = i; j>=1; j--){
            cout<<j;
            
        }
        cout<<endl;
    }
}
void print13 (int n) {
    // code here
    int start = 1;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<=i; j++){
            cout<<start<<" ";
            start++;
        } cout<<endl;
    }
}
void print14 (int n) {
// code here
    for (int i = 0; i<n; i++){
        char start = 'A';
        for (int j = 0; j<=i; j++){
            cout<<start;
            start = (char)(start+1);
        } cout<<endl;
    }
}
void print15 (int n) {
    for (int i = 0; i<n; i++){
    char start = 'A';
    for (int j = n-i-1; j>=0; j--){
        cout<<start;
        start = (char)(start+1);
    } cout<<endl;
}
}
void print16 (int n) {
            char start = 'A';
        for (int i = 0; i<n; i++){
            for (int j = 0; j<=i; j++){
                cout<<start;
            }
            start = (char)(start+1);
            cout<<endl;
        }
}
void print17 (int n) {
    for (int i = 0; i<n; i++){
        char start = 'A';
        //spaces
        for (int j = 0; j<n-i-1; j++){
            cout<<" ";
        }
        //characters
        for (int j = 0; j<2*i+1; j++){
            if (j<i){
                cout<<start;
                start = (char)(start+1);
            } else {
                cout<<start;
                start = (char)(start-1);
            }
        } cout<<endl;
    }
}
void print18 (int n) {
    for (int i = 0; i<n; i++){
        char start = (char)('A' + n);
        for (int j = 0; j<=i; j++) {
            cout<<start;
            start = (char)(start-1);
        } cout<<endl;
    }
}
void print19 (int n) {
    for (int i = 0; i<n; i++){
            //stars
            for (int j = n-i-1; j>=0; j--){
                cout<<"*";
            }
            //space
            for (int j = 0; j<2*i; j++){
                cout<<" ";
            }
            //stars
            for (int j = n-i-1; j>=0; j--){
                cout<<"*";
            } cout<<endl;
        } 
    for (int i = 0; i<n; i++){
        //stars
        for (int j = 0; j<=i; j++){
            cout<<"*";
        }
        //space 
        for (int j = (2*n)-(2*(i+1)); j>0; j--){
            cout<<" ";
        }
        //stars
        for (int j = 0; j<=i; j++){
            cout<<"*";
        } cout<<endl;
    }
}
void print20 (int n) {
    for (int i = 0; i<n; i++){
            //stars
            for (int j = 0; j<=i; j++){
                cout<<"*";
            }
            //space
            for (int j = 2*n-2*(i+1)-1; j>=0; j--){
                cout<<" ";
            }
            //stars
            for (int j = 0; j<=i; j++){
                cout<<"*";
            } cout<<endl;
        }
        for (int i = 1; i<n; i++){
            //stars
            for (int j = n-i-1; j>=0; j--){
                cout<<"*";
            }
            //space 
            for (int j = 0; j<2*i; j++){
                cout<<" ";
            }
            //stars
            for (int j = n-i-1; j>=0; j--){
                cout<<"*";
            } cout<<endl;
        }
}
void print21 (int n) {
    for (int i = 0; i<n; i++){
            if (i == 0 || i == n-1){
                for (int j = 0; j<n; j++){
                    cout<<"*";
                } cout<<endl;
            } else {
                for (int j = 0; j<n; j++){
                    if (j == 0 || j == n-1){
                        cout<<"*";
                    } else {
                        cout<<" ";
                    }
                } cout<<endl;
            }
        }
}
void print22 (int n) {
    for (int i = 0; i<2*n-1; i++){
        for (int j = 0; j<2*n-1; j++){
            int top = i;
            int left = j;
            int right = 2*n-2-j; 
            int down = 2*n-2-i;
            int ans = n - min(min(top,down),min(left,right));
            cout<<ans<<" ";
        } cout<<endl;
    }
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        print22(n);
    }
    return 0;
}