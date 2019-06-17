#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
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
        newList[tListSize].setAvailableSeatNum(numRows, numSeatsPerRow);

        cout << "Theater " << theaterId << " (" << movieName << ") has been added." << endl;


        //BURADA YINE SORUN VERIYO RUNTIME ERROR


        if(theaterList){
            //delete[] theaterList;
        }
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
                    //CANCELLING RESERVATIONS OF THEATER
                    for(int j = 0; j < resListSize; j++)
                    {
                        if(reservationList[j].theaterIdNum == theaterId){
                            Reservation * oldRes = reservationList;
                            reservationList = new Reservation[resListSize - 1];
                            for(int i = 0; i < j; i++)
                            {
                                reservationList[i] = oldRes[i];
                            }
                            for(int m = j + 1; m < resListSize; m++)
                            {
                                reservationList[m - 1] = oldRes[m];
                            }
                            delete[] oldRes;

                            resListSize--;

                        }
                    }

                    cout << "Theater " << theaterId << "(" << theaterList[index].getMovieName() << ") and all of its reservations are cancelled." << endl;

                    // REMOVING THE THEATER ITSELF
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

                    delete[] oldList;
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

            //SHOW SEATING POSITIONS WITH NUMBERS AND

            cout << "0: Available" << endl;
            cout << "1: Occupied" << endl;

            for(int k = 0; k < theaterList[index].getNumSeatsPerRow(); k++)
            {
                cout << "\t" << k;
            }
            cout << "" << endl;
            char seatLetter = 'A';

            for(int i = 0; i < theaterList[index].getNumRows(); i++)
            {
                printf("%c ", seatLetter);
                for(int m = 0; m < theaterList[index].getNumSeatsPerRow(); m++)
                {
                    cout << "\t" << theaterList[index].seats[i][m];
                }
                cout << "" << endl;
                seatLetter++;
            }
        }
    }

    if(!idExists)
    {
        cout << "Theater " << theaterId << " does not exist." << endl;
    }

}

//MAKE REVERVATION TO THE THEATER WITH ID AND NUM FO AUDIENCE WITH SEAT ROW AND SEAT COL POINTERS
int BoxOffice::makeReservation (int theaterId, int numAudiences, char *seatRow, int *seatCol){
    //TODO
    string assignMovie;
    if(tListSize < 1)
        return -1;

    for(int i = 0; i < tListSize; i++)
    {
        if((theaterList[i].getTheaterId() == theaterId) && (theaterList[i].getAvailableSeatNum() >= numAudiences))
        {
            assignMovie = theaterList[i].getMovieName();
            for(int row = 0; row < sizeof(seatRow); row++)
            {
                int seatRowNum = int(seatRow[row]) - 64;
                int seatColNum = seatCol[row];
                theaterList[i].seats[seatRowNum - 1][seatColNum - 1] = 1;
                theaterList[i].decrementAvailableSeat(1);
            }
        int resCode = rand() % 1000 + 1000;

        Reservation *newRes = new Reservation[resListSize + 1];
        for(int k = 0; k < resListSize; k++)
        {
            newRes[i] = reservationList[k];
        }

        newRes[resListSize].code = resCode;
        newRes[resListSize].movie = assignMovie;
        newRes[resListSize].numOfPeople = numAudiences;
        newRes[resListSize].theaterIdNum = theaterId;

        ostringstream rowStr;
        ostringstream colStr;
        ostringstream seatStr;

        ostringstream* newReservedSeat = new ostringstream[sizeof(seatRow)];

        for(int j = 0; j < sizeof(seatRow); j++)
        {
            rowStr << seatRow[j];
            colStr << seatCol[j];
            rowStr << colStr.str();

            //BURADA ASAGIDA SORUN VERIYO EGER COMMENTTEN CIKARIRSAM

            //newReservedSeat[j] = rowStr;

        }

        resListSize++;

        return resCode;

        }
        else{
            return -1;
        }

    }

}

//CANCEL RESERVATION WITH UNIQUE RESERVATION CODE CORRESPONDING THE THEATER
void BoxOffice::cancelReservation(int resCode){
    if(reservationList == NULL)
        cout << "There are no reservations to cancel." << endl;
    else{
        for(int i = 0; i < resListSize; i++)
        {
            if(reservationList[i].code == resCode)
            {
                Reservation * oldRes = reservationList;
                reservationList = new Reservation[resListSize - 1];
                for(int k = 0; k < i; k++)
                {
                    reservationList[k] = oldRes[k];
                }
                for(int m = i + 1; m < resListSize; m++)
                {
                    reservationList[m - 1] = oldRes[m];
                }
                delete[] oldRes;

                resListSize--;
            }
        }
            //reslist tarat ve codeluyu sil, theater seats updatele (char* reserved seats'e gore)
    }
}

//SHWO RESERVATION DETAILS WITH UNIQUE RESERVATION CODE
void BoxOffice::showReservation(int resCode){
    bool resExists = false;
    for(int i = 0; i < resListSize; i++)
    {
        if(reservationList[i].code == resCode)
        {
            resExists = true;
            cout << "Reservation Theater Id: " << reservationList[i].theaterIdNum << "\n Movie Name: " << reservationList[i].movie << endl;
            cout << "Seats under reservation: ";
            for(int k = 0; k < reservationList[i].numOfPeople; k++)
            {
                cout << reservationList[i].reservedSeats[k] << " ";
            }
            cout << "" << endl;
        }
    }
    if(!resExists)
        cout << "No reservation found. " << endl;
}
