// T.C. = O(3^n)

#include <iostream>
using namespace std;

int max(int n1, int n2, int n3){
	return n1>(n2>n3?n2:n3)?n1:(n2>n3?n2:n3) ;
}

int pieces(int n, int a, int b, int c){
	if(n == 0) return 0;
	if(n < 0) return -1;
	
	int res = max(pieces(n-a, a, b, c),
		      pieces(n-b, a, b, c),
		      pieces(n-c, a, b, c));

	if(res == -1) return -1;
	return res + 1;
}

int main(){
	// code here
	int n, a, b, c;
	cin >> n >> a >> b >> c;

	cout << pieces(n, a, b, c) << endl;
	return 0;
}
