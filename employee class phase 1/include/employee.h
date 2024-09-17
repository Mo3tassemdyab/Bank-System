#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <cctype>
#include "Person.h"
using namespace std;

class employee: public Person
{
private:

    double salary = NULL;
public:
    employee() : Person() {
        salary = 0;
    }
    employee(int id, string name, string password, double salary):Person(id,name, password) {
        setSalary(salary);

    }



    void setSalary(double salary) {
        if (Validation::validateSalary(salary))
            this->salary = salary;
        else cout << "Invalid salary\n";
    }


    double get_salary()
    {
        return salary;
    }
    void display()
    {
        Person::display();
        cout << "salary = " << salary << endl;
    }



};

#endif // EMPLOYEE_H
