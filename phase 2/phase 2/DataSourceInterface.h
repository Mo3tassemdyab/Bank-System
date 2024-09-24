#pragma once
#include <iostream>
#include <string>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;


class DataSourceInterface
{
public:
	virtual void add_client(Client c) = 0;
	virtual void add_employee(Employee e) = 0;
	virtual void add_admin(Admin a) = 0;
	virtual void get_all_clients() = 0;
	virtual void get_all_employees() = 0;
	virtual void get_all_admins() = 0;
	virtual void remove_all_clients() = 0;
	virtual void remove_all_employees() = 0;
	virtual void remove_all_admins() = 0;

};

