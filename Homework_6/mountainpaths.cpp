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
#include <climits>
#include <cmath>
using namespace std;

//function definition
int colorPath(const vector<vector<int>>& mapdata, vector<vector<int>>& r, vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g, int color_b, int start_row){
    
    
    int elevation_change = 0, up=0, down=0, fwd=0, curr_row = start_row;
    int numCols = mapdata[0].size();
    
    r[curr_row][0] = color_r;
    
    g[curr_row][0] = color_g;
    
    b[curr_row][0] = color_b;
    //Color g and b
    
    
    for(int j = 0; j < numCols - 1; ++j)
    {
        up = (curr_row > 0) ? abs(mapdata[curr_row-1][j+1] - mapdata[curr_row][j]) : INT_MAX;
        down = (curr_row < mapdata.size() - 1) ? abs(mapdata[curr_row+1][j+1] - mapdata[curr_row][j]) : INT_MAX;
        fwd = abs(mapdata[curr_row][j+1] - mapdata[curr_row][j]);
        
        
        if (fwd<=up and fwd<=down)
        {
            curr_row = curr_row;
            elevation_change += fwd;
            //Go forward
        }
        
        
        else if (down <= up)
        {
            curr_row+=1;
            
            elevation_change+=down;
            
            //Go down
            
        }
        
        
        else
        {
            curr_row-=1;
            elevation_change+=up;
            //Go up
        }
        
        
        r[curr_row][j+1]  = color_r;
        
        g[curr_row][j+1]  = color_g;
        
        b[curr_row][j+1]  = color_b;
        //Color data[updated_row][j+1]
        
    }
    
    return elevation_change;
    
}



int main() {
    
    //initializing variables and creating vectors
    int numrows = -1;
    int numcols = -1;
    int i = 0;
    int j = 0;
    int sizecheck;
    vector<double> numbers;
    vector<vector<int>> griddata;
    vector<int> row;
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
    
    
    //creating 1d vector to push back new scaled values.
    vector<int> scaledrow;
    
    //creating parallel vectors
    vector<vector<int>> r_val;
    vector<vector<int>> g_val;
    vector<vector<int>> b_val;
    
    
    for(int i = 0; i < numrows; ++i  ){
        scaledrow.erase(scaledrow.begin(),scaledrow.end());
        for(int j = 0; j < numcols; ++j){
            double val = griddata[i][j];
            int temp = (val - min) * scale;
            scaledrow.push_back(temp);
        }
        r_val.push_back(scaledrow);
        b_val.push_back(scaledrow);
        g_val.push_back(scaledrow);
    }
    
    int elevation_change = colorPath(griddata, r_val, g_val, b_val, 252, 25, 63, 0);
    
    elevation_change = colorPath(griddata, r_val, g_val, b_val, 252, 25, 63, numrows-1);
    
    elevation_change = colorPath(griddata, r_val, g_val, b_val, 252, 25, 63, numrows/2);
    
    
    //writing .ppm format to an output file
    output << "P3" << endl;
    output << numcols << " " << numrows << endl;
    output << "255" << endl;
    
    for(i = 0; i < numrows; ++i){
        for(j = 0; j < numcols; ++j){
            output << r_val.at(i).at(j) << " ";
            output << g_val.at(i).at(j) << " ";
            output << b_val.at(i).at(j) << "\t";
        }
        output << endl;
    }
    
    output.close();
    
    return 0;
    
}
