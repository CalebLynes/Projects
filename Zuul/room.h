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
  map<char*, Room*>* exits;
  vector<Item*>* items;
  
  void setExit(char direction[10], Room* neighbor);
  void printShortDescription();
  void printLongDescription();
  void printExits();
  void printItems();
  Room getExit(char direction[10]);
  Item getItem(int i);
  Item getItem(char itemName[50]);
  void removeItem(char itemName[50]);
  void setItem(Item* newitem);
};
