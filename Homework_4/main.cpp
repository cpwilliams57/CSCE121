//
//  main.cpp
//  Homework_4
//
//  Created by Cody Williams on 9/19/16.
//  Copyright © 2016 Cody Williams. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <iomanip>
#include <string>
#include <stdio.h>
using namespace std;


int main() {
    
    //initializing vaariables to be used
    int numdigits = -1;
    int i = 0;
    int j = 0;
    int bulls = 0;
    int cows = 0;
    
    //vector where computer generated interger is stored by digits
    vector<int> generatednum;
    vector<int> code;
    vector<int> tempcode;
    //random generator will produce different results each time
    srand(time(0));
    
    //asks user to input value for numdigits until a correct value is given
    while((numdigits != 0) && (numdigits != 3) && (numdigits != 4) && (numdigits != 5)){
        cout << "Enter number of digits in code (3, 4 or 5): " ;
        cin >> numdigits;
        //cout << endl;
    }
    
    //If user inputs zero
    if(numdigits == 0){
        cout << "This happens if user inputs zero" << endl;
    }
    
    // if user inputs 3,4,or 5
    else if ((numdigits != 0)){
        
        //creates a vector of random intergers 0-9, no number repeated
        for( int i = 0; i < numdigits; ++i){
            int digit = rand() % 10;
            for(int j = 0; j < i; ++j){
                while(digit == generatednum.at(j)){
                    digit = rand() % 10;
                }
            }
            generatednum.push_back(digit);
        }
        
        
        //prints the vector produced above
        cout << "Number to guess: ";
        for(int i = 0; i < numdigits; ++i){
            cout << generatednum.at(i);
        }
        cout << endl;
        
        
        while(bulls != numdigits){
            //1) accept input
            //2) check to see if it is a valid input
            //3) count number of bulls and cows
            //4) repeat process
            bulls = 0;
            cows = 0;
            int num = -1;
        
            // 1)getting users guess as a number, converting it to a string
            //*******get guess as an int and turn int into an array
            cout << "Enter guess: ";
            int input = 0;
            cin >> input;
            
            //putting individual digits of guess into a vector
            for(i = 0; i < numdigits; ++i){
                num = input % 10;
                tempcode.push_back(num);
                input = input / 10;
            }
            
            for(i = tempcode.size()- 1; i >= 0; --i){
                code.push_back(tempcode.at(i));
            }
            
            cout << code.size() <<  endl;
        
            //initializing conditions for checking
            bool isgood = false;
            bool checkagain = true;
            
            // 2) checking to see if user input had the correct number of digits and does not repeat
            while((isgood == false) && (checkagain == true)){
                if((code.size() != numdigits)){
                    cout << "You can only enter " << numdigits << " digits." << endl;
                    cout << "Enter guess: ";
                    cin >> input;
                    isgood = false;
                    checkagain = true;
                }
                
                //checking to see if there are repeating numbers in the guess
                else if(checkagain == true){
                    for(i = 1; i < numdigits; ++i){
                        for( j = 0; j < i; ++j){
                            if( code.at(j) == code.at(i)){
                                cout << "Each number must be different " << endl;
                                cout << "Enter guess: ";
                                cin >> input;
                            }
                        }
                    }
                    checkagain = false;
                }
                
                //occurs if there are no repeating numbers or incorrect number of digits (exits loop)
                else{
                    isgood = true;
                    checkagain = false;
                }
            }
            // 3) counting number of bulls and cows and printing number to the user
            for( i = 0; i < numdigits; ++i){
                for( j = 0; j < numdigits; ++j){
                    if(code.at(j) == generatednum.at(i)){
                        if( j == i){
                            bulls = bulls + 1;;
                        }
                        else if(j != i){
                            cows = cows + 1;
                        }
                    }
                }
            }
            cout << bulls << " bulls" << endl;
            cout << cows << " cows" << endl;
        }
        
    }
    
    return 0;
}
