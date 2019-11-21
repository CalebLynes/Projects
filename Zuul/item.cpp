#include <iostream>
#include "item.h"

using namespace std;

Item::Item(char newname[50]) {
  strcpy(name, newname);
}
