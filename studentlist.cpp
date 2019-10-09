#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

//Student structure
struct Student {
  char name[50];
  int id;
  float gpa;
};


//declare functions
void newStudent(vector<Student> students);
void printStudents(vector<Student> students);
void deleteStudent(vector<Student> students);

//main
int main() {
  vector<Student> students;
  bool stillGoing = true;

  Student caleb;
  caleb.name[0] = 'C';
  caleb.name[1] = 'a';
  caleb.name[2] = 'l';
  caleb.name[3] = 'e';
  caleb.name[4] = 'b';
  caleb.id = 555555;
  caleb.gpa = 5.0;
  
  students.push_back(caleb);
  cout << "students size: " << students.size() << endl;

  while (stillGoing == true) {
    cout << "Commands: NEW, PRINT, DELETE, QUIT" << endl;
    char input[10];
    cin.get(input,10);
    cin.get();

    if (input[0] == 'N' &&
	input[1] == 'E' &&
	input[2] == 'W') {
      cout << "read NEW." << endl;
    }
    else if (input[0] == 'Q' &&
	     input[1] == 'U' &&
	     input[2] == 'I' &&
	     input[3] == 'T'){
      cout << "read QUIT." << endl;
      stillGoing = false;
    }
    else if (input[0] == 'P' &&
	     input[1] == 'R' &&
	     input[2] == 'I' &&
	     input[3] == 'N' &&
	     input[4] == 'T'){
      cout << "read PRINT." << endl;
      printStudents(students);
    }
    else if (input[0] == 'D' &&
	     input[1] == 'E' &&
	     input[2] == 'L' &&
	     input[3] == 'E' &&
	     input[4] == 'T' &&
	     input[5] == 'E'){
      cout << "read DELETE." << endl;
    }
    
    //stillGoing = false;
  }
  return 0;
}

void newStudent(vector<Student> students) {
  students.push_back(new Student());
}

void printStudents(vector<Student> students) {
  for (int i = 0; i < students.size(); i++) {
    cout << students.at(i).name <<  ", " << students.at(i).id << endl;
  }
}

void deleteStudent(vector<Student> students) {

}
