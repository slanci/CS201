/**
* Title : Linked-List
* Author : Sila Inci
* ID: 21602415
* Section : 1
* Assignment : 3
* Description : Cpp file for Paper class
*/

#include <iostream>
#include <string>
#include "Paper.h"

using namespace std;

    //DEFAULT CONSTRUCT
    Paper::Paper(){
        paperTitle = "";
        journal = "";
        publishDate = 0;
        coAuthorNum = 0;
        head = NULL;
    }
    //CONSTRUCTOR
    Paper::Paper(string paperTitle, string journal, int pubYear){
        this->paperTitle = paperTitle;
        this->journal = journal;
        this->publishDate = pubYear;
        coAuthorNum = 0;
        head = NULL;
    }
    //COPY CONSTRUCTOR
    Paper::Paper(const Paper &paperToCopy){
        paperTitle = paperToCopy.paperTitle;
        journal = paperToCopy.journal;
        publishDate = paperToCopy.publishDate;
        coAuthorNum = paperToCopy.coAuthorNum;
        head = paperToCopy.head;
    }
    //ASSIGNMENT OPERATOR
    void Paper::operator=(const Paper &right){
        if(this == &right)
            cout << "Same paper." << endl; //self assignment
        else{
            paperTitle = right.paperTitle;
            journal = right.journal;
            publishDate = right.publishDate;
            coAuthorNum = right.coAuthorNum;

            AuthorNode* cur = head;
            AuthorNode* temp;

            while(cur != NULL)
            {
                if(cur == NULL)
                    break;
                else{
                    temp = cur;
                    cur = cur->next;
                    delete temp;
                }
            }
            head = NULL;
            AuthorNode* curr = right.head;
            AuthorNode* lastly;

            while(curr != NULL)
            {
                if(head == NULL)
                {
                    AuthorNode* temp = new AuthorNode;
                    temp->name = curr->name;
                    temp->institution = curr->institution;
                    head = temp;
                    temp = NULL;
                }
                else
                {
                    AuthorNode* temp = new AuthorNode;
                    temp->name = curr->name;
                    temp->institution = curr->institution;
                    lastly = temp;
                    temp = NULL;
                }
                lastly = curr;
                curr = curr->next;

            }
        }
    }
    //DESTRUCTOR
    Paper::~Paper(){
        AuthorNode* cur = head;
        AuthorNode* temp;

        while(cur != NULL)
        {
            if(cur == NULL)
                break;
            else{
                temp = cur;
                cur = cur-> next;
                delete temp;
            }
        }
    }

    //adds a coauthor for the paper
    void Paper::addCoauthor(const string& coauthorFirstName, const string& coauthorLastName, const string& coauthorInstitution){
        AuthorNode* cur = head;
        bool inPlace = false;
        bool authorExist = false;
        string coAuthorName = coauthorFirstName + " " + coauthorLastName;
        AuthorNode* iterate = head;
        while (iterate != NULL)
        {
            if(iterate->name == coAuthorName)
            {
                authorExist = true;
            }
            iterate = iterate->next;
        }
        if(!authorExist){
            if(head == NULL)
            {
                AuthorNode* temp = new AuthorNode;
                temp->name = coAuthorName;
                temp->institution = coauthorInstitution;
                head = temp;
                head->next = NULL;
                cout << "INFO: Coauthor " << coAuthorName << " has been added to Paper " << this->paperTitle << endl;
            }
            else{
                AuthorNode* temp = new AuthorNode;
                temp->name = coAuthorName;
                temp->institution = coauthorInstitution;
                while(cur != NULL)
                {
                    string str2 = temp->name;
                    string str3 = cur->name;
                    for(unsigned i = 0; i < str2.length(); i++)
                    {
                        if(str2.at(i) < str3.at(i))
                        {
                            temp->next = cur;
                            cur = temp;
                            inPlace = true;
                            break;
                        }

                        if(str2.at(i) > str3.at(i))
                        {
                            if(cur->next != NULL){
                                AuthorNode* nextNode = cur->next;
                                string str1 = nextNode->name;
                                if(str1.at(i) > str2.at(i))
                                {
                                    temp->next = cur->next;
                                    cur->next = temp;
                                    inPlace = true;
                                    break;
                                }
                            }
                            else{
                                cur->next = temp;
                                temp->next = NULL;
                                break;
                            }
                        }
                    }
                    if(inPlace)
                        break;
                    cur = cur->next;
                }
                cout << "INFO: Coauthor " << coAuthorName << " has been added to Paper " << this->paperTitle << endl;
            }

            coAuthorNum++;
        }
        if(authorExist)
        {
            cout << "ERROR: Coauthor " << coAuthorName << " already is in Paper " << this->paperTitle << endl;
        }
    }

    //removes given coauthor from the paper
    void Paper::removeCoauthor(const string& coauthorFirstName, const string& coauthorLastName, bool& found)
    {
        string coAuthorName = coauthorFirstName + " " + coauthorLastName;

        if(coAuthorNum == 1)
        {
            delete head;
            head = NULL;
        }
        if(coAuthorNum > 1){
            AuthorNode* cur = head;
            AuthorNode* prev = cur;
            while(cur != NULL)
            {
                if(cur->name == coAuthorName)
                {
                    found = true;
                    if(cur == head)
                    {
                        head = cur->next;
                        cur->next = NULL;
                        delete cur;
                        cur = head;
                        cout << "INFO: Coauthor " << coAuthorName << " has been deleted from Paper " << this->paperTitle << endl;
                    }

                    else{
                        prev->next = cur->next;
                        cur->next = NULL;
                        delete cur;
                        cur = prev;
                        cout << "INFO: Coauthor " << coAuthorName << " has been deleted from Paper " << this->paperTitle << endl;
                    }
                }
                prev = cur;
                cur = cur->next;
            }

            coAuthorNum--;
        }
        else if (coAuthorNum == 0){
            cout << "ERROR: There are no Coauthor to remove." << endl;
        }

    }

    //shows the paper's certain properties if the coauthor names matches with this paper's coauthor's name
    void Paper::showCoauthor(const string& coauthorFirstName, const string& coauthorLastName, bool& found)
    {
        string coAuthorName = coauthorFirstName + " " + coauthorLastName;
        AuthorNode* cur = head;
        while (cur != NULL)
        {
            if(cur->name == coAuthorName)
            {
                found = true;
                cout << cur->institution << ", " << this->paperTitle << ", " << this->publishDate << endl;
            }
            cur = cur->next;
        }
        if(head == NULL)
        {
            found = false;
        }
    }

    //returns paper title
    string Paper::getPaperTitle(){
        return paperTitle;
    }
    //return journal name
    string Paper::getJournal(){
        return journal;
    }
    //returns publish date
    int Paper::getPubYear(){
        return publishDate;
    }
    //returns the pointer to head
    Paper::AuthorNode* Paper::getHead(){
        return head;
    }
    //sets paper title
    void Paper::setPaperTitle(string paperTitle){
        this->paperTitle = paperTitle;
    }
    //sets journal name
    void Paper::setJournal(string journal){
        this ->journal = journal;
    }
    //sets publish date
    void Paper::setPubYear(int pubYear){
        this->publishDate = pubYear;
    }
