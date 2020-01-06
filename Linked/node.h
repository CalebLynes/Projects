//node.h
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "student.h"
using namespace std;

class Node {
 public:
  Node(Student* newstudent);
  ~Node();
  Node* getNext();
  Student* getStudent();
  void setNext(Node* newnext);
 private:
  Student* student;
  Node* next;
};

#endif