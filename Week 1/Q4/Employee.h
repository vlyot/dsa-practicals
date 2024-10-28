#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string> // Include string header for std::string

using namespace std;

class Employee {
public:
    // Constructor
    Employee(string firstName, string lastName, int monthlySalary);

    // Getter methods
    string get_fName();
    string get_lName();
    int get_salary();

    // Setter method for salary
    void set_salary(int salary);
        // Setter methods
    void set_fName(string firstName);
    void set_lName(string lastName);

private:
    string firstName;
    string lastName;
    int monthlySalary;
};

#endif // EMPLOYEE_H
