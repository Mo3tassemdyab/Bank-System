#pragma once
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;


class Employee :public Person
{
private:

    double salary = NULL;
public:
    Employee() : Person() {
        salary = 0;
    }
    Employee(int id, string name, string password, double salary) :Person(id, name, password) {
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

