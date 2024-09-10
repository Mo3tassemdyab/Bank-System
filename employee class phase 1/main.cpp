#include <iostream>
#include <string>
#include <cctype>
#include <employee.h>
#include "Client.h"
#include "Validation.h"

using namespace std;


int main()
{


Client c1(123,"Moatasem", "asd123asd", 2500 );
employee e1;
e1.set_id(123);
e1.set_name("Abdo");
e1.display_info();


c1.display();
    return 0;
}
