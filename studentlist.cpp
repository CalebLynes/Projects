#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

/*
  Author: Caleb Lynes
  Date: 10/18/19
  Student List: Student database that keeps track of added and deleted students.
  Uses structs, vectors. Allows user to add, delete, and print students, as well
  as quit the program.
 */


//Student structure
struct Student {
  char first_name[50];
  char last_name[50];
  int id;
  float gpa;
};


//declare functions
void addStudent(vector<Student*>* students);
void printStudents(vector<Student*>* students);
void deleteStudent(vector<Student*>* students, int id);

//main
int main() {
  //variables
  
  vector<Student*>* students = new vector<Student*>;
  bool stillGoing = true;

  
  while (stillGoing == true) {
    cout << "Commands: ADD, PRINT, DELETE, QUIT" << endl;
    //take in a command
    char input[10];
    cin.get(input,10);
    cin.get();
    cout << "" << endl;
    
    //add student
    if (strcmp(input,"ADD") == 0) {
      addStudent(students);
    }
    
    //quit program
    else if (strcmp(input,"QUIT") == 0){
      stillGoing = false;
    }
    
    //print students
    else if (strcmp(input,"PRINT") == 0){
      printStudents(students);
    }
    
    //delete student
    else if (strcmp(input,"DELETE") == 0){
      int id;
      cout << "Enter the id of the student you want to delete: ";
      cin >> id;
      cin.get();
      deleteStudent(students, id);
    }
    
    //garbage input
    else {
      cout << "Enter a valid command!" << endl;
    }
    cout << "" << endl;

    //(testing)
    //printStudents(students);
    //stillGoing = false;
  }
  return 0;
}

//add student function
void addStudent(vector<Student*>* students) {
  //take in first and last names, id, and gpa and assign them to a struct
  //and then to the students vector.
  Student* s = new Student;
  cout << "Enter a first name: ";
  cin.get(s->first_name,50);
  cin.get();

  cout << "Enter a last name: ";
  cin.get(s->last_name,50);
  cin.get();

  cout << "Enter an id: ";
  cin >> s->id;
  cin.get();
  
  cout << "Enter a gpa: ";
  cin >> s->gpa;
  cin.get();
  
  (*students).push_back(s);
  cout << "Student added!" << endl;
}

//prints out all students
void printStudents(vector<Student*>* students) {
  cout << "Student Count: " << students->size() << endl;
  cout << "Students: " << endl;
  for (int i = 0; i < students->size(); i++) {
    cout << (*students)[i]->first_name << " " << (*students)[i]->last_name <<
      ", " << (*students)[i]->id << ", ";
    cout << fixed;
    cout << setprecision(2);
    cout << (*students)[i]->gpa << endl;
  }
}

//deletes specified student
void deleteStudent(vector<Student*>* students, int id) {
  for (int i = 0; i < students->size(); i++) {
    if ((*students)[i]->id == id) {
      delete ((*students)[i]);
      students->erase(students->begin()+i);
      cout << "Student deleted." << endl;
      return;
    }
  }
  cout << "Student not found." << endl;
}
