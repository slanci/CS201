#include <string>
using namespace std;
class Theater{
public:
    Theater();
    Theater(int theaterId, string movieName,int numRows, int numSeatsPerRow);
    ~Theater();
    int getTheaterId();
    string getMovieName();
    int getNumRows();
    int getNumSeatsPerRow();
    int getAvailableSeatNum();
    void setTheaterId(int id);
    void setMovieName(string movie);
    void setRowNum(int rowNum);
    void setSeatPerRow(int seatPerRow);
    bool decrementAvailableSeat(int a);

    int availableSeatNum;


private:
    int theaterId;
    string movieName;
    int numRows;
    int numSeatsPerRow;
    int ** seats;

};

