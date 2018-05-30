//
//  main.cpp
//  Week4Stacks
//
//  Created by Harrison Senesac on 6/6/17.
//  Copyright © 2017 Harrison Senesac. All rights reserved.
//  Help provided: MyCodeSchool. Balanced Parentheses. Computer software. GitHubGist. Vers. 1. GitHub, n.d. Web. 6 June 2017.

#include<iostream>
#include<stack>
#include<string>
using namespace std;

//Method to check if opening and closing match
bool paired(char opening, char closing)
{
    if(opening == '(' && closing == ')') return true;
    else if(opening == '{' && closing == '}') return true;
    else if(opening == '[' && closing == ']') return true;
    return false;
}

//Stack to compare parentheses
bool parenthesesBalanced(string input)
{
    stack<char>  Stack;
    
    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] == '(' || input[i] == '{' || input[i] == '[')
            Stack.push(input[i]);
        else if(input[i] == ')' || input[i] == '}' || input[i] == ']')
        {
            if(Stack.empty() || !paired(Stack.top(), input[i]))
                return false;
            else
                Stack.pop();
        }
    }
    return Stack.empty() ? true:false;
}

//Main Program
int main()
{
    
    string input;
    cout<<"Enter characters and parentheses:  "; // input
    cin>>input;
    
    //Output
    if(parenthesesBalanced(input))
        cout<<"Input is Balanced\n";
    else
        cout<<"Input is not Balanced\n";
}
