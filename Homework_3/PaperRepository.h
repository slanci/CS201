/**
* Title : Linked-List
* Author : Sila Inci
* ID: 21602415
* Section : 1
* Assignment : 3
* Description : Header file for PaperRepository class
*/

#include <iostream>
#include "Paper.h"
using namespace std;

class PaperRepository{
public:

    PaperRepository();
    ~PaperRepository();
    void addPaper(const string& paperTitle, const string& journalTitle, const int publicationYear);
    void removePaper(const string& paperTitle);
    void addCoauthor(const string& paperTitle,const string& coauthorFirstName, const string& coauthorLastName, const string& coauthorInstitution);
    void removeCoauthor(const string& coauthorFirstName, const string& coauthorLastName);
    void showAllPapers();
    void showCoauthor(const string& coauthorFirstName, const string& coauthorLastName);
    void showJournal(const string& journalTitle);
    void incPaperNum(int amount);
    int getPaperNum();

private:
    struct PaperNode{
        Paper paper;
        PaperNode* next;
        PaperNode* prev;
    };

    PaperNode* tail;
    int paperNum;
};
