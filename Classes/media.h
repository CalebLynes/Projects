//Media.h
#include <iostream>

using namespace std;

class Media {
 public:
  int year;
  char title[];
  
  void hello();
  int getType();
  int getYear();
  void getTitle();
};
