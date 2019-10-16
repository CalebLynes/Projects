#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

//Student structure
struct Student {
  char first_name[50];
  char last_name[50];
  int id;
  float gpa;
};


//declare functions
void newStudent(vector<Student> &students);
void printStudents(vector<Student> students);
void deleteStudent(vector<Student> &students, int id);

//main
int main() {
  vector<Student> students;
  bool stillGoing = true;
  
  cout << "students size: " << students.size() << endl;

  
  while (stillGoing == true) {
    cout << "Commands: NEW, PRINT, DELETE, QUIT" << endl;
    char input[10];
    cout << input << endl;
    cin.get(input,10);
    cin.get();

    if (input[0] == 'N' &&
	input[1] == 'E' &&
	input[2] == 'W') {
      //cout << "read NEW." << endl;
      newStudent(students);
    }
    else if (input[0] == 'Q' &&
	     input[1] == 'U' &&
	     input[2] == 'I' &&
	     input[3] == 'T'){
      //cout << "read QUIT." << endl;
      stillGoing = false;
    }
    else if (input[0] == 'P' &&
	     input[1] == 'R' &&
	     input[2] == 'I' &&
	     input[3] == 'N' &&
	     input[4] == 'T'){
      //cout << "read PRINT." << endl;
      printStudents(students);
    }
    else if (input[0] == 'D' &&
	     input[1] == 'E' &&
	     input[2] == 'L' &&
	     input[3] == 'E' &&
	     input[4] == 'T' &&
	     input[5] == 'E'){
      //cout << "read DELETE." << endl;
      int id;
      cout << "Enter the id of the student you want to delete: ";
      cin >> id;
      deleteStudent(students, id);
    }
    else {
      cout << "Error reading input" << endl;
      stillGoing = false;
    }
    
    //printStudents(students);
    //stillGoing = false;
  }
  return 0;
}

void newStudent(vector<Student> &students) {
  Student s;
  cout << "Enter a first name: ";
  cin.get(s.first_name,50);
  cin.get();

  cout << "Enter a last name: ";
  cin.get(s.last_name,50);
  cin.get();

  cout << "Enter an id: ";
  cin >> s.id;

  cout << "Enter a gpa: ";
  cin >> s.gpa;
  
  students.push_back(s);
  cout << "Student added!" << endl;
}

void printStudents(vector<Student> students) {
  cout << "Students: " << students.size() << endl;
  for (int i = 0; i < students.size(); i++) {
    cout << students.at(i).first_name <<  ", " << students.at(i).id << ", " << students.at(i).gpa << endl;
  }
}

void deleteStudent(vector<Student> &students, int id) {
  cout << id << endl;
}
