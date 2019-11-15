#include <iostream>
#include "room.h"

using namespace std;

//constructor
Room::Room(char newdescription[50]) {
  strcpy(description, newdescription);
  //exits = new map<char[], Room>;
}

/*//define an exit from this room
void Room::setExit(char direction[10], Room neighbor) {
  exits.insert(pair<char[], Room>(direction, neighbor));
}
*/
//print short description of room
void Room::printShortDescription() {
  cout << description;
}

void Room::printLongDescription() {
  cout << "You are " << description << "." << endl;
  printExits();
}

//print exits for a room
void Room::printExits() {
  cout << "Exits: " << endl;
  //for (int i = 0; i < exits.size(); i++) {
  //  cout << exits[i]->first << endl;
  //}
  cout << endl;
  //printRoomItems();
}

/*//prints items in the room
void Room:: printRoomItems() {
  cout << "Items in room: " << endl;
  for (int i = 0; i < items.size(); i++) {
    cout << items[i].getDescription() << endl;
  }
}
*/
