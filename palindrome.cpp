#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

/*
This program takes in a cstring, removes all punctuation and spaces,
and returns whether the word is a palindrome (same forwards as backwards)
Author: Caleb Lynes (477934)
Date: 9/25/19
 */

int main() {

  //read in a cstring
  char str[80];
  cin.get(str, 80);
  cin.get();
  cout << "You entered: " << str << endl;

  //changes input to lowercase
  int len = strlen(str);
  for(int i=0;i<len;i++) {
    str[i] = tolower(str[i]);
  }
  //cout << "tolower: " << str << endl;

  //removes all punctuation and spaces
  int count = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] > 96 && str[i] < 123) {
      str[count++] = str[i];
    }
  }
  //makes rest of string null
  str[count] = '\0';
  //cout << "Removed punct: " << str << endl;

  //create backwards string
  len = strlen(str) - 1;
  int count2 = len;
  char str2[len];

  for (int i = 0; i <= len; i++) {
    str2[count2--] = str[i];
    //cout << str2 << endl;
  }
  str2[len+1] = '\0';
  cout << "Forwards: " << str << endl;
  cout << "Backwards: " << str2 << endl;

  //check and report whether string is a palindrome
  if (strcmp(str,str2) == 0) {
    cout << "Palindrome!! :D" << endl;
  }
  else {
    cout << "Not a Palindrome :(" << endl;
  }
  
  return 0;
}
