//videogames.h
#include <iostream>
#include "media.h"

using namespace std;

class Vgames : public Media {
 public:
  char publisher[0];
  char rating[0];

  void hello();
  int getType();
  int getYear();
};
