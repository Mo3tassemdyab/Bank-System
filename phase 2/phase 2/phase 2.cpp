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
using namespace std;

int main()
{
    FileManager f;
    Employee e1(3,"yossef", "yossef441", 19000);
    Client c1(4, "tarek", "tarek%plus2", 14000);
    f.add_employee(e1);
    f.add_client(c1);
    
    /*to open the client and employee text files to check them 
    right click on the project name then select open folder in file explorer.*/


    return 0;
}