#include <iostream>
#include "Theater.h"

using namespace std;

struct Reservation{
    int code;
    int theaterIdNum;
    int numOfPeople;
    string movie;
    ostringstream * reservedSeats;
};
class BoxOffice{
public:
    BoxOffice();
    ~BoxOffice();
    BoxOffice(const BoxOffice &boxOfficeToCopy);
    void operator=(const BoxOffice &right);

    void addTheater(int theaterId, string movieName,int numRows, int numSeatsPerRow);
    void removeTheater(int theaterId);
    void showAllTheaters();
    void showTheater(int theaterId);
    int makeReservation (int theaterId, int numAudiences, char *seatRow, int *seatCol);
    void cancelReservation(int resCode);
    void showReservation(int resCode);
    //bool searchTheater(int theaterId, Theater* theatherList);

private:
    Theater *theaterList;
    int tListSize;
    Reservation * reservationList;
    int resListSize;
};
