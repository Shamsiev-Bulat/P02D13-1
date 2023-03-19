#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define HEIGHT 25
#define WIDTH 80


void init_board(int *board);
void print_board(int *board);
int count_neighbors(int i, int j, int *board);
void update_board(int *board);


int main() {
  int board[HEIGHT][WIDTH];
  init_board(board);
  while(1) {
    print_board(board);
    update_board(board);
    usleep(200000);
  }

  return 0;
}



void init_board(int *board) {
  int i, j;
  for(i = 0; i < HEIGHT; i++) {
    for(j = 0; j < WIDTH; j++) {
      board[i][j] = rand() % 2;
    }
  }
}

void print_board(int *board) {
  system("clear");
  int i, j;
  for(i = 0; i < HEIGHT; i++) {
    for(j = 0; j < WIDTH; j++) {
      printf("%c", board[i][j] ? '*' : '.');
    }
    printf("\n");
  }
}

int count_neighbors(int i, int j, int *board) {
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

void update_board(int *board) {
  int new_board[HEIGHT][WIDTH];
  int i, j;
  for(i = 0; i < HEIGHT; i++) {
    for(j = 0; j < WIDTH; j++) {
      int state = board[i][j];
      int neighbors = count_neighbors(i, j);
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

