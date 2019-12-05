#include <iostream>
#include "student.h"
#include "node.h"

using namespace std;

void add(Student* student, Node* &head);
void print(Node* node, Node* &head);

int main() {
  Node* head = NULL;
  Student* student1 = new Student(1);
  Student* student2 = new Student(2);
  Student* student3 = new Student(3);

  add(student1, head);
  print(head, head);
  add(student2, head);
  print(head, head);
  add(student3, head);
  print(head, head);
  
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
    cout << endl;
    cout << "list:";
  }
  //if current node != the end of list
  if (node != NULL) {
    cout << node->getStudent()->getId() << " ";
    print(node->getNext(), head);
  }
}
