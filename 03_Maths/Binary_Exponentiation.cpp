// Problem : Find a efficient solution to solve x^n

#include <iostream>

int binaryExp(int x, int n){ // T.C = O(logn)
  int res = 1;
  while(n > 0){
    if(n%2 != 0){
      res *= x;
    } x *= x;
    n /= 2;
  } return res;
}

int main(){
  // code here
  int t;
  std::cin >> t;
  while(t--){
    int x, n;
    std::cin >> x >> n;
    std::cout << binaryExp(x, n) << "\n";
  }
  return 0;
}