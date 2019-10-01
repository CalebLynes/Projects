#include <iostream>
#include <cstring>

using namespace std;

void printBoard(int board[][3], int BLANK, int X_MOVE, int O_MOVE);
void resetBoard(int board[][3]);
bool checkWinX();
bool checkWinO();
bool checkTie();

int main() {
  int board[3][3];

  int X_TURN = 0;
  int O_TURN = 1;
  int BLANK = 0;
  int X_MOVE = 1;
  int O_MOVE = 2;
  
  int o_wins = 0;
  int x_wins = 0;
  int ties = 0;

  bool stillPlaying = true;

  resetBoard(board);
  /* //check values on the board for testing
  for (int i=0;i<3;i++) {
    for (int j=0;j<3;j++) {
      cout << board[i][j] << endl;
    }
  }
  */
  while (stillPlaying == true) {
    printBoard(board, BLANK, X_MOVE, O_MOVE);
    char input[50];
    cout << "X's move: ";
    cin.get(input, 50);
    cin.get();
    cout << "You entered: " << input << endl;
    //check if the input was valid
    
    if (strlen(input) != 2) {
      cout << "Input a letter followed by a number." << endl;
    }
    else if (input[0] != 'a' &&
	     input[0] != 'b' &&
	     input[0] != 'c') {
      cout << "Row must be an a, b, or c." << endl;
    }
    else if (input[1] != '1' &&
	     input[1] != '2' &&
	     input[1] != '3') {
      cout << "Column must be a 1, 2, or 3." << endl;
    }
    else {
      //Input was valid!
      
    }
    
    stillPlaying = false;
  }
  
  return 0;
}

/* board visual:
    1 2 3
  1 _ _ _
  2 _ _ _
  3 _ _ _
 */

void printBoard(int board[][3], int BLANK, int X_MOVE, int O_MOVE) {
  cout << "\t1\t2\t3" << endl;
  for (int row = 0; row < 3; row++) {
    cout << (char)('a'+row) << "\t";
    for (int column = 0; column < 3; column++) {
      if (board[row][column] == BLANK) {
	cout << "_\t";
      }
      else if (board[row][column] == X_MOVE) {
	cout << "X\t";
      }
      else if (board[row][column] == O_MOVE) {
	cout << "O\t";
      }
    }
    cout << endl;
  }
  
}

void resetBoard(int board[][3]) {
  //initialize board
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = 0;
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
