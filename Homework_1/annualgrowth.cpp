//
//  main.cpp
//  Homework_1
//
//  Created by Cody Williams on 9/4/16.
//  Copyright © 2016 Cody Williams. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string firstName = "";
    string lastName = "";
    int birthYear = 0;
    int feet = 0;
    int inches = 0;
    int age = 0;
    int totalInches = 0;
    double centimeters = 0;
    double avgGrowth = 0;
    
    cout << "Enter your first name" <<  endl;
    cin >> firstName;
    
    cout << "Enter your last name" << endl;
    cin >> lastName;
    
    cout << "Enter your birth year" << endl;
    cin >> birthYear;
    
    cout << "Approximately how many feet tall are you?" << endl;
    cin >> feet;
    
    cout << "Approximately how many inches?" << endl;
    cin >> inches;
    
    age = 2016 - birthYear;
    totalInches = (feet * 12) + inches;
    centimeters = totalInches * 2.54;
    avgGrowth = (centimeters - 51) / age;
    
    cout << "Hello " << firstName << " " << lastName << ". " ;
    cout << "You were " << age << " years old in 2016, and and your height is " << centimeters << " cm." << endl;
    cout << "That means that you grew an average of " << avgGrowth << " cm per year (assuming you were 51 cm at birth)." << endl;
    
    return 0;
}
