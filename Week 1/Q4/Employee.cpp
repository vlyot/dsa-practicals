#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

// Constructor implementation
Employee::Employee(string firstName, string lastName, int monthlySalary) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->monthlySalary = monthlySalary;  // Set the correct monthly salary
}

// Getter for first name
string Employee::get_fName() {
    return firstName;
}

// Getter for last name
string Employee::get_lName() {
    return lastName;
}

// Getter for monthly salary
int Employee::get_salary() {
    return monthlySalary;
}

// Setter for monthly salary
void Employee::set_salary(int salary) {
    this->monthlySalary = salary;
}
