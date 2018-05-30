//
//  main.cpp
//  Week9QuickSortMergeSort
//
//  Created by Harrison Senesac on 10/27/17.
//  Copyright © 2017 Harrison Senesac. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Declarations of Methods
void quick_sort(int[], int, int);
int partition(int[], int, int);

//Recursive quicksort
void quick_sort(int a[], int left, int right)
{
    int j;
    if(left < right)
    {
        j = partition(a, left, right);
        quick_sort(a, left, j-1);
        quick_sort(a, j+1, right);
    }
}
//Partition
int partition(int a[], int left, int right)
{
    int v, i, j, temp;
    v = a[left];
    i = left;
    j = right + 1;
    
    do
    {
        do
            i++;
        
        while(a[i] < v && i <= right);
        
        do
            j--;
        while(v < a[j]);
        
        if(i<j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while(i < j);
    
    a[left] = a[j];
    a[j] = v;
    
    return(j);
}

//Declaration of Main Program
int main()
{
    int a[250]; //Array of 250 elements
    int n = 250; //Max size of array
    int i;
    
    for(i = 0; i < n; i++)              //Prints Array before sorting
        a[i] = rand() % 999 + 1;
        cout << "\nArray before sort: ";
    
    for(i = 0; i < n; i++)              //Formats a space between each element
        cout << a[i] << " ";
    
    quick_sort(a, 0, n-1);              //Prints Array after sorting
    cout << "\n\nArray after sort: ";
    
    for(i=0; i<n; i++)                  //Formats a space between each element
        cout<< a[i] << " ";
    
    return 0;
}
