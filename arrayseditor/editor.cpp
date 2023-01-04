/*
    Author: Tony Nguyen
    CPSC 121 02
    18 March 2022
    PA6: Array Editor
*/

//This is the implementation file

#include "editor.h"

/*Fucntion to replace a given index with a given data
  Inputs: an integer array, wanted value, array index, array size
  Outputs: void
  Assumption: The given array type is integer and the replacement value is also an integer
*/
void replaceArray (int inArray[], int value, int location, int size){
    inArray[location] = value;
    cout << "The replaced version is ";
    for (int i = 0; i < size; i++){
        cout << inArray[i] << " ";
    }
    cout << endl;
}

/*Fucntion to search if there is the desired value in the array
  Inputs: an integer array, wanted value, array size
  Outputs: bool, depending on the value of the array
*/
bool seachArray (int inArray[], int value, int size){
    bool search = false;
    for (int i = 0; i < size; i++){
        if (inArray[i] == value){
            search = true;
            break;
        }
    }
    if (search == true)
    {
        cout << "Value found!" << endl;
    }
    else 
    {
        cout << "Value not found!" << endl;
    }
    return 0;
}

/*Function to check how many values are there in the array
* Inputs: an integer array, array size
* Output: number of value in the array
  Assumption: array size smaller than 1000
*/
int checkQuantity (int inArray[], int value, int size){
    int num = 0;
    for (int i = 0; i < size; i++){
        if (inArray[i] == value){
        num++;
        }
    }
    cout << "Quantity of value " << value << " is " << num << endl;
    return 0;
}

/*Function to find the minimum value in the array
* Inputs: an integer array, array size
* Output: the minimum value in the array
*/
int findMin (int inArray[], int size){
    int min = inArray[0];
    for (int i = 1; i < size; i++){
        if (inArray[i] < inArray[0]){
            min = inArray[i];
        }
    }
    cout << "Minimum value is " << min << endl;
    return 0;
}

/*Function to find the maximum value in the array
* Inputs: an integer array, array size
* Output: the maximum value in the array
*/
int findMax (int inArray[], int size){
    int max = inArray[0];
    for (int i = 1; i < size; i++){
        if (inArray[i] > inArray[0]){
            max = inArray[i];
        }
    }
    cout << "Maximum value is " << max << endl;
    return 0;
}

/*Function to compare two arrays to see if equal
* Inputs: two integer arrays
* Output: bool, whether arrays equal
*/
bool compareArray(int inArray1[], int inArray2[], int size){
    bool equal = true;
    for (int i = 0; i < size; i++){
        if (inArray1[i] != inArray2[i]){
            equal = false; 
            break;
        }
    }
   if (equal == true)
    {
        cout << "Equal arrays!" << endl;
    }
    else 
    {
        cout << "Arrays not equal!" << endl;
    }
    return 0;
}
