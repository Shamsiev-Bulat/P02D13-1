#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define HEIGHT 25
#define WIDTH 80

void init_board(int ac, char *av[]);
void print(int (*board)[WIDTH]);
int count_neighbors(int i, int j, int (*board)[WIDTH]);
void update_board(int (*board)[WIDTH]) ;




int main(int ac, char *av[]) {
  init_board(ac,av);
    int board[HEIGHT][WIDTH];
    int n;
    scanf("%d", &n);
  while(1) {
    print(board);
    update_board(board);
          usleep(n);
  }

  return 0;
}




void init_board(int ac, char *av[]) {
    int data[HEIGHT][WIDTH];
    for(int i = 0; i < HEIGHT; i++) {
    for(int j = 0; j < WIDTH; j++) {
        FILE *fptr;
        fptr=fopen (av[ac-1],"r");
        fscanf(fptr,"%d",&data[i][j]);
        
    }
    }
}




void print(int (*board)[WIDTH]) {
  system("clear");
  for(int i = 0; i < HEIGHT; i++) {
    for(int j = 0; j < WIDTH; j++) {
      printf("%c", board[i][j] ? '*' : '.');
    }
    printf("\n");
  }
}




int count_neighbors(int i, int j, int (*board)[WIDTH]) {
  int count = 0;
  int x, y;

  for(x = -1; x <= 1; x++) {
    for(y = -1; y <= 1; y++) {
      if(x == 0 && y == 0) continue;
      int neighbor_x = i + x;
      int neighbor_y = j + y;
      if(neighbor_x >= 0 && neighbor_x < HEIGHT && neighbor_y >= 0 && neighbor_y < WIDTH) {
        count += board[neighbor_x][neighbor_y];
      }
    }
  }
  return count;
}




void update_board(int (*board)[WIDTH]) {
  int new_board[HEIGHT][WIDTH];
  int i, j;
  for(i = 0; i < HEIGHT; i++) {
    for(j = 0; j < WIDTH; j++) {
      int state = board[i][j];
      int neighbors = count_neighbors(i, j, board);
      if(state == 0 && neighbors == 3) {
        new_board[i][j] = 1;
      }
      else if(state == 1 && (neighbors < 2 || neighbors > 3)) {
        new_board[i][j] = 0;
      }
      else {
        new_board[i][j] = state;
      }
    }
  }
  for(i = 0; i < HEIGHT; i++) {
    for(j = 0; j < WIDTH; j++) {
      board[i][j] = new_board[i][j];
    }
  }
}

