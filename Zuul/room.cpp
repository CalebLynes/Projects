//room.cpp
#include <iostream>
#include "room.h"
#include "item.h"

using namespace std;

/*
    This class is to hold all of the room functions
*/

//constructor
Room::Room(char newdescription[50]) {
  strcpy(description, newdescription);
  exits = new map<char*, Room*>;
  items = new vector<Item*>;
}

//---setExit:   make an exit from this room
void Room::setExit(char direction[10], Room* neighbor) {
  exits->insert(pair<char*, Room*>(direction, neighbor));
}

//---printShortDescription:   print short description of room
void Room::printShortDescription() {
  cout << "You are in " << description << endl;
}

//---printLongDescription:   prints long description of the room (description, exits, items)
void Room::printLongDescription() {
  printShortDescription();
  printExits();
  printItems();
}

//---printExits:   print exits for a room
void Room::printExits() {
  cout << "Exits: " << endl;
  cout << "\tDIRECTION:\tROOM:" << endl;
  map<char*, Room*>::iterator it;
  for (it = exits->begin(); it != exits->end(); it++) {
    cout << "\t  " << it->first << "\t"
	 << "\t  " << it->second->description << endl;
  }
  cout << endl;
}

//---printItems:   print all items in current room
void Room::printItems() {
    cout << "Items in room: " << endl;
    int size = items->size();
    if (size == 0) {
        cout << "No items to see here." << endl << endl;
    }
    else {
        for (int i = 0; i < size; i++) {
            cout << " - " << (*items)[i]->name << endl;
        }
        cout << endl;
    }
}

//---getExit:   get exit at specified direction
Room* Room::getExit(char direction[10]) {
  map<char*, Room*>::iterator it = exits->find(direction);
  if (it != exits->end()) {
    return it->second;
  }
  return NULL;
}

//---setItem:   set an item in the room
void Room::setItem(Item* newitem) {
  items->push_back(newitem);
}
