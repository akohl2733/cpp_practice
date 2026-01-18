#pragma once
#include "degree.h"
#include <iostream>
#include <string>
using std::string;


class Student {


public:

    // constructors
    Student(string studentId, string first, string last, string email,
        int age, int numDays[], degreeProgram degree);
    Student();

    // mutators
    void setStudentId(string studentId);
    void setFirstName(string first);
    void setLastName(string last);
    void setEmail(string email);
    void setAge(int age);
    void setNumDays(int numDays[]);
    void setDegreeProgram(degreeProgram degree);

    // getters
    string getStudentId() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmail() const;
    int getAge() const;
    const int* getNumDays() const;
    degreeProgram getDegreeProgram() const;

    void Print() const;

    const static int AMT_DAYS = 3;

protected:

    string studentId;
    string first;
    string last;
    string email;
    int age;
    int numDays[AMT_DAYS];
    degreeProgram degree;

};