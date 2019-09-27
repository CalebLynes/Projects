#include <iostream>

using namespace std;

void printBoard(int board[3][3], int BLANK, int X_MOVE, int O_MOVE);
bool checkWinX();
bool checkWinO();
bool checkTie();

int main() {
  int board[3][3];
  const int X_TURN = 0;
  const int O_TURN = 1;
  const int BLANK = 0;
  const int X_MOVE = 1;
  const int O_MOVE = 2;
  int o_wins = 0;
  int x_wins = 0;
  int ties = 0;
  int column;
  int row;
  
  bool stillPlaying = true;
  //while (stillPlaying == true) {
    printBoard(board, BLANK, X_MOVE, O_MOVE);
    //cout << board.length;
    //}
  
  return 0;
}

/* board visual:
    1 2 3
  1 _ _ _
  2 _ _ _
  3 _ _ _
 */

void printBoard(int board[3][3], int BLANK, int X_MOVE, int O_MOVE) {
  cout << "\t1\t2\t3" << endl;
  for (int row = 0; row < 3; row++) {
    cout << (char)('a'+row) + "\t";
    for (int column = 0; column < 3; column++) {
      if (board[row][column] == BLANK) {
	cout << " \t";
      }
      else if (board[row][column] == X_MOVE) {
	cout << "X\t";
      }
      else if (board[row][column] == O_MOVE) {
	cout << "O\t" << endl;
      }
    }
  }
  
}

bool checkWin(int player) {

  //check if theres 3 in a row anywhere on the board
  //of that players value
  
  return false;
}

bool checkTie() {

  //check if there is any blanks on the board. If so return false.
  //otherwise return true.
  
  return false;
}
