//item.cpp
#include <iostream>
#include "item.h"

using namespace std;

//This class is for all of the item functions

Item::Item(char newname[50]) {
  strcpy(name, newname);
}
