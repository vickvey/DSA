#include <iostream>
#include <string>

bool isPalindrome(std::string &str, int start, int end){
	if(start >= end) return true;

	return (str[start] == str[end]) && isPalindrome(str, ++start, --end);
} // T.C. = O(n)
	

int main(){
	// code here
	std::string str;
	std::cin >> str;

	if(isPalindrome(str, 0, str.length()-1)){
		std::cout << "The given string " << str << " is a palindrome.\n" ;
	} else {
		std::cout << "The given string " << str << " is not a palindrome. \n" ;
	}
	return 0;
}
