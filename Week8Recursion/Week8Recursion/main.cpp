//
//  main.cpp
//  Week8Recursion
//
//  Created by Harrison Senesac on 10/22/17.
//  Copyright © 2017 Harrison Senesac. All rights reserved.
//

#include <iostream>
using namespace std;

//Recursive Method for calculating Int to Hex
void calc_hex(int value)
{
    if (value == 0)
        return;
    
    int remainder = value % 16;
    value /= 16;
    calc_hex(value); //Recursive Call to method
    
    //After return print less significant digit
    if (remainder > 9)
        cout << (char)(remainder - 10 + 'A');
    else
        cout << remainder;
}

//Main Function
int main(int argc, char * argv[]) {
    cout << "Enter Whole Integer: ";
    int num;
    cin >> num;
    calc_hex(num);
    cout << endl;
    return 0;
}
