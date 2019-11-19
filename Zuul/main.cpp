//main.cpp
#include <iostream>
#include <cstring>
#include "room.h"
#include "item.h"

using namespace std;

void printHelp();
void printCommands(char validCommands[][10]);

int main() {
  cout << "Hello world." << endl;

  char validCommands[][10] = {
    "go", "quit", "help", "inventory", "get", "drop"
  };
  char word1[10];
  char word2[50];
  
  cout << "type 'help' if you need help with commands" << endl;
  cout << endl;
  char input[100];
  cin.get(input,100);
  cin.get();
  
  try {
    char* a = strtok(input, " ");
    strcpy(word1, a);
    a = strtok(NULL, " ");
    
      strcpy(word2, a);
  } catch (const exception& e) {
    strcpy(word1, input);
  }
  //word 1 and 2 separated
  if (strcmp(word1,"go")==0) {
    //go
    cout << word2 << endl;
  }
  if (strcmp(word1,"quit")==0) {
    //quit
  }
  if (strcmp(word1,"help")==0) {
    //help
    printHelp();
    printCommands(validCommands);
  }
  if (strcmp(word1,"inventory")==0) {
    //inventory
  }
  if (strcmp(word1,"get")==0) {
    //get
  }
  if (strcmp(word1,"drop")==0) {
    //drop
  }
  
  return 0;
}

void printHelp() {
  cout << "You are in Room 1" << endl;
  cout << "(objective)" << endl << endl;
}

void printCommands(char validCommands[][10]) {
  cout << "Commands: " << endl;
  for (int i = 0; i < 6; i++) {
    cout << validCommands[i] << endl;
  }
}

