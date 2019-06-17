/**
* Title : Linked-List
* Author : Sila Inci
* ID: 21602415
* Section : 1
* Assignment : 3
* Description : Header file for Paper class
*/

#include <iostream>

using namespace std;
class Paper{
public:
    struct AuthorNode{
        AuthorNode* next;
        string name;
        string institution;
    };
    //DEFAULT CONSTRUCT
    Paper();
    //CONSTRUCTOR
    Paper(string paperTitle, string journal, int pubYear);
    //COPY CONSTRUCTOR
    Paper(const Paper &paperToCopy);
    //ASSIGNMENT OPERATOR
    void operator=(const Paper &right);
    //DESTRUCTOR
    ~Paper();

    void addCoauthor(const string& coauthorFirstName, const string& coauthorLastName, const string& coauthorInstitution);
    void removeCoauthor(const string& coauthorFirstName, const string& coauthorLastName, bool& found);
    void showCoauthor(const string& coauthorFirstName, const string& coauthorLastName, bool& found);
    string getPaperTitle();
    string getJournal();
    int getPubYear();
    Paper::AuthorNode* getHead();
    void setPaperTitle(string paperTitle);
    void setJournal(string journal);
    void setPubYear(int pubYear);
private:

    string paperTitle;
    string journal;
    int publishDate;
    int coAuthorNum;
    AuthorNode* head;

};
