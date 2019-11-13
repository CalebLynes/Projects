#include <iostream>
#include <cstring>

using namespace std;

/*
  This program is the game TicTacToe. If you really need a 
  description of tictactoe you have no childhood. Google it.
  Author: Caleb Lynes
  Date: 10/3/19
 */

void printBoard(int board[][3], int BLANK, int X_MOVE, int O_MOVE);
void resetBoard(int board[][3]);
bool checkWin(int player, int board[][3]);
bool checkTie(int board[][3], int BLANK);

int main() {
  //variables
  int board[3][3];

  int X_TURN = 0;
  int O_TURN = 1;
  int BLANK = 0;
  int X_MOVE = 1;
  int O_MOVE = 2;
  
  int o_wins = 0;
  int x_wins = 0;
  int ties = 0;
  int turn = X_TURN;

  bool stillPlaying = true;

  /* //check values on the board for testing
  for (int i=0;i<3;i++) {
    for (int j=0;j<3;j++) {
      cout << board[i][j] << endl;
    }
  }
  */
  while (stillPlaying == true) {
    turn = X_TURN;
    resetBoard(board);
    cout << "X's turn: " << endl;
    //while the game is ongoing
    while (checkWin(X_MOVE, board) == false &&
	   checkWin(O_MOVE, board) == false &&
	   checkTie(board, BLANK) == false) {
      //print the board and take user input
      printBoard(board, BLANK, X_MOVE, O_MOVE);
      char input[50];
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
	int row = input[0] - 'a';
	int column = input[1] - '1';
	//check if move is legal and update the board
	if (board[row][column] == BLANK) {
	  if (turn == X_TURN) {
	    board[row][column] = X_MOVE;
	    cout << "O's turn:" << endl;
	    turn = O_TURN;
	  }
	  else {
	    board[row][column] = O_MOVE;
	    cout << "X's turn:" << endl;
	    turn = X_TURN;
	  }
	}
	else { //if spot isn't a blank
	  cout << "Move not valid." << endl;
	}
      }
    }
    //game has ended, check to see who won and add points accordingly
    if (checkWin(X_MOVE, board) == true) {
      printBoard(board, BLANK, X_MOVE, O_MOVE);
      cout << "X wins!" << endl;
      x_wins++;
    }
    else if (checkWin(O_MOVE, board) == true) {
      printBoard(board, BLANK, X_MOVE, O_MOVE);
      cout << "O wins!";
      o_wins++;
    }
    else if (checkTie(board, BLANK) == true) {
      printBoard(board, BLANK, X_MOVE, O_MOVE);
      cout << "You tied!" << endl;
      ties++;
    }
    //print all wins and ties
    cout << "X Wins: " << x_wins << ". O Wins: " << o_wins << ". Ties: " << ties << "." << endl;

    //ask if still playing
    cout << "Keep playing? y or n" << endl;
    /*char inp;
    cin >> inp;
    if (inp = 'y') {
      
    }
    else {*/
    //stillPlaying = false;
      //}
  }
  
  return 0;
}

/* board visual:
    1 2 3
  1 _ _ _
  2 _ _ _
  3 _ _ _
 */

//prints the board
void printBoard(int board[][3], int BLANK, int X_MOVE, int O_MOVE) {
  cout << "\t1\t2\t3" << endl;
  for (int row = 0; row < 3; row++) {
    cout << (char)('a'+row) << "\t";
    for (int column = 0; column < 3; column++) {
      if (board[row][column] == BLANK) {
	cout << " \t";
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

//resets the board to all blanks
void resetBoard(int board[][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = 0;
    }
  }
}

//checks if the given player has won
bool checkWin(int player, int board[][3]) {

  //check if theres 3 in a row anywhere on the board of that players value

  //horizontal
  if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {
    return true;
  }
  if (board[1][0] == player && board[1][1] == player && board[1][2] == player) {
    return true;
  }
  if (board[2][0] == player && board[2][1] == player && board[2][2] == player) {
    return true;
  }
  //verticals
  if (board[0][0] == player && board[1][0] == player && board[2][0] == player) {
    return true;
  }
  if (board[0][1] == player && board[1][1] == player && board[2][1] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][2] == player && board[2][2] == player) {
    return true;
  }
  //diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[2][0] == player && board[1][1] == player && board[0][2] == player) {
    return true;
  }
  
  return false;
}

//check if there is a tie (if there are no blanks left)
bool checkTie(int board[][3], int BLANK) {
  //check if there is any blanks on the board. If so return false. otherwise return true.
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      if (board[row][column] == BLANK) {
	return false;
      }
    }
  }
  
  return false;
}
