//media.h
#include <iostream>

using namespace std;

class Media {
 public:
  int year;
  char title[0];

  void hello();
  int getType();
  int getYear();
  void getTitle();
};
