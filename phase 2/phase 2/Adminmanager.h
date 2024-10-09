#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Admin.h"
#include "Employee.h"
#include "Clientmanager.h"
using namespace std;

class Adminmanager
{
public:
	static void print_admin_menu()
	{
		cout << "1- Display my info\n";
		cout << "2- Update Password\n";
		cout << "3- Add new client\n";
		cout << "4- Search for a client\n";
		cout << "5- Edit client info\n";
		cout << "6- List all clients\n";
		cout << "7- Add new employee\n";
		cout << "8- Search for an employee\n";
		cout << "9- Edit employee info\n";
		cout << "10- List all employees\n";
		cout << "11- Logout\n\n";
	}
	static Admin* login(int id, string password)
	{
		if (m3[0].getID() != id || m3[0].getPassword() != password)
		{
			return NULL;
		}
		return &m3[0];
	}
	static void new_client(Admin* a)
	{
		string name, password;
		double balance;
		cout << "Enter Name: ";
		cin >> name;
		while (!(Validation::validatename(name)))
		{
			system("cls");
			cout << "Name must be alphabetic and min size is 5 and max size is 20!\n\n";
			cout << "Enter Name: ";
			cin >> name;
		}
		while (true)
		{
			cout << "\nEnter Password: ";
			cin >> password;
			if (password.size() >= 8 && password.size() <= 20)
			{
				break;
			}
			system("cls");
			cout << "Invalid Password!\nMinimum password size is 8 and Maximum size is 20 characters.\n";
		}
		while (true)
		{
			cout << "\nEnter Balance: ";
			cin >> balance;
			if (Validation::validateBalance(balance))
			{
				break;
			}
			system("cls");
			cout << "Minimum balance is 1500!\n";
		}
		Client c(name, password, balance);
		int x = Filehelper::get_last_id("Clientlastid.txt");
		x++;
		c.setID(x);
		a->add_client(c);
		FileManager::update_all_clients();
		cout << "\nNew client added Successfully!\n\n";
		system("pause");
	}
	static void search_for_client(Admin* a)
	{
		int id;
		cout << "Enter client id: ";
		cin >> id;
		Client* p = a->search_client(id);
		if (p != NULL)
		{
			cout << endl;
			p->display();
			cout << endl;
			system("pause");
		}
		else
		{
			cout << "\nThis client not found!\n\n";
			system("pause");
		}
	}
	static void edit_client_info(Admin* a)
	{
		int id;
		string name, password;
		double balance;
		cout << "Enter client id: ";
		cin >> id;
		Client* p = a->search_client(id);
		if (p == NULL)
		{
			cout << "\nThis client not found!\n\n";
			system("pause");
			return;
		}
		while (true)
		{
			cout << "\nEnter name: ";
			cin >> name;
			if (Validation::validatename(name))
			{
				p->setName(name);
				break;
			}
			system("cls");
			cout << "Name must be alphabetic and min size is 5 and max size is 20!\n";
		}
		while (true)
		{
			cout << "\nEnter Password: ";
			cin >> password;
			if (password.size() >= 8 && password.size() <= 20)
			{
				p->setPassword(password);
				break;
			}
			system("cls");
			cout << "Invalid Password!\nMinimum password size is 8 and Maximum size is 20 characters.\n";
		}
		while (true)
		{
			cout << "\nEnter Balance: ";
			cin >> balance;
			if (Validation::validateBalance(balance))
			{
				p->setBalance(balance);
				break;
			}
			system("cls");
			cout << "Minimum balance is 1500!\n";
		}
		FileManager::update_all_clients();
		cout << "\nClient info updated successfully!\n\n";
		system("pause");
	}
	static void list_all_clients(Admin* a)
	{
		cout << "All Clients:\n\n";
		a->list_clients();
		cout << endl;
		system("pause");
	}
	static void new_employee(Admin* a)
	{
		string name, password;
		double salary;
		cout << "Enter Name: ";
		cin >> name;
		while (!(Validation::validatename(name)))
		{
			system("cls");
			cout << "Name must be alphabetic and min size is 5 and max size is 20!\n\n";
			cout << "Enter Name: ";
			cin >> name;
		}
		while (true)
		{
			cout << "\nEnter Password: ";
			cin >> password;
			if (password.size() >= 8 && password.size() <= 20)
			{
				break;
			}
			system("cls");
			cout << "Invalid Password!\nMinimum password size is 8 and Maximum size is 20 characters.\n";
		}
		while (true)
		{
			cout << "\nEnter Salary: ";
			cin >> salary;
			if (Validation::validateSalary(salary))
			{
				break;
			}
			system("cls");
			cout << "Minimum salary is 5000!\n";
		}
		Employee e(name, password, salary);
		int x = Filehelper::get_last_id("Employeelastid.txt");
		x++;
		e.setID(x);
		a->add_employee(e);
		FileManager::update_all_employees();
		cout << "\nNew employee added Successfully!\n\n";
		system("pause");
	}
	static void search_for_employee(Admin* a)
	{
		int id;
		cout << "Enter employee id: ";
		cin >> id;
		Employee* p = a->search_employee(id);
		if (p != NULL)
		{
			cout << endl;
			p->display();
			cout << endl;
			system("pause");
		}
		else
		{
			cout << "\nThis employee not found!\n\n";
			system("pause");
		}
	}
	static void edit_employee_info(Admin* a)
	{
		int id;
		string name, password;
		double salary;
		cout << "Enter employee id: ";
		cin >> id;
		Employee* p = a->search_employee(id);
		if (p == NULL)
		{
			cout << "\nThis employee not found!\n\n";
			system("pause");
			return;
		}
		while (true)
		{
			cout << "\nEnter name: ";
			cin >> name;
			if (Validation::validatename(name))
			{
				p->setName(name);
				break;
			}
			system("cls");
			cout << "Name must be alphabetic and min size is 5 and max size is 20!\n";
		}
		while (true)
		{
			cout << "\nEnter Password: ";
			cin >> password;
			if (password.size() >= 8 && password.size() <= 20)
			{
				p->setPassword(password);
				break;
			}
			system("cls");
			cout << "Invalid Password!\nMinimum password size is 8 and Maximum size is 20 characters.\n";
		}
		while (true)
		{
			cout << "\nEnter Salary: ";
			cin >> salary;
			if (Validation::validateSalary(salary))
			{
				p->setSalary(salary);
				break;
			}
			system("cls");
			cout << "Minimum salary is 5000!\n";
		}
		FileManager::update_all_employees();
		cout << "\nEmployee info updated successfully!\n\n";
		system("pause");
	}
	static void list_all_employees(Admin* a)
	{
		cout << "All Employees:\n\n";
		a->list_employees();
		cout << endl;
		system("pause");
	}
	static int admin_options(Admin* a)
	{
		int x;
		cout << "Choose option: ";
		cin >> x;
		system("cls");
		switch (x)
		{
		case 1:
			a->display();
			cout << endl;
			system("pause");
			break;
		case 2:
			Clientmanager::update_password(a);
			break;
		case 3:
			new_client(a);
			break;
		case 4:
			search_for_client(a);
			break;
		case 5:
			edit_client_info(a);
			break;
		case 6:
			list_all_clients(a);
			break;
		case 7:
			new_employee(a);
			break;
		case 8:
			search_for_employee(a);
			break;
		case 9:
			edit_employee_info(a);
			break;
		case 10:
			list_all_employees(a);
			break;
		case 11:
			return 2;
		default:
			return 0;

		}
		return 1;
	}

};

