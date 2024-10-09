#pragma once
#include <iostream>
#include <string>
#include "Clientmanager.h"
#include "Employeemanager.h"
#include "Adminmanager.h"
#include <Windows.h>
using namespace std;


class Screens
{
public:
	static void bankName() {
		cout << "\n\n\n\n\n\n\t\t    ##       ##   #######   ##      #######  ########    ####    ####   #######\n";
		cout << "\t\t    ##   #   ##   ##        ##      ##       ##    ##    ##  #  #  ##   ##\n";
		cout << "\t\t    ##  ###  ##   ######    ##      ##       ##    ##    ##   ##   ##   #######\n";
		cout << "\t\t    ## ## ## ##   ##        ##      ##       ##    ##    ##        ##   ##\n";
		cout << "\t\t    ###     ###   #######   ######  #######  ########    ##        ##   #######\n\n\n";


		cout << "\t\t ####    ####   ########  ########  ########      #######   ########  ####     ##  ##   ##      \n";
		cout << "\t\t ##  #  #  ##   ##    ##  ##    ##  ##    ##      ##    ##  ##    ##  ## ##    ##  ##  ##    \n";
		cout << "\t\t ##   ##   ##   ########  ########  ########      #######   ########  ##  ##   ##  ## #    \n";
		cout << "\t\t ##        ##   ##    ##  ##    ##  ##    ##      ##    ##  ##    ##  ##   ##  ##  ##  ##     \n";
		cout << "\t\t ##        ##   ##    ##  ##    ##  ##    ##      #######   ##    ##  ##    ####   ##   ##        \n";


	}

	static void login_options()
	{
		cout << "1- Admin\n";
		cout << "2- Employee\n";
		cout << "3- Client\n\n";
	}
	static int login_as()
	{
		int x;
		cout << "Login as: ";
		cin >> x;
		return x;
	}
	
	static void logout()
	{
		system("cls");
		login_options();
		int v;
		while (true)
		{
			v = login_as();
			if (v == 1 || v == 2 || v == 3)
			{
				break;
			}
			system("cls");
			login_options();
		}
		login_screen(v);
	}
	static void login_screen(int c)
	{
		if (c == 1)
		{
			system("cls");
			int id;
			string password;
			cout << "Enter id: ";
			cin >> id;
			cout << "\nEnter password: ";
			cin >> password;
			Admin* p = Adminmanager::login(id, password);
			while (p == NULL)
			{
				system("cls");
				cout << "Incorrect id or password!\n\n";
				cout << "Enter id: ";
				cin >> id;
				cout << "\nEnter password: ";
				cin >> password;
				p = Adminmanager::login(id, password);
			}
			while (true)
			{
				system("cls");
				Adminmanager::print_admin_menu();
				int x = Adminmanager::admin_options(p);
				if (x==2)
				{
					return;
				}
			}
			
		}
		else if (c == 2)
		{
			system("cls");
			int id;
			string password;
			cout << "Enter id: ";
			cin >> id;
			cout << "\nEnter password: ";
			cin >> password;
			Employee* p = Employeemanager::login(id, password);
			while (p == NULL)
			{
				system("cls");
				cout << "Incorrect id or password!\n\n";
				cout << "Enter id: ";
				cin >> id;
				cout << "\nEnter password: ";
				cin >> password;
				p = Employeemanager::login(id, password);
			}
			while (true)
			{
				system("cls");
				Employeemanager::print_employee_menu();
				int x = Employeemanager::employee_options(p);
				if (x == 2)
				{
					return;
				}
			}
			
		}
		else if (c == 3)
		{
			system("cls");
			int id;
			string password;
			cout << "Enter id: ";
			cin >> id;
			cout << "\nEnter password: ";
			cin >> password;
			Client* p = Clientmanager::Login(id, password);
			while (p == NULL)
			{
				system("cls");
				cout << "Incorrect id or password!\n\n";
				cout << "Enter id: ";
				cin >> id;
				cout << "\nEnter password: ";
				cin >> password;
				p = Clientmanager::Login(id, password);
			}
			while (true)
			{
				system("cls");
				Clientmanager::print_client_menu();
				int x = Clientmanager::client_options(p);
				if (x == 2)
				{
					return;
				}
			}
		}
	}
	static void run_app()
	{
		bankName();
		Sleep(7000);
		system("cls");
		FileManager::get_all_data();
		while (true)
		{
			login_options();
			int v;
			while (true)
			{
				v = login_as();
				if (v == 1 || v == 2 || v == 3)
				{
					break;
				}
				system("cls");
				login_options();
			}
			login_screen(v);
			logout();
			system("cls");
		}

	}
};

