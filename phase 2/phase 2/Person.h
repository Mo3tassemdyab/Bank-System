#pragma once
#include <iostream>
#include <string>
#include "Validation.h"
using namespace std;

class Person
{
private:
	int id;
	string name;
	string password;
public:
	Person() {
		id = 0;
		name = "";
		password = "";
	}
	Person(int id, string name, string password) {
		setID(id);
		setName(name);
		setPassword(password);
	}
	//setter
	void setName(string name) {
		if (Validation::validatename(name))
			this->name = name;
		else cout << "Invalid name\n";
	}

	void setPassword(string passwrod) {
		if (Validation::validatepassword(passwrod)) {
			this->password = passwrod;
		}
		else {
			cout << "Invalid password\n";
		}
	}



	void setID(int id) {
		this->id = id;
	}
	//getter
	string getName() {
		return name;
	}
	string getPassword() {
		return password;
	}
	int getID() {
		return id;
	}
	//method
	void display() {
		cout << "ID : " << id << endl;
		cout << "Name : " << name << endl;
		cout << "Password : " << password << endl;
	}
};

