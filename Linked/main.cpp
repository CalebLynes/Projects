//main.cpp
#include <iostream>
#include "student.h"
#include "node.h"
using namespace std;

void add(Student* student, Node* &head);
void print(Node* node, Node* &head);
void del(int id, Node* node, Node* prev, Node* &head);

int main() {
  Node* head = NULL;
  char sname[] = "Caleb Lynes";
  cout << sname << endl;
  Student* student1 = new Student(1, sname, 4.0);
  add(student1, head);
  cout << student1->getName() << endl;
  /*
  Student* student1 = new Student(1);
  Student* student2 = new Student(2);
  Student* student3 = new Student(3);
  
  add(student1, head);
  print(head, head);
  add(student2, head);
  print(head, head);
  add(student3, head);
  print(head, head);
  del(1, head, NULL, head);
  print(head, head);
  */
  while (true) {
    cout << "Commands: ADD, PRINT, DELETE, QUIT" << endl;
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
      add(temp, head);
      cout << "Student added!" << endl;
    }

    else if (strcmp(input,"QUIT")==0) {
      break;
    }
    
    else if (strcmp(input,"PRINT")==0) {
      print(head, head);
      cout << endl;
    }
  }
  return 0;
}
//---add student
void add(Student* student, Node* &head) {
  Node* current = head;
  //if the list is empty
  if (current == NULL) {
    head = new Node(student);
  }
  //list is not empty!
  else {
    //make our way to the end of the list
    while (current->getNext() != NULL) {
      current = current->getNext();
    }
    current->setNext(new Node(student));
  }
}
//---print list
void print(Node* node, Node* &head) {
  //if current node = the start of list
  if (node == head) {
    cout << "list:" << endl;
  }
  //if current node != the end of list
  if (node != NULL) {
    cout << "Name: " << node->getStudent()->getName() << "\t";
    cout << "Id: " << node->getStudent()->getId() << "\t";
    cout << "Gpa: " << node->getStudent()->getGpa() << endl;
    print(node->getNext(), head);
  }
}

//---delete student
void del(int id, Node* node, Node* prev, Node* &head) {
  if (node->getStudent()->getId() == id) {
      //safeguard for if the deleted node is the start of list
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
      //safeguard for if the target node is the end of list
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
      del(id, node->getNext(), node, head);
    }
  }
}
