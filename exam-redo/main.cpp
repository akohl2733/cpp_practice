#include <iostream>
#include "student.h"
#include "degree.h"
using namespace std;

const int NUM_SDNT = 5;

int main() {


    int days[] = {10, 20, 20};

    Student* classRosterArray[NUM_SDNT];

    classRosterArray[0] = new Student(
        "101010101", 
        "Andrew", 
        "Kohl", 
        "akohl2733@gmail.com", 
        10, 
        days, 
        degreeProgram::SECURITY
    );

    classRosterArray[0]->Print();

    delete classRosterArray[0];

    return 0;
};
    
    