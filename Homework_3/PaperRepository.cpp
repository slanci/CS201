/**
* Title : Linked-List
* Author : Sila Inci
* ID: 21602415
* Section : 1
* Assignment : 3
* Description : Cpp file for PaperRepository class
*/

#include <iostream>
#include "PaperRepository.h"

using namespace std;
    //CONSTRUCTOR
    PaperRepository::PaperRepository(){
        tail = NULL;
        paperNum = 0;
    }

    //DESTRUCTOR
    PaperRepository::~PaperRepository(){
        PaperNode* cur = tail->next;
        PaperNode* temp;
        do{
            temp = cur;
            cur = cur->next;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->next = NULL;
            temp->prev = NULL;
            delete temp;
        }while(cur != tail->next);
    }
    //adds paper to paper repository with given parameters
    void PaperRepository::addPaper(const string& paperTitle, const string& journalTitle, const int publicationYear){
        bool uniquePaper = true;
        if(paperNum < 1)
            uniquePaper = true;
        else{
            PaperNode* cur = tail->next;
            do{
                if(cur->paper.getPaperTitle() == paperTitle)
                    uniquePaper = false;
                cur = cur->next;
            }while(cur != tail->next);
        }

        if(uniquePaper){
            if(tail != NULL)
            {
                PaperNode* newPaper = new PaperNode;
                newPaper->next = tail->next;
                newPaper->prev = tail;
                tail->next->prev = newPaper;
                tail->next= newPaper;
                tail = newPaper;
                newPaper->paper.setPaperTitle(paperTitle);
                newPaper->paper.setJournal(journalTitle);
                newPaper->paper.setPubYear(publicationYear);
            }
            else{
                PaperNode* newPaper = new PaperNode;
                newPaper->paper.setPaperTitle(paperTitle);
                newPaper->paper.setJournal(journalTitle);
                newPaper->paper.setPubYear(publicationYear);
                tail = newPaper;
                tail->next = tail;
                tail->prev = tail;
            }
            incPaperNum(1);
            cout << "INFO: Paper " << paperTitle << " has been added." << endl;
        }
        else{
            cout << "ERROR: Paper " << paperTitle << " already exists." << endl;
        }
    }

    //removes certain paper with given parameters
    void PaperRepository::removePaper(const string& paperTitle){
        PaperNode* cur = tail->next;
        bool paperFounded = false;
        do{
            if(cur->paper.getPaperTitle() == paperTitle)
            {
                paperFounded = true;
                if(cur == tail){
                    tail = tail->prev;
                }
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                cur->next = NULL;
                cur->prev = NULL;

                delete cur;
                cout << "INFO:Paper " << paperTitle << " has been deleted." << endl;
                break;
            }
            cur = cur->next;
        }while(cur != tail->next);

        if(!paperFounded)
        {
            cout << "ERROR: This paper does not exist in the repository." << endl;
        }
    }

    //adds a coauthor for the given paper in the parameters
    //calls the addCoauthor function from the Paper class
    void PaperRepository::addCoauthor(const string& paperTitle,const string& coauthorFirstName, const string& coauthorLastName, const string& coauthorInstitution){
        PaperNode* cur = tail->next;
        bool paperFounded = false;
        do{
            if(cur->paper.getPaperTitle() == paperTitle)
            {
                paperFounded = true;
                cur->paper.addCoauthor(coauthorFirstName,coauthorLastName,coauthorInstitution);
            }
            cur = cur->next;
        }while(cur != tail->next);

        if(!paperFounded)
        {
            cout << "ERROR: This paper does not exist in the repository." << endl;
        }
    }

    //removes given coauthor from all of works
    //calls removeCoauthor function from the Paper class
    void PaperRepository::removeCoauthor(const string& coauthorFirstName, const string& coauthorLastName){
        bool found = false;
        PaperNode* cur = tail->next;
        do{
            cur->paper.removeCoauthor(coauthorFirstName,coauthorLastName,found);
            cur = cur->next;
        }while(cur != tail->next);
        if(!found)
        {
            cout << "ERROR: Coauthor " << coauthorFirstName << " " << coauthorLastName << " does not have any paper in the repository." << endl;
        }
    }

    //lists all the papers in the repository
    void PaperRepository::showAllPapers(){
        if(paperNum == 0){
            cout << "---none---" << endl;
        }
        else{
            PaperNode* cur = tail-> next;
            do
            {
                cout << cur->paper.getPaperTitle() <<"," << cur->paper.getJournal() << "," << cur->paper.getPubYear() << endl;
                cur = cur -> next;
            }while(cur != tail->next);
        }
    }

    //shows all the works of a coauthor
    void PaperRepository::showCoauthor(const string& coauthorFirstName, const string& coauthorLastName){
        cout << coauthorFirstName << " " << coauthorLastName << endl;
        bool found = false;
        PaperNode* cur = tail->next;
        do{
            cur->paper.showCoauthor(coauthorFirstName,coauthorLastName, found);
            cur = cur->next;
        }while(cur != tail->next);
        if(!found)
            cout << "---none---" << endl;
    }

    //shows all the papers in a journal
    void PaperRepository::showJournal(const string& journalTitle){
        bool journalExist = false;
        cout << journalTitle << endl;
        PaperNode* cur = tail->next;
        do{
            if(cur->paper.getJournal() == journalTitle)
            {
                journalExist = true;
                cout << cur->paper.getPaperTitle() << ", " << cur->paper.getPubYear() << endl;
            }
            cur = cur->next;
        }while(cur != tail->next);

        if(!journalExist)
            cout << "---none---" << endl;
    }

    //increases the number of papers
    void PaperRepository::incPaperNum(int amount)
    {
        paperNum += amount;
    }

    //returns the number of papers
    int PaperRepository::getPaperNum()
    {
        return paperNum;
    }

