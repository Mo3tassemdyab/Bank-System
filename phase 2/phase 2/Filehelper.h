#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parserr.h"
using namespace std;


class Filehelper
{
public:
	static void save_last_id(string s, int id)
	{
		fstream f(s, ios::out);
		f << id << endl;
		f.close();
	}
	static int get_last_id(string s)
	{
		int x;
		fstream f(s, ios::in);
		f >> x;
		f.close();
		return x;
	}
	static void save_client(Client c)
	{
		int x;
		x = get_last_id("Clientlastid.txt");
		x++;
		save_last_id("Clientlastid.txt", x);
		fstream f1("Client.txt", ios::app);
		f1 << x << "~" << c.getName() << "~" << c.getPassword() << "~" << c.getBalance() << "~" << endl;
		f1.close();

	}
	static void save_employee(Employee e)
	{
		int x;
		x = get_last_id("Employeelastid.txt");
		x++;
		save_last_id("Employeelastid.txt", x);
		fstream f("Employee.txt", ios::app);
		f << x << "~" << e.getName() << "~" << e.getPassword() << "~" << e.get_salary() << "~" << endl;
		f.close();

	}
	static void get_clients()
	{
		string s;
		fstream f("Client.txt", ios::in);
		while (getline(f, s))
		{
			m1.push_back(Parserr::parse_to_client(s));
		}
		f.close();
	}
	static void get_employees()
	{
		string s;
		fstream f("Employee.txt", ios::in);
		while (getline(f, s))
		{
			m2.push_back(Parserr::parse_to_employee(s));
		}
		f.close();
	}
	static void get_admins()
	{
		string s;
		fstream f("Admin.txt", ios::in);
		while (getline(f, s))
		{
			m3.push_back(Parserr::parse_to_admin(s));
		}
		f.close();
	}
	static void clear_file(string s1, string s2)
	{
		fstream f(s1, ios::out);
		f.close();
		fstream f2(s2, ios::out);
		f2 << 0;
		f2.close();
	}

};

