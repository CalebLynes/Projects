#include <iostream>
#include "item.h"

using namespace std;

Item::Item(char newdescription[50]) {
  strcpy(description, newdescription);
}

void Item::getDescription(char temp[50]) {
  temp = description;
}
