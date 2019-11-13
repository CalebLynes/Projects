//videogames.cpp
#include <iostream>
#include "videogames.h"

using namespace std;

void Vgames::hello() {
  cout << "I am Vgames" << endl;
}

int Vgames::getType() {
  return 1;
}

int Vgames::getYear() {
  return year;
}
