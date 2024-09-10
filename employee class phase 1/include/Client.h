#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include "Validation.h"


using namespace std;

class Client
{
	private:
	int id;
	string name;
	string password;
	double balance;
public:
	Client() {
		balance = 0;
	}
	Client(int id, string name, string password, double balance) {
		this->id = id;
		this->name = name;
		this->password = password;
		this->id = id;
		setBalance(balance);
	}
	//setter
	void setBalance(double balance) {
		if (Validation::validateBalance(balance))
			this->balance = balance;
		else cout << "Invalid balance\n";
	}
	//getter
	double getBalance() {
		return balance;
	}
	//methods
	void deposit(double amount) {
		if (amount > 0)
			this->balance += amount;
	}
	void withdraw(double amount) {
		if (amount <= balance && amount > 0)
			this->balance -= amount;
	}
	void transferTo(double amount, Client& recipient) {
		withdraw(amount);
		recipient.deposit(amount);
	}
	void checkBalance() {
		cout << "Balance : " << balance << endl;
	}
	void display() {

		cout << "Id : " << id << endl;
		cout << "Name : " << name << endl;
		cout << "Password : " << password << endl;
		cout << "Balance : " << balance << endl;
	}
};

#endif // CLIENT_H
