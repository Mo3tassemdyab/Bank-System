#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include<string>
#include <cctype>

using namespace std;

class Admin {
private:
	int id;
	string name;
	string password;
	double salary;
public:
	Admin() : id(0), name("N/A"), password("N/A"), salary(0.0) {}
	Admin(int id, string name, string password, double salary) {
		this->id = id;
		this->name = name;
		this->password = password;
		this->salary = salary;
	}
	void setId(int id) {
		this->id = id;
	}
	void setName(string name) {
		bool alpha = true;
		for (int i = 0; i <= name.length()-1; i++)
		{
			if (!isalpha(name[i])) {
				alpha = false;
				cout << "\nThe name must contain only alphabetic characters.\n";
				return;
			}

		}
		if (alpha == true && name.size() >= 5 && name.size() <= 20) {
			this->name = name;
		}
		else {
			cout << "\nThe name must be between 5 and 20 characters long.\n";
		}
}

	void setpassword(string password) {
		if ( password.size() >= 8 && password.size() <= 20) {
			this->password = password;
		}
		else {
			cout << "\nThe password must be between 8 and 20 characters long.\n";
		}
	}
	void setSalary(double salary) {
		if (salary >= 5000) {
			this->salary = salary;
		}
		else
		{
			cout << "\nsalary must be greater than 5000\n";
		}
	}
	int getId() {
		return id;
	}
	string getName() {
		return name;
	}
	string getpassword() {
		return password;
	}
	double getSalary() {
		return salary;
	}
	void displayInfo()
	{
		cout << "\nAdmin Name : " << name << endl;
		cout << "\nAdmin id : " << id << endl;
		cout << "\nAdmin Password : " << password << endl;
		cout << "\nAdmin salary : " << salary << endl;
	}
};





#endif // ADMIN_H
