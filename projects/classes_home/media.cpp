//media.cpp
#include <iostream>
#include "media.h"

using namespace std;

void Media::hello() {
  cout << "I am media" << endl;
}

int Media::getType() {
  return 0;
}

int Media::getYear() {
  return year;
}
