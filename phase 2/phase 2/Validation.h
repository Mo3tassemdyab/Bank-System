#pragma once
#include <iostream>
#include <string>
using namespace std;


class Validation
{
public:
	static bool validatename(string name) {
		if (!(name.size() >= 5 && name.size() <= 20)) {
			return false;
		}

		for (int i = 0; i < name.size(); i++) {
			if (!(name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'A' && name[i] <= 'Z')) {
				return false;
			}
		}
		return true;
	}




	static bool validatepassword(string password) {
		if (password.size() >= 8 && password.size() <= 20)
		{
			return true;
		}
		else
		{
			cout << "\nmin password size is 8 and max is 20" << endl;
			return false;
		}
	}


	static bool validateBalance(double balance) {
		if (balance < 1500) {
			return false;
		}
		return true;
	}
	static bool validateSalary(double salary) {
		if (salary < 5000) {
			
			return false;
		}
		return true;
	}
};

