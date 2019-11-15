#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>

using namespace std;

class Item {
 public:
  Item(char newdescription[50]);
  void getDescription(char temp[50]);
  char description[50];
};

#endif
