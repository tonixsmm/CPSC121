/// Implementation file for arrays4 file bundle

#include "moreTools.h"

/// if I don't want a function to modify the contents of an array, I can use const with the array parameter

// Function to print contents of array
// Arguments: array, arraysize
// Return: void
void printElements(const int inArray[], int size){
    for (int i = 0; i < size; i++){
        cout << inArray[i] << ' ';
    }
    cout << endl;
}

// Function to add 4 to each element of array
// Arguments: array, arraysize
// Return: void
void addFour(int inArray[], int size){
    for (int i = 0; i < size; i++){
        inArray[i] += 4;
    }
}

// Function to print memory address of incoming array
// Arguments: array
// Return: void
void printAddress(int inArray[]){
    cout << "The array I see in printAddress() is located at address: " << inArray << endl;
}

// Function to print elements of 2d array
// Arguments: 2d array, assumed to be size 3x2
// Return: void
void print2dElements(const int inArray[3][2]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            cout << inArray[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

// Function to print elements of 3d array
// Arguments: 3d array, assumed to be size 3x3x3
// Return: void
void print3dElements(const char inArray[3][3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                cout << inArray[i][j][k] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
}

// void printDouble(const double inArray[],[2]){