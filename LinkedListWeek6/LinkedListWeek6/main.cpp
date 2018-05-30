//
//  main.cpp
//  LinkedListWeek6
//
//  Created by Harrison Senesac on 10/9/17.
//  Copyright © 2017 Harrison Senesac. All rights reserved.
//

//linkList.cpp
//demonstrates linked list
#include <iostream>
#include <stdlib.h>
using namespace std;
/////////////////////////////////////////////////////////////
class Link
{
public:
    string iData;                  //data item
    Link* pNext;                //ptr to next link in list
    //----------------------------------------------------------
    Link(string id) :      //constructor
    iData(id), pNext(NULL)
    {  }
    //----------------------------------------------------------
    void displayLink()             //display ourself {22, 2.99}
    {
        cout << "{" << iData << "} ";
    }
    //----------------------------------------------------------
};  //end class Link
/////////////////////////////////////////////////////////////
class LinkList
{
private:
    Link* pFirst;               //ptr to first link on list
public:
    //----------------------------------------------------------
    LinkList() : pFirst(NULL)      //constructor
    { }                         //no links on list yet
    //----------------------------------------------------------
    bool isEmpty()                 //true if list is empty
    { return pFirst==NULL; }
    //----------------------------------------------------------
    //insert at start of list
    void insertFirst(string id)
    {                           //make new link
        Link* pNewLink = new Link(id);
        pNewLink->pNext = pFirst;   //newLink-->old first
        pFirst = pNewLink;          //first-->newLink
    }
    //----------------------------------------------------------
    Link* getFirst()               //return first link
    { return pFirst; }
    //----------------------------------------------------------
    void removeFirst()             //delete first link
    {                           //(assumes list not empty)
        Link* pTemp = pFirst;       //save first
        pFirst = pFirst->pNext;     //unlink it: first-->old next
        delete pTemp;               //delete old first
    }
    //----------------------------------------------------------
    void displayList()
    {
        cout << "List (first-->last): ";
        Link* pCurrent = pFirst;    //start at beginning of list
        while(pCurrent != NULL)     //until end of list,
        {
            pCurrent->displayLink(); //print data
            pCurrent = pCurrent->pNext;  //move to next link
        }
        cout << endl;
    }
    //----------------------------------------------------------
};  //end class LinkList
/////////////////////////////////////////////////////////////

LinkList theList;       //Globally declared list so main function and divider function can access it

///////////////Divider function to break number into groups of 3
void divider (long int number) {
    int digit;
    if (number > 1000){
        digit = number % 1000;
        number /= 1000;
        std::string a = std::to_string(digit);
        theList.insertFirst(a);
        divider(number);
    } else if (10 < number && number < 100){
        std::string b = std::to_string(number);
        std::string newB = "0"+b;
        theList.insertFirst(newB);
    } else if (number < 10) {
        std::string c = std::to_string(number);
        std::string newC = "00" + c;
        theList.insertFirst(newC);
    } else {
        std::string d = std::to_string(number);
        theList.insertFirst(d);
    }
}
///////////////End Divider function

//Main Program
int main()
{
    
    long int userNumber;        //Variable to store user input
    cout << "Enter a positive, whole number:" ;
    cin >> userNumber ;
    
    if(userNumber < 0){     //Check to see if input is positive
        cout << "Number is not positive, try again."<<endl;
        return 1;
    } else {
        divider(userNumber);
        theList.displayList();
    }
    
    
    return 0;
}  //end main()
