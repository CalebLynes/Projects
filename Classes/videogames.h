//Videogames.h
#include <iostream>
#include "media.h"

using namespace std;

class Vgames : public Media {
 public:
  char publisher[];
  char rating[];
  
  void hello();
  int getType();
};
