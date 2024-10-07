#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Validation.h"
#include <Windows.h>
#include "FileManager.h"
using namespace std;


class Clientmanager
{
public:
	static void print_client_menu()
	{
		cout << "1- Display my info" << endl;
		cout << "2- Check balance" << endl;
		cout << "3- Update Password" << endl;
		cout << "4- Withdraw" << endl;
		cout << "5- Deposit" << endl;
		cout << "6- Transfer amount" << endl;
		cout << "7- Logout" << endl;
	}
	static void update_password(Person *p)
	{
		string s;
		cout << "Enter Password: ";
		cin >> s;
		if (s.size() >= 8 && s.size() <= 20)
		{
			p->setPassword(s);
			FileManager::update_all_clients();
			FileManager::update_all_employees();
			cout << "\n\nPassword Updated Successfully!\n" << endl;
			system("pause");
		}
		else
		{
			system("cls");
			cout << "Invalid Password!\nMinimum password size is 8 and Maximum size is 20 characters.\n" << endl;
			update_password(p);
		}
	}
	static Client* Login(int id, string password)
	{
		Employee e;
		Client* p = e.search_client(id);
		if (p == NULL || p->getPassword() != password)
		{
			return NULL;
		}
		else
		{
			return p;
		}
	}
	static bool client_options(Client* p)
	{
		int x;
		cout << "Choose option: ";
		cin >> x;
		system("cls");
		switch (x)
		{
		case 1:

			p->display();
			cout << endl;
			system("pause");
			break;
		case 2:

			cout << "Balance: " << p->getBalance() << endl << endl;
			system("pause");
			break;
		case 3:

			update_password(p);
			break;
		case 4:

			double a;
			cout << "Enter amount: ";
			cin >> a;
			if (a <= p->getBalance() && a > 0)
			{
				p->withdraw(a);
				FileManager::update_all_clients();
				cout << "\n\nAmount Withdrawed Successfully!\n" << endl;
				system("pause");
			}
			else if (a <= 0)
			{
				cout << "\n\nInvalid Amount!\n" << endl;
				system("pause");
			}
			else
			{
				cout << "\n\nAmount Exceeded balance!\n" << endl;
				system("pause");
			}
			break;
		case 5:
			double d;
			cout << "Enter Amount: ";
			cin >> d;
			if (d > 0)
			{
				p->deposit(d);
				FileManager::update_all_clients();
				cout << "\n\nAmount added to balance Successfully!\n" << endl;
				system("pause");
			}
			else
			{
				cout << "\n\nInvalid Amount!\n" << endl;
				system("pause");
			}
			break;
		case 6:
			{
			int x;
			double s;
			cout << "Enter id of recipient: ";
			cin >> x;
			Employee e;
			Client* v = e.search_client(x);
			if (v == NULL)
			{
				cout << "\n\nThis recipient not found!\n\n";
				system("pause");
				break;
			}
			else {
				cout << "\nEnter amount to be transferred: ";
				cin >> s;

				if (s <= p->getBalance() && s > 0)
				{
					p->transferTo(s, *v);
					FileManager::update_all_clients();
					cout << "\n\nSuccessful Transaction!\n" << endl;
					system("pause");
				}
				else
				{
					cout << "\n\nInvalid Amount!\n" << endl;
					system("pause");
				}
				break;
			}
		}
		case 7:
			system("cls");
			break;
		default:
			return false;
		
		}
		return true;
	}

};

