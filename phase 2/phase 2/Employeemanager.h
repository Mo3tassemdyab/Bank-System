#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "FileManager.h"
#include "Validation.h"
#include "Clientmanager.h"
using namespace std;


class Employeemanager
{
public:
	static void print_employee_menu()
	{
		cout << "1- Display my info\n";
		cout << "2- Update Password\n";
		cout << "3- Add new client\n";
		cout << "4- Search for a client\n";
		cout << "5- Edit client info\n";
		cout << "6- List all clients\n";
		cout << "7- Logout\n\n";
	}
	static void new_client(Employee* e)
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
		e->add_client(c);
		FileManager::update_all_clients();
		cout << "\nNew client added Successfully!\n\n";
		system("pause");
	}
	static void list_all_clients(Employee* e)
	{
		cout << "All Clients:\n\n";
		e->list_clients();
		cout << endl;
		system("pause");
	}
	static void search_for_client(Employee* e)
	{
		int id;
		cout << "Enter client id: ";
		cin >> id;
		Client* p = e->search_client(id);
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
	static void edit_client_info(Employee* e)
	{
		int id;
		string name, password;
		double balance;
		cout << "Enter client id: ";
		cin >> id;
		Client* p = e->search_client(id);
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
	static Employee* login(int id, string password)
	{
		Admin a;
		Employee* p = a.search_employee(id);
		if (p == NULL || p->getPassword() != password)
		{
			return NULL;
		}
		return p;
	}
	static int employee_options(Employee* e)
	{
		int x;
		cout << "Choose option: ";
		cin >> x;
		system("cls");
		switch (x)
		{
		case 1:
			e->display();
			cout << endl;
			system("pause");
			break;
		case 2:
			Clientmanager::update_password(e);
			break;
		case 3:
			new_client(e);
			break;
		case 4:
			search_for_client(e);
			break;
		case 5:
			edit_client_info(e);
			break;
		case 6:
			list_all_clients(e);
			break;
		case 7:
			return 2;
		default:
			return 0;
		}
		return 1;
	}

};

