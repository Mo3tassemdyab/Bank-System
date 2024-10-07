#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
using namespace std;


class Client :public Person
{
private:
	double balance = 0;
public:
	Client() : Person() {
		balance = 0;
	}
	Client(string name, string password, double balance) : Person( name, password) {
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
		Person::display();
		cout << "Balance: " << balance << endl;
	}
};

vector <Client>m1;