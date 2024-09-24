#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Person.h"
#include "Client.h"
using namespace std;


class Employee :public Person
{
private:

    double salary = 0.0;
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
    void add_client(Client& c)
    {
        m1.push_back(c);
    }
    Client* search_client(int id)
    {
        Client* p;
        for (int i = 0; i < m1.size(); i++)
        {
            if (m1[i].getID() == id)
            {
                p = &m1[i];
                return p;
            }
        }
        throw 'n';
    }
    void list_clients()
    {
        for (int i = 0; i < m1.size(); i++)
        {
            m1[i].display();
            cout << "==============================================================" << endl;
        }
    }
    void edit_client(int id, string name, string password, double balance)
    {
        try
        {
            Client* p = search_client(id);
            p->setName(name);
            p->setPassword(password);
            p->setBalance(balance);
            fstream f("Client.txt", ios::out);
            for (int i = 0; i < m1.size(); i++)
            {
                f << m1[i].getID() << "~" << m1[i].getName() << "~" << m1[i].getPassword() << "~" << m1[i].getBalance() << "~" << endl;
            }
            f.close();
        }
        catch (char c)
        {
            cout << "this client not found" << endl;
        }
    }
};

vector <Employee>m2;