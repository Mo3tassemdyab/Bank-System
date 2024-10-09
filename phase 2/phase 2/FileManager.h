#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "DataSourceInterface.h"
#include "Filehelper.h"
using namespace std;


class FileManager :public DataSourceInterface
{
public:
	static void add_client(Client c)
	{
		Filehelper::save_client(c);
	}
	static void add_employee(Employee e)
	{
		Filehelper::save_employee(e);
	}
	static void add_admin(Admin a)
	{
		if (Filehelper::get_last_id("Adminlastid.txt") == 1)
		{
			cout << "their is a stored admin data already" << endl;
			return;
		}
		Filehelper::save_last_id("Adminlastid.txt", 1);
		fstream f("Admin.txt", ios::out);
		f << 1 << "~" << a.getName() << "~" << a.getPassword() << "~" << a.get_salary() << "~" << endl;
		f.close();

	}
	static void get_all_clients()
	{
		Filehelper::get_clients();
	}
	static void get_all_employees()
	{
		Filehelper::get_employees();
	}
	static void get_all_admins()
	{
		Filehelper::get_admins();
	}
	static void remove_all_clients()
	{
		Filehelper::clear_file("Client.txt", "Clientlastid.txt");
		Filehelper::get_clients();
	}
	static void remove_all_employees()
	{
		Filehelper::clear_file("Employee.txt", "Employeelastid.txt");
		Filehelper::get_employees();
	}
	static void remove_all_admins()
	{
		Filehelper::clear_file("Admin.txt", "Adminlastid.txt");
		Filehelper::get_admins();
	}
	static void get_all_data()
	{
		get_all_clients();
		get_all_employees();
		get_all_admins();
	}
	static void update_all_clients()
	{
		remove_all_clients();
		for (int i = 0; i < m1.size(); i++)
		{
			add_client(m1[i]);
		}
	}
	static void update_all_employees()
	{
		remove_all_employees();
		for (int i = 0; i < m2.size(); i++)
		{
			add_employee(m2[i]);
		}
	}
	static void update_all_admins()
	{
		remove_all_admins();
		for (int i = 0; i < m3.size(); i++)
		{
			add_admin(m3[i]);
		}
	}
	
};

