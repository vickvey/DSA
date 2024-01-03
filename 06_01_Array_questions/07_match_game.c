/*
  PROBLEM: Matchsticks game
  Two friends, A and B, are playing the game of matchsticks. In this game, 
  a group of N matchsticks is placed on the table. The players can pick
  any number of matchsticks from 1 to 4 (both inclusive) during their 
  chance. The player who takes the last match stick wins the game. 
  If A starts first, how many matchsticks should he pick on his 1st turn such
  that he is guaranteed to win the game or determine if it's impossible 
  for him to win. Return -1 if it's impossible for A to win the game, 
  else return the number of matchsticks should he pick on his 1st turn such 
  that he is guaranteed to win.

  Note : Consider both A and B play the game optimally.

  1 <= N <= 10^18
*/

#include <stdio.h>

int matchGame(long long N) {
  if((N-1)%5==0) {
    return 1;
  } 
  if((N-2)%5==0) {
    return 2;
  }
  if((N-3)%5==0) {
    return 3;
  }
  if((N-4)%5==0) {
    return 4;
  } return -1;
}

int main() {
  int n;
  scanf("%d", &n);


  return 0;
}
