#include <iostream>
#include <vector>

using namespace std;

//declare functions
void newStudent();
void printStudents();
void deleteStudent();

struct Student {
  char name[50];
  int id;
  float gpa;
};

//main
int main() {
  vector<Student> students;
  bool stillGoing = true;

  while (stillGoing == true) {
    cout << "Commands: NEW, PRINT, DELETE, QUIT" << endl;
    char input[10];
    cin.get(input,10);
    cin.get();
    
    cout << input << endl;
    
    stillGoing = false;
  }
  return 0;
}

void newStudent() {
  
}

void printStudents() {

}

void deleteStudent() {

}
