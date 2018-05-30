//
//  main.cpp
//  Week1AssignmentWarmUp
//
//  Created by Harrison Senesac on 5/13/18.
//  Copyright © 2018 Harrison Senesac. All rights reserved.
//
//Support and Reference provided by Derek Banas YouTube Videos
// Link: https://www.youtube.com/watch?v=Rub-JsjMhWY

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


class Animal
{
    //protected variables are accessible in the class that defines them and in classes that inherit from that class.
protected:
    int id;
    
    // private variables are only available to methods in the class
private:
    int height;
    int weight;
    string name;

    
    // A static variable shares the same value with every object in the class
    static int numOfAnimals;
    
    // Public variables can be accessed by anything with access to the object
public:
    int getHeight(){return height;}
    int getWeight(){return weight;}
    string getName(){return name;}
    void setHeight(int cm){ height = cm; }
    void setWeight(int kg){ weight = kg; }
    void setName(string dogName){ name = dogName; }
    
    // Declared as a prototype
    void setAll(int, int, string);
    
    // Declare the constructor
    Animal(int, int, string);
    
    // Declare the deconstructor
    ~Animal();
    
    // An overloaded constructor called when no data is passed
    Animal();

    static int getNumOfAnimals() { return numOfAnimals; }
    
    // This method will be overwritten in Dog
    void toString();
    
};

//Abstract Class with Secondary Derived
class Car{
    public :
        virtual int getNumWheels() = 0;
        virtual int getNumDoors() = 0;
};

class StationWagon : public Car{
    public :
        int getNumWheels() { cout << "Station Wagon has 4 Wheels" << endl; }
        int getNumDoors() { cout << "Station Wagon has 4 Doors" << endl; }
        StationWagon() { }
        ~StationWagon();
    
};

int main(){
    
    // Create a StationWagon using the abstract data type Car
    Car* stationWagon = new StationWagon();
    
    stationWagon -> getNumWheels();
    
    //This is a reference example
    int myAge = 22;
    //A reference to the location of the integer variable myAge
    cout << "My age is located at: " << &myAge << endl;
    
    //A pointer example that uses a pointer to reference the memory location as well as the data itself
    int* agePtr = &myAge;
    cout << "Address of myAge: " << agePtr << endl;
    cout << "My Age: " << *agePtr << endl;
    
    return 0;
}

