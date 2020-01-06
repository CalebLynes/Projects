//node.cpp
#include <iostream>
#include "node.h"

using namespace std;

Node::Node(Student* newstudent) {
  student = newstudent;
  next = NULL;
}

Node::~Node() {
  delete student;
  next = NULL;
}

Node* Node::getNext() {
  return next;
}

void Node::setNext(Node* newnext) {
  next = newnext;
}

Student* Node::getStudent() {
  return student;
}