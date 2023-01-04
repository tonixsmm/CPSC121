/*  Author: Jo Crandall
    CPSC 121 Function Basics
    Jan 26, 2022
    Gonzaga University
    This program demonstrates function basics: name, parameters, returns, calling.
*/

#include <iostream>
using namespace std;

/*  This function doubles a number that it receives.
    Input: one integer (number to be doubled)
    Output: one integer (twice the input number)
*/
int doubleNum(int inputNum){
    int newNum = 2 * inputNum;
    return newNum;
}

/*  This function adds two numbers together.
    Input: two doubles
    Output: one double ( the sum of the inputs )
*/
double addNums(double num1, double num2){
    return num1 + num2;
}

int main(){

    int coolNum;
    coolNum = doubleNum(5);   //here I am CALLING (using) the doubleNum function. 

    return 0;
}

