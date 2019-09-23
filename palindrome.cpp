#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
  
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

  len = strlen(str) - 1;
  int count2 = len;
  char str2[len];

  for (int i = 0; i <= len; i++) {
    str2[count2--] = str[i];
    //cout << str2 << endl;
  }
  str2[len+1] = '\0';
  cout << "str: " << str << endl;
  cout << "str2: " << str2 << endl;

  if (strcmp(str,str2) == 0) {
    cout << "This is a Palindrome!!" << endl;
  }
  else {
    cout << "This is not a Palindrome :(" << endl;
  }
  
  return 0;
}
