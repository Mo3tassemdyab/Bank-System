#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Parserr.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Filehelper.h"
#include "FileManager.h"
#include "Clientmanager.h"
#include <Windows.h>
#include "Employeemanager.h"
using namespace std;

int main()
{
    int id;
    string password;
    FileManager::get_all_data();
    cout << "Enter id: ";
    cin >> id;                   //program to login as an employee, open employee file to get id and password
    cout << "\nEnter password: ";
    cin >> password;
    if (Employeemanager::login(id, password) != NULL)
    {
        while (true)
        {
            system("cls");
            Employeemanager::print_employee_menu();
            Employeemanager::employee_options(Employeemanager::login(id, password));
        }
    }
    else
    {
        system("cls");
        cout << "incorrect id or password!\n\n";
        system("pause");
    }
    
    
    
    
    
    /*FileManager::get_all_data();
    Client* c1 = &m1[2];
    while (true)
    {
        system("cls");
        Clientmanager::print_client_menu();
        cout << endl;
        Clientmanager::client_options(c1);
    }*/


    /*to open the client and employee text files to check them 
    right click on the project name then select open folder in file explorer.*/

    return 0;
   
}