#include <iostream>

void TOH (int n, char A, char B, char C){
  if(n == 1){
    printf("Move Disc %d from ( %c -> %c ) \n", n, A , C);
    return;
  }

  TOH(n-1, A, C, B);
  printf("Move Disc %d from ( %c -> %c ) \n", n, A , C);
  TOH(n-1, B, A, C);
}

int main(){
  // code here
  int n;
  printf("Enter the number of towers in A : ");
  std::cin >> n;

  printf("Here is your Solution.\nFollow these steps : \n");
  TOH(n, 'A', 'B', 'C');
  return 0;
}