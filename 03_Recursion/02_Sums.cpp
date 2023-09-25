#include <iostream>

// function to determine the sum of first n natural numbers using recursion
int SONN(int n, int k = 0){
	if(n == 0){
		return k;
	} return SONN(n-1, k+n);
}

int main(){
	// code here
	int sum1 = SONN(5);
	std::cout << sum1 << std::endl;
	return 0;
}

