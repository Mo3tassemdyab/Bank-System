#include <iostream>
#include <string>
#include "Validation.h"
#include "Employee.h"
#include "Person.h"
#include "Client.h"
#include "Admin.h"

using namespace std;

int main()
{

	employee e1;
	e1.setName("moatasem");
	e1.setPassword("moatasem123");
	e1.setSalary(1212321);
	e1.display();


	cout << "====================================\n";

	Client c1;
	c1.setName("mo");
	c1.setPassword("asd");
	c1.setBalance(232113);
	c1.display();


	cout << "====================================\n";

	Admin a1;
	a1.setName("mohamed");
	a1.setPassword("123456788");
	a1.setSalary(123);
	a1.display();
}
