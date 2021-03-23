#include <iostream>
#include <stdio.h>
#include "BoxOffice.h"
using namespace std;

int main()
{
    BoxOffice R1;
    R1.addTheater(19,"dory",4,6);
    R1.addTheater(255, "nemo", 5, 7);
    R1.showAllTheaters();
    R1.removeTheater(23);
    R1.removeTheater(19);
    R1.showAllTheaters();

    //AVAILABLE SEATS FUNCTION  IS FAULTY

    return 0;
}
