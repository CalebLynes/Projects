//Main class
#include <iostream>
#include "videogames.h"

using namespace std;

int main() {
  cout << "Hello world" << endl;
  Vgames vgames;
  vgames.hello();
  cout << vgames.getType() << endl;
  return 0;
}
