/*
    Author: Tony Nguyen
    CPSC 121 02
    18 March 2022
    PA6: Array Editor
*/

//This is the main file

#include "editor.h"

int main(){

    int myArray1[5] = {1, 2, 3, 4, 5};
    int myArray2[5] = {1, 2, 3, 4, 5};
    int myArray3[5] = {6, 7, 8, 9, 10};
    int myArray4[5] = {1, 2, 2, 4, 5};

    //Testing the searchArray function
    seachArray(myArray1, 4, 5);
    seachArray(myArray3, 2, 5);

    //Testing the checkQuantity function
    checkQuantity(myArray1, 5, 5);
    checkQuantity(myArray4, 2, 5);

    //Testing the findMin function
    findMin(myArray1, 5);
    findMin(myArray3, 5);

    //Testing the findMax function
    findMax(myArray1, 5);
    findMax(myArray3, 5);

    //Testing the compareArray function
    compareArray(myArray1, myArray2, 5);
    compareArray(myArray1, myArray3, 5);

    //Testing the replaceArray function
    replaceArray(myArray1, 15, 3, 5);
    replaceArray(myArray3, 3, 3, 5);

    return 0;
}