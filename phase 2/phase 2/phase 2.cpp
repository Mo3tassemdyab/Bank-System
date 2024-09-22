#include <iostream>
#include <string>
#include <fstream>
#include "Parserr.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Filehelper.h"
using namespace std;

int main()
{
    Client c1(1, "Ahmed", "ahmed@2024", 7000);
    Filehelper::save_client(c1);
    Employee e1(1, "mohanad", "mohanad_2020", 9000);
    Filehelper::save_employee(e1);

    /*to open the client and employee text files to check them 
    right click on the project name then select open folder in file explorer.*/


    return 0;
}