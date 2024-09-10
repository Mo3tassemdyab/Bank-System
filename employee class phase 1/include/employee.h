#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class employee
{
private:
    int id;
    string name ,password;
    double salary = NULL;
public:

void set_id(int id)
{
    this->id = id;
}
void set_name(string name)
{
    bool check = true;
    for(int i=0;i<name.size();i++)
    {
        if(isalpha(name[i])==0)
        {
            check = false;
            break;
        }
    }
    if(name.size()>=5&&name.size()<=20&&check)
    {
        this->name = name;
    }
    else
    {
        cout<<"name must be alphabetic and min size is 5 and max size is 20"<<endl;
    }
}
void set_password(string password)
{
    if(password.size()>=8&&password.size()<=20)
    {
        this->password = password;
    }
    else
    {
        cout<<"min password size is 8 and max is 20"<<endl;
    }
}
void set_salary(double salary)
{
    if(salary>=5000.0)
    {
        this->salary = salary;
    }
    else
    {
        cout<<"minimum salary is 5000.0"<<endl;
    }
}

int get_id()
{
    return id;
}
string get_name()
{
    return name;
}
string get_password()
{
    return password;
}
double get_salary()
{
    return salary;
}
void display_info()
{
    cout<<"id: "<<id<<endl;
    cout<<"name: "<<name<<endl;
    cout<<"password: "<<password<<endl;
    cout<<"salary = "<<salary<<endl;
}

};

#endif // EMPLOYEE_H
