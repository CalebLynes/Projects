//student.cpp
#include <iostream>
#include "student.h"

using namespace std;

Student::Student(int newid, char* newname, float newgpa) {
  id = newid;
  strcpy(name, newname);
  gpa = newgpa;
}

Student::~Student() {
  
}

int Student::getId() {
  return id;
}

char Student::getName() {
  return *name;
}

float Student::getGpa() {
  return gpa;
}
