//
//  main.cpp
//  Homework_3
//
//  Created by Cody Williams on 9/17/16.
//  Copyright © 2016 Cody Williams. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;


int main() {
    
    //initializing vaariables to be used
    int numdigits = -1;
    int code = -1;
    vector<int>numbervec;
    int i = 0;
    int j = 0;
    int digit = -1;
    srand(time(0));
    
    //asks user to input value for numdigits until conditions are met
    while((numdigits != 0) && (numdigits != 3) && (numdigits != 4) && (numdigits != 5)){
        cout << "Enter number of digits in code (3, 4 or 5): " ;
        cin >> numdigits;
        //cout << endl;
    }
    
    //if user input = 0
    if(numdigits == 0){
        
        //gets code, number of digits, turns code into a string that can be accessed
        cout << "Enter Code: ";
        cin >> code;
        cout << "Enter number of digits in code: ";
        cin >> numdigits;
        string usercode = to_string(code);
        
        //if the number of digits is not equal to the code size (will there be zeros in front?)
        if(numdigits != usercode.size()){
            vector<char> usernum(numdigits, '0');
            
            //creating variable for # of zeros
            int difference = (numdigits - usercode.size());
            
            //fills vector usernum with usercode in appropriate spot
            for(int i = 0 ; i < usercode.size(); ++i){
                usernum.at(i + difference) = usercode.at(i);
            }
            
            //prints zeros then string usercode (containing number)
            cout << "Number to guess: ";
            
            for(int i = 0; i < numdigits; ++i){
                cout << usernum.at(i);
            }
            
            cout << endl;
            
            
        }
        
        //prints number user entered
        else {
            cout << "Number to guess: " << code;
            cout << endl;
        }
    }
    
    //user input = 3,4 0r 5
    else{
        
        //creates a vector of random intergers 0-9, no number repeated
        for( i = 0; i < numdigits; ++i){
            digit = rand() % 10;
            for(j = 0; j < i; ++j){
                while(digit == numbervec.at(j)){
                    digit = rand() % 10;
                }
            }
            numbervec.push_back(digit);
        }
        
        //prints the vector produced above
        cout << "Number to guess: ";
        for(i = 0; i < numdigits; ++i){
            cout << numbervec.at(i);
        }
        cout << endl;
    }
    
    return 0;
}
