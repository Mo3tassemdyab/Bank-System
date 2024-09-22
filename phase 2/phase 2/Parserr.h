#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;

class Parserr
{
private:

public:
	static vector<string> split(string r)
	{
		stringstream z;
		string s1;
		vector <string>v1;
		z << r;
		while (getline(z, s1, '~'))
		{
			v1.push_back(s1);
		}
		return v1;
	}
	static Client parse_to_client(string k)
	{
		vector <string>v = split(k);
		Client c;
		c.setID(stoi(v[0]));
		c.setName(v[1]);
		c.setPassword(v[2]);
		c.setBalance(stod(v[3]));
		return c;
	}
	static Employee parse_to_employee(string k)
	{
		vector <string>v = split(k);
		Employee e;
		e.setID(stoi(v[0]));
		e.setName(v[1]);
		e.setPassword(v[2]);
		e.setSalary(stod(v[3]));
		return e;
	}
	static Admin parse_to_admin(string k)
	{
		vector <string>v = split(k);
		Admin a;
		a.setID(stoi(v[0]));
		a.setName(v[1]);
		a.setPassword(v[2]);
		a.setSalary(stod(v[3]));
		return a;
	}

};

