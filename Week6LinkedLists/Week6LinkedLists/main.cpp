//
//  main.cpp
//  Week6LinkedLists
//
//  Created by Harrison Senesac on 6/20/17.
//  Copyright © 2017 Harrison Senesac. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "priorityQueue.h"
using namespace std;
int main()
{
    //local declarations
    int option,priority;
    PriorityQueue pq;
    char ch;
    string jobName;
    int number = 0;
    do
    {
        
        cout << "1.Completed Jobs\n";
        cout << "2.List of uncompleted Jobs\n";
        cout << "3.Exit\n";
        cout << "Enter your option : ";
        cin >> option;
        switch(option)
        {
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
                
            default :
                cout << "Wrong option\n";
        }
    }
    while(option != 4);
    return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

// node of the Priority Queue
struct node
{
    //local declarations
    int priority;
    int snumber;
    string jobName;
    struct node *next;
};

//PriorityQueue
class PriorityQueue

{
    
private:
    node *front;
    //constructor
public:
    PriorityQueue()
    {
        front = NULL;
    }
    for( int K=0; K<1000; ++K ){ //a day
        job = add_job(); //26% return a (random) priority, else returns -1
        if( job.priority not_eq -1 )
            queue.push( job );
            
            for( auto &p: printers )
                p.work( queue );
                }
    //the day has ended, print jobs completed
    for( auto &p: printers )
        p.print_report();
        //unfinished jobs
        show( queue );
