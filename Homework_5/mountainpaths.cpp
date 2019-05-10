//
//  main.cpp
//  HW5_Mountain_Paths
//
//  Created by Cody Williams on 9/28/16.
//  Copyright © 2016 Cody Williams. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

int main() {
 
    //initializing variables and creating vectors
    int numrows = -1;
    int numcols = -1;
    int i = 0;
    int j = 0;
    int sizecheck;
    vector<double> numbers;
    vector<vector<double>> griddata;
    vector<double> row;
    string datafilename = "";
    bool invalid = false;
    
    //User enters number of rows in map, number of columns, and file name containing map data
    cout << "Enter number of rows: ";//(height of picture)
    cin >> numrows;
    while(numrows < 1){
        cout << "Invalid number of rows" << endl; // (height of picture)
        cout <<"Please enter a valid number of rows: ";
        cin >> numrows;
        cout << endl;
    }
    
    cout << "Enter number of columns: "; //(width of picture)
    cin >> numcols;
    while(numcols < 1){
        cout << "Invalid number of columns" << endl;
        cout <<"Please enter a valid number of columns: ";
        cin >> numcols;
        cout << endl;
    }

    //accessing data file given by user & creating output file
    cout << "Enter name of data file: ";
    cin >> datafilename;
    
    ifstream datafile (datafilename);
    string outputfilename = datafilename + ".ppm";
    ofstream output(outputfilename);
    
    //checking to see if given file exists
    if (!datafile.is_open()) {
        cerr << "Failed to open file: " << datafilename << endl;
        return 1;
    }
    
    if (!output.is_open()) {
        cerr << "Failed to create output file" << endl;
        return 1;
    }
    
  
    
    
    //filling vector with given data from file
    double num;
    while(datafile >> num){
        numbers.push_back(num);
        if(num < 0){
            invalid = true;
        }
    }
    
    //checking to see if there is enough data from users input and specified number of rows and columns
    sizecheck = numrows * numcols;
    if((numbers.size()!= sizecheck)){
        cout << "Invalid image format! Please check your output images." << endl;
        return 1;
    }
    
    //putting datapoints into a 2d vector.
    int position = 0;
    while(position < numbers.size()){
        for(int i = 0; i < numrows; ++i  ){
            row.erase(row.begin(),row.end());
            for(int j = 0; j < numcols; ++j){
                row.push_back(numbers.at(position));
                position = position + 1;
                //cout << row.at(j) << " ";
            }
            griddata.push_back(row);
        }
    }
    
    //finding min and max values
    double min = griddata[0][0];
    for( i = 0; i < numrows; ++i){
        for(j = 0; j < numcols; ++j){
            if(griddata[i][j] < min){
                min = griddata[i][j];
            }
        }
    }
    
    
    double max = griddata[0][0];
    
    for( i = 0; i < numrows; ++i){
        for(j = 0; j < numcols; ++j){
            if(griddata[i][j] > max){
                max = griddata[i][j];
            }
        }
    }
    
    
    //creating scale value
    double scale = (255.0/(max-min));
    
    
    //creating 2d vectorr with new scaled values.
    vector<vector<double>> scaleddata;
    vector<double> scaledrow;
    
    position = 0;
    while(position < numbers.size()){
        for(int i = 0; i < numrows; ++i  ){
            scaledrow.erase(scaledrow.begin(),scaledrow.end());
            for(int j = 0; j < numcols; ++j){
                double val = griddata[i][j];
                int temp = (val - min) * scale;
                scaledrow.push_back(temp);
                position = position + 1;
            }
            scaleddata.push_back(scaledrow);
        }
    }
    
    //printing info to output file

        output << "P3" << endl;
        output << numcols << " " << numrows << endl;
        output << "255" << endl;

        for(i = 0; i < numrows; ++i){
            for(j = 0; j < numcols; ++j){
                output << scaleddata[i][j] << " ";
                output << scaleddata[i][j] << " ";
                output << scaleddata[i][j] << "\t";
            }
            output << endl; 
        }
        
        output.close();
    
    return 0;
    
}
