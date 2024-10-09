#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
using namespace std;

class Admin :public Person
{
private:
	double salary = 0.0;
public:
	Admin() :Person()
	{
		salary = 0;
	}
	Admin(string name, string password, double salary) :Person(name, password) {
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
		cout << "Salary: " << salary << endl;
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
		return NULL;
	}
	void list_clients()
	{
		for (int i = 0; i < m1.size(); i++)
		{
			m1[i].display();
			cout << "_______________________________________________________________________________________\n\n";
		}
	}
	void edit_client(int id, string name, string password, double balance)
	{
		Client* p = search_client(id);
		if (p != NULL)
		{
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
		else
		{
			cout << "this client id not found" << endl;
		}

	}
	void add_employee(Employee& e)
	{
		m2.push_back(e);
	}
	Employee* search_employee(int id)
	{
		Employee* p;
		for (int i = 0; i < m2.size(); i++)
		{
			if (m2[i].getID() == id)
			{
				p = &m2[i];
				return p;
			}
		}
		return NULL;
	}
	void edit_employee(int id, string name, string password, double salary)
	{
		
			Employee* p = search_employee(id);
			if (p != NULL)
			{
				p->setName(name);
				p->setPassword(password);
				p->setSalary(salary);
				fstream f("Employee.txt", ios::out);
				for (int i = 0; i < m2.size(); i++)
				{
					f << m2[i].getID() << "~" << m2[i].getName() << "~" << m2[i].getPassword() << "~" << m2[i].get_salary() << "~" << endl;
				}
				f.close();
			}
			else
			{
				cout << "this employee id not found" << endl;
			}
		
	}
	void list_employees()
	{
		for (int i = 0; i < m2.size(); i++)
		{
			m2[i].display();
			cout << "_______________________________________________________________________________________\n\n";
		}
	}

};

vector <Admin>m3;

