#ifndef ADMIN_H
#define ADMIN_H

#include "employee.h"
class Admin : public employee
{
public:
	Admin() : employee() {

	}
	Admin(int id, string name, string password, double salary) : employee(id, name, password, salary) {

	}

};

#endif // ADMIN_H
