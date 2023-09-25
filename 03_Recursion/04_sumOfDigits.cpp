#include <iostream>

// function to return sum of digits of an integer number
int digitSum (int n, int k = 0){
	if(n <= 9){
		return k + n;
	} k += n%10;
	return digitSum (n/10, k);
}

int main(){
	// code here
	int n;
	std::cout << "Enter the number for which you want the digitSum!\n" ;
	std::cin >> n;

	std::cout << "The sum of digits of " << n << " is : " ;
	std::cout << digitSum(n) << std::endl;
	return 0;
}
