#include <iostream>
//#include "Theater.h"
#include "BoxOffice.h"

using namespace std;

//CONSTRUCTOR
BoxOffice::BoxOffice(){
    tListSize = 0;
    resListSize = 0;
}

//DESTRUCTOR
BoxOffice::~BoxOffice(){
    delete[] theaterList;
    delete[] reservationList;
}

//COOY CONSTRUCTOR
BoxOffice::BoxOffice(const BoxOffice& boxOfficeToCopy)
{

    theaterList = new Theater[tListSize];
    reservationList = new Reservation[resListSize];

    for(int i = 0; i < tListSize; i ++)
    {
        theaterList[i] = boxOfficeToCopy.theaterList[i];
    }
    for(int i = 0; i < resListSize; i++)
    {
        reservationList[i] = boxOfficeToCopy.reservationList[i];
    }

    tListSize = boxOfficeToCopy.tListSize;
    resListSize = boxOfficeToCopy.resListSize;
}
//ASSIGNMENT OPERATOR
void BoxOffice::operator=(const BoxOffice &right)
{
    if(this == &right)
        cout << "Same BoxOffice." << endl; //self assignment
    //if(right != NULL)
    //{
        delete[] theaterList; //clean up
        delete[] reservationList; //clean up
    //}

    tListSize = right.tListSize;
    resListSize = right.resListSize;

    theaterList = new Theater[tListSize];
    reservationList = new Reservation[resListSize];

    for(int i = 0; i < tListSize; i ++)
    {
        theaterList[i] = right.theaterList[i];
    }
    for(int i = 0; i < resListSize; i++)
    {
        reservationList[i] = right.reservationList[i];
    }

}

//FUNCTION FOR ADDING THEATER TO BOX OFFICE
void BoxOffice::addTheater(int theaterId, string movieName,int numRows, int numSeatsPerRow){
    bool uniqueId = true;
    for(int i = 0; i < tListSize; i++)
    {
        if(theaterList[i].getTheaterId() == theaterId){
            uniqueId = false;
        }
    }

    if(uniqueId){
        Theater *newList = new Theater[tListSize + 1];
        for(int i = 0; i < tListSize; i++)
        {
            newList[i] = theaterList[i];
        }
        newList[tListSize].setTheaterId(theaterId);
        newList[tListSize].setMovieName(movieName);
        newList[tListSize].setRowNum(numRows);
        newList[tListSize].setSeatPerRow(numSeatsPerRow);

        cout << "Theater " << theaterId << " (" << movieName << ") has been added." << endl;

        //if(theaterList){
            //delete[] theaterList;
        //}
        theaterList = newList;
        tListSize++;


    }
    else if(!uniqueId)
    {
        cout << "Theater ID is not unique. Cannot add an existing ID." << endl;
    }
}

//FUNC FOR REMOVING THEATER FROM BOX OFFICE
void BoxOffice::removeTheater(int theaterId){
    if(tListSize < 1)
    {
        cout << "There are no theaters in the list." << endl;
    }
    else{
        bool idExists = false;
        for(int index = 0; index < tListSize; index++)
        {
            if(theaterList[index].getTheaterId() == theaterId){
                idExists = true;
                if(idExists)
                {

                    //CANCEL RESERVATION

                    cout << "Theater " << theaterId << "(" << theaterList[index].getMovieName() << ") and all of its reservations are cancelled." << endl;


                    Theater * oldList = theaterList;
                    theaterList = new Theater [tListSize = 1];
                    for(int k = 0; k < index; k++)
                    {
                        theaterList[k] = oldList[k];
                    }
                    for(int j = index + 1; j < tListSize; j++)
                    {
                        theaterList[j - 1] = oldList[j];
                    }

                    //delete[] oldList;
                }
                tListSize--;

                break;
            }
        }
        if(!idExists)
        {
            cout << "Theater " << theaterId << " does not exist." << endl;
        }
    }

}

//SHOW ALL THEATERS WITH DI AND MOVIE NAME
void BoxOffice::showAllTheaters(){
    if(tListSize == 0){
        cout << "No movie theaters in the system!" << endl;
    }
    else{
        cout << "Theaters currently in the system:" << endl;
        for(int i = 0; i < tListSize; i++)
        {
            cout << "Theater " << theaterList[i].getTheaterId() << "(" << theaterList[i].getMovieName() << "): " << theaterList[i].getAvailableSeatNum() << " available seats " << endl;
        }
    }

}

//SHOW A SPECIFIC THEATER
void BoxOffice::showTheater(int theaterId){
    bool idExists = false;
    for (int index = 0; index < tListSize; index++)
    {
        if(theaterList[index].getTheaterId() == theaterId)
        {
            idExists = true;
            cout << "Theater " << theaterId << " (" << theaterList[index].getMovieName() << ") has " << theaterList[index].getAvailableSeatNum() << " available seats" << endl;

            //SHOW SEATING POSITIONS WITH NUMBERS ANS CHARACTERS
        }
    }

    if(!idExists)
    {
        cout << "Theater " << theaterId << " does not exist." << endl;
    }

    //TODO
}

//MAKE REVERVATION TO THE THEATER WITH ID AND NUM FO AUDIENCE WITH SEAT ROW AND SEAT COL POINTERS
int BoxOffice::makeReservation (int theaterId, int numAudiences, char *seatRow, int *seatCol){
    //TODO

    //CREATE UNIQUE RESERVATION CODE
    return 0;
}

//CANCEL RESERVATION WITH UNIQUE RESERVATION CODE CORRESPONDING THE THEATER
void BoxOffice::cancelReservation(int resCode){
    //TODO
}

//SHWO RESERVATION DETAILS WITH UNIQUE RESERVATION CODE
void BoxOffice::showReservation(int resCode){
    //TODO

}

