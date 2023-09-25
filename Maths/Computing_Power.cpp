// Problem : Compute the x raised to the power n

#include <iostream>

int Power(int x, int n){ // T.C = Theta(logn)
  if(n == 0){
    return 1;
  }
  int temp = Power(x, n/2);
  temp = temp*temp;
  if(n % 2 == 0){
    return temp;
  } else {
    return temp*x;
  }
}

int main(){
  // code here
  int t;
  std::cin >> t;
  while(t--){
    int x,n;
    std::cin >> x >> n;
    std::cout << Power(x, n) << "\n";
  }
  return 0;
}