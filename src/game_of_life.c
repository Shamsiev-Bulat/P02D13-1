#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define HEIGHT 25
#define WIDTH 80

void init_board(int (*data)[WIDTH]);
void print(int (*board)[WIDTH]);
int count_neighbors(int i, int j, int (*board)[WIDTH]);
void update_board(int (*board)[WIDTH]) ;


<<<<<<< HEAD


int main() {
    int board[HEIGHT][WIDTH];
    init_board(board);
    FILE *drugoe=freopen("/dev/tty","r",stdin);
    if(drugoe==NULL) printf("Fatal");
 int n;
  scanf("%d", &n);
 while(1) {
   print(board);
   update_board(board);
        usleep(n);
 }
=======
void init_board(int **board);
void print_board(int **board);
int count_neighbors(int i, int j, int **board);
void update_board(int **board);


int main() {
  int **board;
  init_board(board);
  while(1) {
    print_board(board);
    update_board(board);
    usleep(200000);
  }
>>>>>>> Game_of_life_primtr

  return 0;
}



<<<<<<< HEAD

void init_board(int (*data)[WIDTH]) {
    char ch;
    for(int i = 0; i < HEIGHT; i++) {
    for(int j = 0; j < WIDTH; j++) {
        scanf("%c",&ch);
        if(ch=='*') data[i][j]=1;
        else if(ch=='.') data[i][j]=0;
        else --j;
    }
=======
void init_board(int **board) {
  int i, j;
  for(i = 0; i < HEIGHT; i++) {
    for(j = 0; j < WIDTH; j++) {
      board[i][j] = rand() % 2;
>>>>>>> Game_of_life_primtr
    }
}

<<<<<<< HEAD



void print(int (*board)[WIDTH]) {
=======
void print_board(int **board) {
>>>>>>> Game_of_life_primtr
  system("clear");
  for(int i = 0; i < HEIGHT; i++) {
    for(int j = 0; j < WIDTH; j++) {
      printf("%c", board[i][j] == 1 ? '*' : ' ');
    }
    printf("\n");
  }
}

<<<<<<< HEAD



int count_neighbors(int i, int j, int (*board)[WIDTH]) {
=======
int count_neighbors(int i, int j, int **board) {
>>>>>>> Game_of_life_primtr
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
      else{
          if(neighbor_x==HEIGHT) neighbor_x=0;
          if(neighbor_x==-1) neighbor_x=HEIGHT-1;
          if(neighbor_y==WIDTH) neighbor_y=0;
          if(neighbor_y==-1) neighbor_y=WIDTH-1;
          count += board[neighbor_x][neighbor_y];
      }
    }
  }
  return count;
}

<<<<<<< HEAD



void update_board(int (*board)[WIDTH]) {
=======
void update_board(int **board) {
>>>>>>> Game_of_life_primtr
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
