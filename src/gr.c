#include <stdio.h>

int main (){
    int board[25][80];
    for(int i = 0; i < 25; i++) {
        printf("\n");
    for(int j = 0; j < 80; j++) {
      board[i][j] = 0;
      printf("%d", board[i][j]);
    }
  }
}