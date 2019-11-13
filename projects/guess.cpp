#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

int main() {

  //variables
  char input;
  int guess, num, count;
  bool win;
  bool keepGoing = true;

  //while loop for restarting game
  while (keepGoing == true) {
    win = false;
    count = 0;
    //initialize random seed
    srand(time(NULL));
    //generate random number
    num = rand() % 100 + 1;
  
    cout << "Guess a number between 1 and 100:" << endl;

    //while the user hasn't guessed it yet
    while (win == false) {
      cin >> guess;
      //if the guess isn't correct, add to count and report whether the guess was too low or too high
      if (guess != num) {
	count++;
	if (guess < num) {
	  cout << "Too low" << endl;
	}
	else if (guess > num) {
	  cout << "Too high" << endl;
	}
      }
      else { //if guess is correct
	win = true;
	cout << "You Win!" << " Guesses: " << count << endl;
      }
    }
    //ask if user wants to continue
    cout << "Do you want to keep playing? y or n." << endl;
    cin >> input;
    if (input == 'n') {
      keepGoing = false;
    }
  }

  return 0;
}
