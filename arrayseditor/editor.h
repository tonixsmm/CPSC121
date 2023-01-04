/*
    Author: Tony Nguyen
    CPSC 121 02
    18 March 2022
    PA6: Array Editor
*/

//This is the header file

#ifndef ARR_EDIT_H
#define ARR_EDIT_H

#include <iostream>
#include <string>
using namespace std;

//Function prototypes
void replaceArray (int inArray[], int value, int location, int size);
bool seachArray (int inArray[], int value, int size);
int checkQuantity (int inArray[], int value, int size);
int findMin (int inArray[], int size);
int findMax (int inArray[], int size);
bool compareArray (int inArray1[], int inArray2[], int size);

#endif