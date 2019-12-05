//main.cpp
#include <iostream>
#include "room.h"
#include "item.h"

using namespace std;

/*
    Zuul - Text based adventure game
    This class is the main class of the program and deals with game initiation and command processing.
    Author: Caleb Lynes
    Date: 11/--
*/

void printWelcome(Room* room);
void printHelp(Room* room);
void printCommands(char validCommands[][10]);

int main() {
    
    //Base game variable declarations
    vector<Item*>* inventory = new vector<Item*>;
    char validCommands[][10] = {
        "go", "quit", "help", "inventory", "get", "drop"
    };
    char word1[10];
    char word2[50];
    Room* currentRoom;
    char north[] = "North";
    char south[] = "South";
    char west[] = "West";
    char east[] = "East";
    
    //----GAME DECLARATIONS:----
    //Rooms
    char r1d[] = "Front Yard";
    Room* frontyard = new Room(r1d);
    char r2d[] = "Lounge";
    Room* lounge = new Room(r2d);
    char r3d[] = "Living Room";
    Room* living = new Room(r3d);
    char r4d[] = "Office";
    Room* office = new Room(r4d);
    char r5d[] = "Bedroom";
    Room* bedroom = new Room(r5d);
    char r6d[] = "Bathroom #1";
    Room* bath1 = new Room(r6d);
    char r7d[] = "Kitchen";
    Room* kitchen = new Room(r7d);
    char r8d[] = "Dining Room";
    Room* dining = new Room(r8d);
    char r9d[] = "Basement";
    Room* basement = new Room(r9d);
    char r10d[] = "Back Yard";
    Room* backyard = new Room(r10d);
    char r11d[] = "Shed";
    Room* shed = new Room(r11d);
    char r12d[] = "Bathroom #2";
    Room* bath2 = new Room(r12d);
    char r13d[] = "Mancave";
    Room* mancave = new Room(r13d);
    char r14d[] = "Storage Room";
    Room* storage = new Room(r14d);
    char r15d[] = "Garage";
    Room* garage = new Room(r15d);
    
    //Exits
    frontyard->setExit(south, lounge);
    
    lounge->setExit(north, frontyard);
    lounge->setExit(west, bedroom);
    lounge->setExit(east, living);
    lounge->setExit(south, kitchen);

    bedroom->setExit(east, lounge);
    bedroom->setExit(south, bath1);

    kitchen->setExit(north, lounge);
    kitchen->setExit(east, dining);
    kitchen->setExit(south, backyard);

    backyard->setExit(north, kitchen);
    backyard->setExit(west, shed);

    shed->setExit(east, backyard);

    bath1->setExit(north, bedroom);

    living->setExit(north, garage);
    living->setExit(west, lounge);
    living->setExit(east, office);
    living->setExit(south, dining);

    dining->setExit(north, living);
    dining->setExit(west, kitchen);
    dining->setExit(east, basement);

    office->setExit(west, living);

    basement->setExit(west, dining);
    basement->setExit(east, bath2);
    basement->setExit(south, mancave);

    mancave->setExit(north, basement);
    mancave->setExit(east, storage);

    storage->setExit(west, mancave);

    bath2->setExit(west, basement);

    garage->setExit(south, living);
    
    //Items
    char forkn[] = "fork";
    Item* fork = new Item(forkn);
    storage->setItem(fork);
    char platen[] = "plate";
    Item* plate = new Item(platen);
    living->setItem(plate);
    char knifen[] = "knife";
    Item* knife = new Item(knifen);
    mancave->setItem(knife);
    char bageln[] = "bagel";
    Item* bagel = new Item(bageln);
    bedroom->setItem(bagel);
    char buttern[] = "butter";
    Item* butter = new Item(buttern);
    kitchen->setItem(butter);


    
    currentRoom = lounge;
  
    //-----Start Game-----
    printWelcome(currentRoom);
    while (true) {
        cout << endl;
        char input[100];
        cin.get(input,100);
        cin.get();
        //check if input has two words
        int len = strlen(input);
        bool hasSecondWord = false;
        for (int i = 0; i < len; i++) {
            if (input[i] == ' ') {
                hasSecondWord = true;
            }
            input[i] = tolower(input[i]);
        }
        if (hasSecondWord == true) {
            //if so split them and perform actions of said command
            char* a = strtok(input, " ");
            strcpy(word1, a);
            a = strtok(NULL, " ");
            strcpy(word2, a);
            //-----COMMAND: GO-----
            if (strcmp(word1,"go")==0) {
                //Go to specified direction if it is valid
	        //north
	        if (strcmp(word2, "north")==0) {
                    cout << "Going North.." << endl;
                    currentRoom = currentRoom->getExit(north);
		    cout << "You are in ";
		    currentRoom->printShortDescription();
		    currentRoom->printExits();
		    currentRoom->printItems();
                }
		//south
                else if (strcmp(word2, "south")==0) {
                    cout << "Going South.." << endl;
                    currentRoom = currentRoom->getExit(south);
		    cout << "You are in ";
		    currentRoom->printShortDescription();
		    currentRoom->printExits();
		    currentRoom->printItems();
		}
		//west
                else if (strcmp(word2, "west")==0) {
                    cout << "Going West.." << endl;
                    currentRoom = currentRoom->getExit(west);
		    cout << "You are in ";
		    currentRoom->printShortDescription();
		    currentRoom->printExits();
		    currentRoom->printItems();
		}
		//east
                else if (strcmp(word2, "east")==0) {
                    cout << "Going East.." << endl;
                    currentRoom = currentRoom->getExit(east);
		    cout << "You are in ";
		    currentRoom->printShortDescription();
		    currentRoom->printExits();
		    currentRoom->printItems();
		}
                //input filter
                else {
                    cout << "Invalid direction. Type 'help' to see possible directions." << endl << endl;
                }
            }
            //-----COMMAND: GET-----
            else if (strcmp(word1,"get")==0) {
                //pick up item
                Item* item;
                int itemsSize = currentRoom->items->size();
                vector<Item*>* tempItems = currentRoom->items;
                int count = 0;
                for (int i = 0; i < itemsSize; i++) {
                    item = (*tempItems)[i];
                    if (strcmp(word2, item->name)==0) {
                        //Found a match!
                        inventory->push_back(item);
                        tempItems->erase(tempItems->begin()+i);
                        cout << "You picked up " << item->name << "." << endl;
                        count++;
                    }
                }
                if (count == 0) {
                    cout << "No match. (items are case sensitive)" << endl;
                }
            }
            //-----COMMAND: DROP-----
            else if (strcmp(word1,"drop")==0) {
                //drop item
                Item* item;
                int invSize = inventory->size();
                vector<Item*>* tempItems = currentRoom->items;
                int count = 0;
                for (int i = 0; i < invSize; i++) {
                    item = (*inventory)[i];
                    if (strcmp(word2, item->name)==0) {
                        //Found a match!
                        tempItems->push_back(item);
                        inventory->erase(inventory->begin()+i);
                        cout << "You dropped " << item->name << "." << endl;
                        count++;
                    }
                }
                if (count == 0) {
                    cout << "No match. (items are case sensitive)" << endl;
                }
            }
            //more input filter
            else {
                cout << "Invalid command. Type 'help' to see possible commands." << endl << endl;
            }
        }
        else {
            //Only one word inputs to deal with!
            //find out what command was entered and perform action
            //-----COMMAND: QUIT-----
            if (strcmp(input,"quit")==0) {
               //quit
               cout << "Terminating..." << endl;
               break;
            }
            //-----COMMAND: HELP-----
            else if (strcmp(input,"help")==0) {
              //help
	      printCommands(validCommands);
              printHelp(currentRoom);
            }
            //-----COMMAND: INVENTORY-----
            else if (strcmp(input,"inventory")==0) {
                //print out inventory
                cout << "Inventory: " << endl;
                int size = inventory->size();
                if (size == 0) {
                    cout << "Nothing to see here!" << endl;
                }
                else {
                    for (int i = 0; i < size; i++) {
                        cout << " - " << (*inventory)[i]->name << endl;
                    }
                }
                cout << endl;
            }
            //more and more input filter
            else {
                cout << "Invalid command. Type 'help' to see possible commands." << endl << endl;
            }
        }
        //winning condition
        if (dining->items->size() == 5) {
            cout << "Congratulations! You successfully buttered your bagel!" << endl;
	    cout << "Enjoy your now non-barren morning..." << endl;
            break;
        }
    }
    return 0;
}

//---printHelp: print where the user is and the objective
void printHelp(Room* room) {
  room->printShortDescription();
  room->printExits();
  room->printItems();
  cout << "Objective: Butter Your Bagel! you need to scrounge your house for your bagel eating needs."
       << "Find the misplaced plate, knife, fork, bagel, and butter and drop them to the dining room "
       << "to transform your extremely barren morning into a good one!"
       << endl << endl;
}

//---printCommands: print all commands
void printCommands(char validCommands[][10]) {
  cout << "Commands: " << endl;
  for (int i = 0; i < 6; i++) {
    cout << validCommands[i] << endl;
  }
  cout << endl;
}

//---printWelcome: print welcoming statement
void printWelcome(Room* room) {
  cout << "Welcome to Zuul!" << endl;
  cout << "Butter your bagel." << endl;
  cout << "Type 'help' to show commands, room, objective, exits, and items." << endl << endl;
}
