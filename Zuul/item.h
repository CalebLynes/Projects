//item.h
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>

using namespace std;

/*
    This class is the header for item.cpp
*/

class Item {
 public:
  Item(char newname[50]);
  char name[50];
};

#endif
