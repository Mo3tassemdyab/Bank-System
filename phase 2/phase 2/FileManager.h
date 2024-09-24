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
	void add_client(Client c)
	{
		Filehelper::save_client(c);
	}
	void add_employee(Employee e)
	{
		Filehelper::save_employee(e);
	}
	void add_admin(Admin a)
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
	void get_all_clients()
	{
		Filehelper::get_clients();
	}
	void get_all_employees()
	{
		Filehelper::get_employees();
	}
	void get_all_admins()
	{
		Filehelper::get_admins();
	}
	void remove_all_clients()
	{
		Filehelper::clear_file("Client.txt", "Clientlastid.txt");
		Filehelper::get_clients();
	}
	void remove_all_employees()
	{
		Filehelper::clear_file("Employee.txt", "Employeelastid.txt");
		Filehelper::get_employees();
	}
	void remove_all_admins()
	{
		Filehelper::clear_file("Admin.txt", "Adminlastid.txt");
		Filehelper::get_admins();
	}
};

