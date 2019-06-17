#include <iostream>
#include <string>
using namespace std;

#include "Theater.h"

Theater::Theater(){
    theaterId = 0;
    movieName = "";
    numRows = 0;
    numSeatsPerRow = 0;
    availableSeatNum = 0;
}

Theater::Theater(int theaterId, string movieName,int numRows, int numSeatsPerRow){
    this-> theaterId = theaterId;
    this-> movieName = movieName;
    this-> numRows = numRows;
    this-> numSeatsPerRow = numSeatsPerRow;
    this-> availableSeatNum = numRows * numSeatsPerRow;
    seats = new int*[numRows];

    for(int i = 0; i < numRows - 1; ++i){
        seats[i] = new int[i];
    }

    for(int row = 0; row < numRows; row++)
    {
        for(int col = 0; col < numSeatsPerRow; col++)
        {
            seats[row][col] = 0;
        }
    }
}

Theater::~Theater(){

    for(int i = 0; i < numRows -1; ++i){
        delete[] seats[i];
    }
    delete[] seats;
}

int Theater::getTheaterId(){
    return theaterId;
}

string Theater::getMovieName(){
    return movieName;
}

int Theater::getNumRows(){
    return numRows;
}

int Theater::getNumSeatsPerRow(){
    return numSeatsPerRow;
}

int Theater::getAvailableSeatNum(){
    return availableSeatNum;
}

void Theater::setTheaterId(int id){
    this->theaterId = id;
}

void Theater::setMovieName(string movie){
    this->movieName = movie;
}

void Theater::setRowNum(int rowNum){
    this->numRows = rowNum;
}

void Theater::setSeatPerRow(int seatPerRow){
    this->numSeatsPerRow = seatPerRow;
}

void Theater:: setAvailableSeatNum(int rowNum, int seatPerRow)
{
    this->availableSeatNum = rowNum * seatPerRow;
}

bool Theater::decrementAvailableSeat(int a){
    if(getAvailableSeatNum() <= 0)
        return false;
    else{
        availableSeatNum = availableSeatNum - a;
        return true;
    }
}
