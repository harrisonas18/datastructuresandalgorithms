//
//  main.cpp
//  Week2BinarySearch
//
//  Created by Harrison Senesac on 5/17/18.
//  Copyright © 2018 Harrison Senesac. All rights reserved.
//

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

//Declare Size of array
const int size = 8;

int binarySearch(double myArray[], int size, double searchKey)
{
    int lowerBound = 0;
    int upperBound = size - 1;
    int mid;
    
    while (lowerBound <= upperBound) {
        mid = (lowerBound + upperBound) / 2;
        
        if(searchKey == myArray[mid])
        {
            return mid;
        }
        else if (searchKey > myArray[mid])
        {
            lowerBound = mid + 1;
        }
        else
        {
            upperBound = mid - 1;
        }
    }
    return -1;
    
}  //end find()

int main(int argc, const char * argv[]) {
    
    //Declare size of array and array
    double myArray[size] = {4.5,6,1,9.2,4,77,1200,16.4};
    
    //Sort in Ascending Order
    sort(myArray, myArray + size);

    //Get User Input and check if it's in the Array
    double userValue;
    cout << "Enter an integer: " << endl;
    cin >> userValue;
    
    int result = binarySearch(myArray, 8, userValue);
    if(result >= 0)
    {
        cout << "The number " << myArray[result] << " was found at the"
        " element with index " << result << endl;
    }
    else
    {
        cout << "The number " << userValue << " was not found. " << endl;
    }
    
    
    return 0;
}

