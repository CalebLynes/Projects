//student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student {
 public:
  Student(int newid);
  ~Student();
  int getId();
 private:
  int id;
};

#endif
