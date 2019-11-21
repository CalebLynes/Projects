#include <iostream>
#include "room.h"
#include "item.h"

using namespace std;

//constructor
Room::Room(char newdescription[50]) {
  strcpy(description, newdescription);
  exits = new map<char*, Room*>;
  items = new vector<Item*>;
}

//make an exit from this room
void Room::setExit(char direction[10], Room* neighbor) {
  exits->insert(pair<char*, Room*>(direction, neighbor));
}

//print short description of room
void Room::printShortDescription() {
  cout << "You are in " << description << endl;
}

//prints long description of the room (description, exits, items)
void Room::printLongDescription() {
  printShortDescription();
  printExits();
  printItems();
}

//print exits for a room
void Room::printExits() {
  cout << "Exits: " << endl;
  cout << "\tDIRECTION\tROOM" << endl;
  map<char*, Room*>::iterator it;
  for (it = exits->begin(); it != exits->end(); it++) {
    cout << "\t" << it->first << "\t"
	 << "\t" << it->second->description << endl;
  }
  cout << endl;
}

//print all items in current room
void Room::printItems() {
  cout << "Items in room: " << endl;
  for (int i = 0; i < items->size(); i++) {
    cout << " - " << (*items)[i]->name << endl;
  }
  cout << endl;
}

//get exit at specified direction
Room Room::getExit(char direction[10]) {
  map<char*, Room*>::iterator it = exits->find(direction);
  if (it != exits->end()) {
    return (*it->second);
  }
}

//Get item at specified index or name
Item Room::getItem(int i) {
  return *(*items)[i];
}
Item Room::getItem(char itemName[50]) {
  for (int i = 0; i < items->size(); i++) {
    if (strcmp((*items)[i]->name, itemName)==0) {
      return *(*items)[i];
    }
  }
  return NULL;
}

//Remove item from room
void Room::removeItem(char itemName[50]) {
  for (int i = 0; i < items->size(); i++) {
    if (strcmp((*items)[i]->name, itemName)==0) {
      //call destructor and delete item
      delete (*items)[i];
      items->erase(items->begin()+i);
    }
  }
}

//Set an item in the room
void Room::setItem(Item* newitem) {
  items->push_back(newitem);
}
