#include <iostream>
#include <stdio.h>
#include <sstream>
#include "BoxOffice.h"
using namespace std;

int main()
{

    BoxOffice R1;
    R1.addTheater(19,"dory",4,6);
    R1.addTheater(255, "nemo", 5, 7);
    R1.showTheater(19);

    R1.showAllTheaters();
    R1.removeTheater(23);
    R1.removeTheater(19);
    R1.showAllTheaters();
//
//char seatLetter = 'A';
//
//            for(int i = 0; i < 5; i++)
//            {
//                printf("%c ", seatLetter);
//               cout << "" << endl;
//                seatLetter++;
//            }
//    int k = 5;
//    char a = 'a';
//
//    ostringstream str1;
//    ostringstream str2;
//
//    str1 << k;
//    str2 << a;
//
//    string nah1 = str2.str();
//
//    string nah = str1.str();
//    cout << nah1;
//    cout << nah;
//    cout << "" << endl;

//char rowRes1[4] = {'A','B', 'C','D'};
//cout << sizeof(rowRes1) << endl;
//cout << int(rowRes1[0] - 64);
//
//Theater t1(19,"dory", 4,6);
// cout << t1.availableSeatNum;
// cout << t1.getTheaterId();
// for(int row = 0; row < t1.getNumRows(); row++)
//    {
//        for(int col = 0; col < 5; col++)
//        {
//            cout << "\t" << col;
//       }
//    }

    return 0;
}
