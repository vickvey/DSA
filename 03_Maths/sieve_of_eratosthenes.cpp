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

// Explanation of Sieve of Eratosthenes
/**
 * @title Sieve of Eratosthenes
 * @details 
 * 1. Create a list of consecutive integers from 2 to n: (2, 3, 4, ..., n).
 * 2. Initially, let p equal 2, the smallest prime number.
 * 3. Enumerate the multiples of p by counting in increments of p from 2p to n, and mark them 
 *    in the list (these will be 2p, 3p, 4p, ...; the p itself should not be marked).
 * 4. Find the first number greater than p in the list that is not marked. If there was no such
 *    number, stop. Otherwise, let p now equal this new number (which is the next prime), and
 *    repeat from step 3.
 * 5. When the algorithm terminates, the numbers remaining not marked in the list are all the
 *    primes below n.
 * 
 * The main idea here is that every value of p we choose, we mark all multiples of p as
 * composite (not prime). This way, when we iterate through all values of p, we will only
 * be left with prime numbers.
 * 
 * The algorithm can be improved further by observing that all primes are of the form 6k ± 1,
 * with the exception of 2 and 3. This is because all integers can be expressed as (6k + i)
 * for some integer k and for i = −1, 0, 1, 2, 3, or 4; 2 divides (6k + 0), (6k + 2), (6k + 4);
 * and 3 divides (6k + 3). So a more efficient method is to test if n is divisible by 2 or 3,
 * then to check through all the numbers of form 6k ± 1.
 * 
 */