//
//  main.cpp
//  Assignment 3
//
//  Created by Harrison Senesac on 5/27/18.
//  Copyright © 2018 Harrison Senesac. All rights reserved.
//
// Worst case run time using big O
// O(n^2)
// O(10^2) = O(100)
//
#include <iostream>
#include <vector>
using namespace std;
//--------------------------------------------------------------
class ArrayIns
{
private:
    vector<double> v;              //vector v
    int nElems;                    //number of data items
    //--------------------------------------------------------------
public:
    ArrayIns(int max) : nElems(0)     //constructor
    {
        v.resize(max);                 //size the vector
    }
    //--------------------------------------------------------------
    void insert(double value)         //put element into array
    {
        v[nElems] = value;             //insert it
        nElems++;                      //increment size
    }
    //--------------------------------------------------------------
    void display()                    //displays array contents
    {
        for(int j=0; j<nElems; j++)    //for each element,
            cout << v[j] << " ";        //display it
        cout << endl;
    }
    //--------------------------------------------------------------
    void insertionSort()
    {
        int in, out;
        
        for(out=1; out<nElems; out++)     //out is dividing line
        {
            double temp = v[out];          //remove marked item
            in = out;                      //start shifts at out
            while(in>0 && v[in-1] >= temp) //until one is smaller,
            {
                v[in] = v[in-1];            //shift item to right
                --in;                       //go left one position
            }
            v[in] = temp;                  //insert marked item
        }  //end for
    }  //end insertionSort()
    //--------------------------------------------------------------
};  //end class ArrayIns
////////////////////////////////////////////////////////////////
int main()
{
    int maxSize = 100;            //array size
    ArrayIns arr(maxSize);        //create array
    
    arr.insert(23);               //insert 10 items
    arr.insert(54);
    arr.insert(2);
    arr.insert(8);
    arr.insert(3.2);
    arr.insert(14);
    arr.insert(43);
    arr.insert(0);
    arr.insert(9);
    arr.insert(2);
    
    cout << "Unsorted Array: " << endl;
    arr.display();                //display items
    arr.insertionSort();          //insertion-sort them
    cout << "Sorted Array: " << endl;
    arr.display();                //display them again
    return 0;
}  //end main()

