#include <iostream>

int fun2(int n){
	if(n == 1){
		return 0;
	} else {
		return 1 + fun2(n/2);
	}
}

void fun(int n){
	if(n == 0){
		return ;
	} 
	fun(n-1);
	std::cout << n << std::endl;
	fun(n-1);
}

int main(){
	// code here
	fun(3);
	std::cout << fun2(16) << std::endl;
	return 0;
}
