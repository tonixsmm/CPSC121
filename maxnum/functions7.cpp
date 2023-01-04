/*  Author: Jo Crandall
    CPSC 121 Function Basics 7
    Feb 2022
    Gonzaga University
    This program demonstrates driver programs.
*/

#include "maxnum.h"
// #include <iostream>
// using namespace std;

/// Note the use of default arguments
//int maxNumber(int num1 = 9, int num2 = 13);


//This is a driver to test the maxNumber() function.
int main(){

    //Test maxNumber with two negative ints
    cout << maxNumber(-2,-3) << endl;

    //Test maxNumber with one positive and one negative int

    //Test maxNumber with default args

    //Test maxNumber with one arg



    return 0;
}

/*This function accepts two integers and returns the larger of the two.
* (If the integers are equal, the first value is returned)
* Default args: num1 = 9, num2 = 13.*/
// int maxNumber(int num1, int num2){
//     if (num1 >= num2){
//         return num1;
//     }
//     else return num2;
// }

