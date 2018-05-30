//
//  main.cpp
//  Week5Queues
//
//  Created by Harrison Senesac on 9/30/17.
//  Copyright © 2017 Harrison Senesac. All rights reserved.
//

//Queue.cpp
//demonstrates queue
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Queue
{
private:
    int name;
    int maxSize;
    vector<int> queVect;
    int front;
    int rear;
    int nItems;
public:
    //------------------------------------------------------------
    //constructor
    Queue(int n, int s) : name(n), maxSize(s), front(0), rear(-1), nItems(0)
    { queVect.resize(maxSize); }
    //------------------------------------------------------------
    void insert(int j)           //put item at rear of queue
    {
        if(rear == maxSize-1)         //deal with wraparound
            rear = -1;
        queVect[++rear] = j;          //increment rear and insert
        nItems++;                     //one more item
    }
    //------------------------------------------------------------
    int remove()                 //take item from front of queue
    {
        int temp = queVect[front++];  //get value and incr front
        if(front == maxSize)          //deal with wraparound
            front = 0;
        nItems--;                     //one less item
        return temp;
    }
    //------------------------------------------------------------
    int peekFront()              //peek at front of queue
    { return queVect[front]; }
    //------------------------------------------------------------
    bool isEmpty()               //true if queue is empty
    { return (nItems==0); }
    //------------------------------------------------------------
    bool isFull()                //true if queue is full
    { return (nItems==maxSize); }
    //------------------------------------------------------------
    int size()                   //number of items in queue
    { return nItems; }
    //------------------------------------------------------------
};  //end class Queue

//////////////////////////////// Global Variables
Queue printerArray[4] = {{1,10},{2,10},{3,10},{4,10}};  //Array of Queue classes gives 4 queues/printers

int a = 0;
int b = 0;
int c = 0;
int d = 0;
////////////////////////////////

//Finds the printer with the smallest queue and returns the printers number
int findSmallestQueue(int a, int b, int c, int d){
    int min;
    int printer;
    
    min = std::min(a, std::min(b, std::min(c, d)));
    
    if (min == a) {
        printer = 1;
    } else if (min == b){
        printer = 2;
    } else if (min == c){
        printer = 3;
    } else{
        printer = 4;
    }
    
    return printer;
};

//Function checks to see if a new job for the given queue has arrived
bool newJobArrive (int queueSize, int previousQueueSize) {
    
    int remainder = queueSize - previousQueueSize;
    
    if (remainder == 1) {
        return true;
    } else if (remainder == 0) {
        return false;
    } else {
        return false;
    }
    
};

//Helper Function to print queue size and new jobs that have arrived
void printerHelper () {
    cout << "Printer 1 Queue Size: " << printerArray[0].size() << endl;
    if (newJobArrive(printerArray[0].size(), a)) {
        cout << "Printer 1 Received 1 new job." << endl;
    } else {
        cout << "Printer 1 Received No new jobs." << endl;
    }
    
    cout << "Printer 2 Queue Size: " << printerArray[1].size() << endl;
    if (newJobArrive(printerArray[1].size(), b)) {
        cout << "Printer 2 Received 1 new job." << endl;
    } else {
        cout << "Printer 2 Received No new jobs." << endl;
    }
    
    cout << "Printer 3 Queue Size: " << printerArray[2].size() << endl;
    if (newJobArrive(printerArray[2].size(), c)) {
        cout << "Printer 3 Received 1 new job." << endl;
    } else {
        cout << "Printer 3 Received No new jobs." << endl;
    }
    
    cout << "Printer 4 Queue Size: " << printerArray[3].size() << endl;
    if (newJobArrive(printerArray[3].size(), d)) {
        cout << "Printer 4 Received 1 new job." << endl;
    } else {
        cout << "Printer 4 Received No new jobs." << endl;
    }
    
};

//Vars to keep the peek number
int peekPrinter1 = 0;
int peekPrinter2 = 0;
int peekPrinter3 = 0;
int peekPrinter4 = 0;

//Counter vars to hold the pages printed during each interval
int countPrinter1 = 0;
int countPrinter2 = 0;
int countPrinter3 = 0;
int countPrinter4 = 0;


//Counter helper function to keep track of pages printed
void counterHelper () {
    
    //Printer 1
    
    
    //Printer 2
    
    //Printer 3
    
    //Printer 4
    
};


int main()
{
    
    int timer = 4; //
    //Timer pushes new task onto the smallest queue every 5 seconds
    do {
        if(timer % 5 == 0){
            
             a = printerArray[0].size();
             b = printerArray[1].size();
             c = printerArray[2].size();
             d = printerArray[3].size();
            
            int jobSize = rand() % 10 + 1; //Creates a random job size between 1-10 pages
            int printer = findSmallestQueue(a, b, c, d); //finds smallest queue size
            
            switch (printer) {
                case 1:
                    printerArray[0].insert(jobSize);
                    break;
                case 2:
                    printerArray[1].insert(jobSize);
                    break;
                case 3:
                    printerArray[2].insert(jobSize);
                    break;
                case 4:
                    printerArray[3].insert(jobSize);
                    break;
                default:
                    break;
            }
        }
        
        
        printerHelper();
        
        if (printerArray[0].isEmpty() != true) {
            if (peekPrinter1 == 0) {
                peekPrinter1 = printerArray[0].peekFront();
            } else if (countPrinter1 != peekPrinter1){
                countPrinter1++;
            } else if (countPrinter1 == peekPrinter1){
                printerArray[0].remove();
            } else {
                cout << "Counter Print Error" << endl;
            }
        }
        if (printerArray[1].isEmpty() != true) {
            if (peekPrinter2 == 0 && printerArray[1].isEmpty() != true) {
                peekPrinter2 = printerArray[1].peekFront();
            } else if (countPrinter2 != peekPrinter2){
                countPrinter2++;
            } else if (countPrinter2 == peekPrinter2){
                printerArray[1].remove();
            } else {
                cout << "Counter Print Error" << endl;
            }
        }
        if (printerArray[2].isEmpty() != true) {
            if (peekPrinter3 == 0 && printerArray[2].isEmpty() != true) {
                peekPrinter3 = printerArray[2].peekFront();
            } else if (countPrinter3 != peekPrinter3){
                countPrinter3++;
            } else if (countPrinter3 == peekPrinter3){
                printerArray[2].remove();
            } else {
                cout << "Counter Print Error" << endl;
            }
        }
        if (printerArray[3].isEmpty() != true) {
            if (peekPrinter4 == 0 && printerArray[3].isEmpty() != true) {
                peekPrinter4 = printerArray[3].peekFront();
            } else if (countPrinter4 != peekPrinter4){
                countPrinter4++;
            } else if (countPrinter4 == peekPrinter4){
                printerArray[3].remove();
            } else {
                cout << "Counter Print Error" << endl;
            }
        }
        
        cout << timer;
        cout << " Second(s)"<< endl;
        timer++;
    } while (timer < 60); //Timer for new jobs
    
    do {
        printerHelper();
        
        cout << timer;
        cout << " Second(s)"<< endl;
        timer++;
    } while (printerArray[0].isEmpty() != true && printerArray[1].isEmpty() != true && printerArray[2].isEmpty() != true && printerArray[3].isEmpty() != true);
    
    cout << endl;
    return 0;
}  //end main()
