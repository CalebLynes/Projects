//main.cpp
#include <iostream>
#include "student.h"
#include "node.h"
#include <cstring>

using namespace std;

int main() {
  //make students (shows student constructor)
  Student* student1 = new Student(1);
  Student* student2 = new Student(2);
  Student* student3 = new Student(3);

  //make list (shows node constructor and setNext)
  Node* node1 = new Node(student1);
  Node* node2 = new Node(student2);
  Node* node3 = new Node(student3);
  node1->setNext(node2);
  node2->setNext(node3);

  //print the next students' id
  //(shows use of getNext and getStudent)
  cout << "Student1's next: "
       << node1->getNext()->getStudent()->getId() << endl;
  cout << "Student2's next: "
       << node2->getNext()->getStudent()->getId() << endl;
  
  //delete student2 and update list
  //(shows deconstructor of both student and node)
  delete node2;
  node1->setNext(node3);
  cout << "Student1 next after list update: "
       << node1->getNext()->getStudent()->getId() << endl;
  
  return 0;
}
