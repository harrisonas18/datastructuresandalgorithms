//
//  main.cpp
//  Week9MergeSortQuickSort
//
//  Created by Harrison Senesac on 10/31/17.
//  Copyright © 2017 Harrison Senesac. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>                //for random numbers
#include <ctime>                  //for random numbers
using namespace std;
////////////////////////////////////////////////////////////////
class ArrayPar
{
private:
    vector<double> theVect;     //vector of doubles
    int nElems;                 //number of data items
public:
    //--------------------------------------------------------------
    ArrayPar(int max) : nElems(0)  //constructor
    {
        theVect.resize(max);        //size the vector
    }
    //--------------------------------------------------------------
    void insert(double value)      //put element into array
    {
        theVect[nElems] = value;    //insert it
        nElems++;                   //increment size
    }
    //--------------------------------------------------------------
    int getSize()                  //return number of items
    { return nElems; }
    //--------------------------------------------------------------
    void display()                 //displays array contents
    {
        cout << "A=";
        for(int j=0; j<nElems; j++)      //for each element,
            cout << theVect[j] << " ";    //display it
        cout << endl;
    }
    //--------------------------------------------------------------
    //partition a range
    int partitionIt(int left, int right, double pivot)
    {
        int leftMark = left - 1;        //right of first elem
        int rightMark = right + 1;      //left of pivot
        while(true)
        {
            while(leftMark < right &&    //find bigger item
                  theVect[++leftMark] < pivot)
                ;  //(nop)
            
            while(rightMark > left &&    //find smaller item
                  theVect[--rightMark] > pivot)
                ;  //(nop)
            if(leftMark >= rightMark)    //if markers cross,
                break;                    //   partition done
            else                         //not crossed, so
                swap(leftMark, rightMark); //  swap elements
        }  //end while(true)
        return leftMark;                //return partition
    }  //end partitionIt()
    //--------------------------------------------------------------
    void swap(int dex1, int dex2)  //swap two elements
    {
        double temp;
        temp = theVect[dex1];            //A into temp
        theVect[dex1] = theVect[dex2];   //B into A
        theVect[dex2] = temp;            //temp into B
    }  //end swap(
    //--------------------------------------------------------------
};  //end class ArrayPar
////////////////////////////////////////////////////////////////
int main()
{
    time_t aTime;
    int maxSize = 250;              //array size
    ArrayPar arr(maxSize);         //create the array
    srand( static_cast<unsigned>(time(&aTime)) ); //seed randoms
    
    for(int j=0; j<maxSize; j++)   //fill array with
    {                           //random numbers
        double n = rand() % 199;
        arr.insert(n);
    }
    arr.display();                 //display unsorted array
    
    double pivot = 99;             //pivot value
    cout << "\nPivot is " << pivot;
    int size = arr.getSize();
    //partition array
    int partDex = arr.partitionIt(0, size-1, pivot);
    
    cout << ", Partition is at index " << partDex << endl;
    cout << "\n" << endl;
    arr.display();                 //display partitioned array
    return 0;
}  //end main()
