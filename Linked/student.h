//student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>
using namespace std;

class Student {
 public:
  Student(int newid, char* newname, float newgpa);
  ~Student();
  int getId();
  char getName();
  float getGpa();
 private:
  int id;
  char name[100];
  float gpa;
};

#endif
