#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
#include"Filehelper.h"
#include<vector>
#include<iterator>

using namespace std;



class Admin:public Employee
{
public:
	Admin() : Employee() {

	}
	Admin(int id, string name, string password, double salary) : Employee(id, name, password, salary) {

	}
	void addClient(Client& client)
	{
		allClients.push_back(client);
	}
	Client* searchClient(int id)
	{
		for (auto it = allClients.begin(); it != allClients.end(); it++) {
			if (it->getID() == id) {
				return it._Ptr;
			}
		}
		return NULL;
	}
	void listCLient() {
		for (auto it = allClients.begin(); it != allClients.end(); it++) {
			it->display();
			cout << "------------------------\n";
			}
	}
	void editClient(int id, string name, string password, double balance) {
		searchClient(id)->setName(name);
		searchClient(id)->setPassword(password);
		searchClient(id)->setBalance(balance);
	}
	void addEmployee(Employee& employee)
	{
		allEmployees.push_back(employee);
	}
	Employee* searchEmployee(int id)
	{
		for (auto it = allEmployees.begin(); it != allEmployees.end(); it++) {
			if (it->getID() == id) {
				return it._Ptr;
			}
		}
		return NULL;
	}
	void listEmployee() {
		for (auto it = allEmployees.begin(); it != allEmployees.end(); it++) {
			it->display();
			cout << "------------------------\n";
		}
	}
	void editClient(int id, string name, string password, double salary) {
		searchEmployee(id)->setName(name);
		searchEmployee(id)->setPassword(password);
		searchEmployee(id)->setSalary(salary);
	}
};

