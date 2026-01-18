#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;
using std::string;


// construct without an input
Student::Student() : studentId(""), first(""), last(""), email(""), age(-1), numDays{0,0,0} {}

// If data is inputted
Student::Student(string studentId, string first, string last, string email,
        int age, int numDays[], degreeProgram degree)
{
    setStudentId(studentId);
    setFirstName(first);
    setLastName(last);
    setEmail(email);
    setAge(age);
    setNumDays(numDays);
    setDegreeProgram(degree);
}


// mutators 
void Student::setStudentId(string studentId) { this -> studentId = studentId; }
void Student::setFirstName(string first) { this -> first = first; }
void Student::setLastName(string last) { this -> last = last; }
void Student::setEmail(string email) { this -> email = email; }
void Student::setAge(int age) { this -> age = age; }
void Student::setNumDays(int numDays[]) {
    for (int i=0; i < AMT_DAYS; i++) {
        this -> numDays[i] = numDays[i];
    }
}
void Student::setDegreeProgram(degreeProgram degree) { this -> degree = degree; }


// getters
string Student::getStudentId() const { return studentId; }
string Student::getFirstName() const { return first; }
string Student::getLastName() const { return last; }
string Student::getEmail() const { return email; }
int Student::getAge() const { return age; }
const int* Student::getNumDays() const { return numDays; }
degreeProgram Student::getDegreeProgram() const { return degree; }


// print statement
void Student::Print() const {
    cout << getStudentId() << endl;
    cout << "First name is: " << getFirstName() << endl;
    cout << "Last name is: " << getLastName() << endl;
    cout << "Email address is: " << getEmail() << endl; 
    cout << "Age is: " << getAge() << endl;
    for (int i=0; i < AMT_DAYS; i++) {
        cout << numDays[i] << " " << endl; 
    }
    
    string degStr {};
    switch(getDegreeProgram()) {
        case degreeProgram::NETWORK: degStr = "NETWORK"; break;
        case degreeProgram::SECURITY: degStr = "SECURITY"; break;
        case degreeProgram::SOFTWARE: degStr = "SOFTWARE"; break;
    }

    cout << "Degree: " << degStr << endl;
}