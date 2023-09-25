// Problem : Print all prime numbers upto n (inclusive if n is prime)

#include <iostream>
#include <vector>

void Sieve_Not_Optimised(int n){
  std::vector <bool> isPrime(n+1, true);
  for(int i = 2; (i*i <= n); i++){
    if(isPrime[i]){
      for(int j = 2*i; j <= n; j = j+i){
        isPrime[j] = false;
      }
    }
  }
  for(int i = 2; i <= n; i++){
    if(isPrime[i]){
      std::cout << i << " ";
    }
  } std::cout << "\n";
}

void Optimized_Sieve(int n){                      // T.C = O(nloglogn) almost linear as O(n)
  std::vector <bool> isPrime(n+1, true);
  for(int i = 2; i<=n; i++){
    if(isPrime[i] = true){
      std::cout << i << " ";
      for(int j = i*i; j <= n; j = j+i){
        isPrime[i] = false;
      }
    }
  }
}

int main(){
  // code here
  int t; 
  std::cin >> t;
  while(t--){
    int n;
    std::cin >> n;
    Optimized_Sieve(n);
  }
  return 0;
}