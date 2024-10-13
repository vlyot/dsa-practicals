#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

int main() {
    // Create two Employee objects
    Employee e1("Joe", "Rauth", 8500);
    Employee e2("Kai", "Chong", 24000);

    // Display yearly salary for each employee
    cout << "Employee 1's Salary: " << e1.get_salary() * 12 << endl;
    cout << "Employee 2's Salary: " << e2.get_salary() * 12 << endl;

    // Give each employee a 10% raise using the setter method
    e1.set_salary(e1.get_salary() + (e1.get_salary() * 0.1));
    e2.set_salary(e2.get_salary() + (e2.get_salary() * 0.1));

    // Display yearly salary after the raise
    cout << "After 10% raise:" << endl;
    cout << "Employee 1's Salary: " << e1.get_salary() * 12 << endl;
    cout << "Employee 2's Salary: " << e2.get_salary() * 12 << endl;

    return 0;
}
