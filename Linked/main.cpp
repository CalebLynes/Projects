//main.cpp
#include <iostream>
#include <iomanip>
#include "student.h"
#include "node.h"
using namespace std;

void add(Student* student, Node* current, Node* &head);
void print(Node* node, Node* head);
void del(int id, Node* node, Node* prev, Node* &head);
void average(Node* head);

int main() {
  Node* head = NULL;
  char sname[] = "Caleb Lynes";
  Student* student1 = new Student(123456, sname, 4.5);
  add(student1, head, head);
  
  while (true) {
    cout << "Commands: ADD, PRINT, DELETE, QUIT, AVERAGE" << endl;
    //take in a command
    char input[10];
    cin.get(input,10);
    cin.get();
    cout << endl;
    for (int i = 0; i < strlen(input); i++) {
      input[i] = toupper(input[i]);
    }
    
    //add
    if (strcmp(input,"ADD")==0) {
      char name[100];
      int id;
      float gpa;
      cout << "Enter a full name (first and last): " << endl;
      cin.get(name, 100);
      cin.get();
      cout << "Enter an id: " << endl;
      cin >> id;
      cin.get();
      cout << "Enter a gpa: " << endl;
      cin >> gpa;
      cin.get();
      Student* temp = new Student(id, name, gpa);
      add(temp, head, head);
      cout << "Student added!" << endl;
    }

    else if (strcmp(input,"QUIT")==0) {
      break;
    }
    
    else if (strcmp(input,"PRINT")==0) {
      print(head, head);
      cout << endl;
    }
    else if (strcmp(input,"DELETE")==0) {
        if (head != NULL) {
            cout << "Enter an id: " << endl;
            int id;
            cin >> id;
            cin.get();
            del(id, head, NULL, head);
        }
        else {
            cout << "List is empty" << endl;
        }
    }
    else if (strcmp(input,"AVERAGE")==0) {
        average(head);
    }
    else {
        cout << "Invalid command." << endl;
    }
  }
  return 0;
}

//---add student in order of id
void add(Student* student, Node* current, Node* &head) {
    int id = student->getId();
    if (head == NULL) {
        //list is empty
        head = new Node(student);
    }
    else {
        //list is not empty
        if (head->getNext() == NULL) {
            //list only has head in it
            if (head->getStudent()->getId() > id) {
                //heads id is bigger than ours
                //insert student at beginning of list
                head = new Node(student);
                head->setNext(current);
            }
            else {
                //head has lower id than ours
                //insert student at end of list
                head->setNext(new Node(student));
            }
        }
        else {
            //more than 1 node in list
	    if (head->getStudent()->getId() > id) {
                //heads id is bigger than ours
                //insert student at beginning of list
                head = new Node(student);
                head->setNext(current);
            }
            if (current->getNext() != NULL) {
                //not end of list
                if (current->getStudent()->getId() < id) {
                    //current is lower
                    if (current->getNext()->getStudent()->getId() > id) {
                        //currents next is higher
                        //insert inbetween
                        Node* temp = new Node(student);
                        Node* temp2 = current->getNext();
                        current->setNext(temp);
                        temp->setNext(temp2);
                    }
                    else {
                        //currents next is also lower
                        //retry with next
                        add(student, current->getNext(), head);
                    }
                }
		/*else {
		  //not at end of list,
		  //but current is greater than us.
		  //insert before 
		  }*/
            }
            else {
                //last item in list
                if (current->getStudent()->getId() < id) {
                    //all items in list are lower than current
                    //insert at end of list
                    current->setNext(new Node(student));
                }
            }
        }
    }
}
//---print list
void print(Node* node, Node* head) {
  //if current node = the start of list
  if (node == head) {
    cout << "Students:" << endl;
  }
  //if list is empty
  if (head == NULL) {
      cout << "Emptiness.." << endl;
      return;
  }
  //if current node != the end of list
  if (node != NULL) {
    cout << node->getStudent()->getName() << ", ";
    cout << node->getStudent()->getId() << ", ";
    cout << fixed << setprecision(2) 
         << node->getStudent()->getGpa() << endl;
    print(node->getNext(), head);
  }
}

//---delete student
void del(int id, Node* node, Node* prev, Node* &head) {
  //if node is null then we went through the 
  //whole list and never found a match
  if (node == NULL) {
      cout << "Student not found." << endl;
      return;
  }
  //if we found a match
  if (node->getStudent()->getId() == id) {
      //if the deleted node is the start of list
      if (prev == NULL) {
        //if list > 1
        if (node->getNext() != NULL) {
            head = node->getNext();
        }
        else {
            //There is only one thing in list
            head = NULL;
        }
        delete node;
        cout << endl << id << " Deleted." << endl;
      }
      //if the target node is the end of list
      else if (node->getNext() == NULL) {
          prev->setNext(NULL);
          delete node;
          cout << endl << id << " Deleted." << endl;
      }
      //if target node is not start or end of list
      else {
          prev->setNext(node->getNext());
          delete node;
          cout << endl << id << " Deleted." << endl;
      }
  }
  else {
    //Node not found. Go through list recursively using del()
    if (node != NULL) {
      cout << node->getNext() << endl;
      del(id, node->getNext(), node, head);
    }
  }
}

void average(Node* head) {
    float total = 0.00;
    int count = 0;
    if (head == NULL) {
        //list is empty
        cout << "List is empty" << endl;
        return;
    }
    else {
        //list is not empty
        Node* current = head;
        total += current->getStudent()->getGpa();
        count++;
        while (current->getNext() != NULL) {
            current = current->getNext();
            total += current->getStudent()->getGpa();
            count++;
        }
        cout << fixed << setprecision(2) << total/count << endl;
    }
}
