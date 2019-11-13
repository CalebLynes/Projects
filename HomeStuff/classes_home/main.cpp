//main.cpp
#include <iostream>
#include "videogames.h"
#include <vector>
#include <cstring>

using namespace std;

void addMedia(vector<Media*>* media);
void searchMedia(vector<Media*>* media);
void deleteMedia(vector<Media*>* media);

int main() {
  cout << "Hello world." << endl;
  cout << "Commands: ADD, SEARCH, DELETE" << endl;
  /*
  Media* m = new Media();
  m->hello();

  Vgames* v = new Vgames();
  v->hello();
  */
  
  vector<Media*>* media = new vector<Media*>;
  
  char input[50];
  cin.get(input,50);
  cin.get();
  if (strcmp(input,"ADD") == 0) {
    //cout << "read ADD." << endl;
    addMedia(media);
  }
  if (strcmp(input,"SEARCH") == 0) {
    //cout << "read SEARCH." << endl;
  }
  if (strcmp(input,"DELETE") == 0) {
    //cout << "read DELETE." << endl;
  }
  cout << "media size after: " << media->size() << endl;
  /*for (int i = 0; i < media->size(); i++) {
    cout << (*media)[i]->hello() << endl;
    }*/
  
  return 0;
}

void addMedia(vector<Media*>* media) {
  cout << "What kind of media do you want to make? Videogame, Music, or Movie." << endl;
  
  char input[10];
  cin.get(input,10);
  cin.get();
  cout << input << endl;
  if (strcmp(input,"Videogame") == 0) {
    Vgames* vg = new Vgames();
    media->push_back(vg);
  }
  cout << "media size before: " << media->size() << endl;
}
