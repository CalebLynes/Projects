#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include "item.h"
using namespace std;

class Room {
 public:
  Room(char newdescription[50]);
  char description[50];
  //map<char[], Room> exits;
  vector<Item*>* items = new vector<Item*>;
  //void setExit(char direction[10], Room neighbor);
  void printShortDescription();
  void printLongDescription();
  void printExits();
  //void printRoomItems();
};
