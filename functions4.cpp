/*  Author: Jo Crandall
    CPSC 121 Function Basics 4
    Feb 2022
    Gonzaga University
    This program demonstrates overloading functions.
*/

#include <iostream>
using namespace std;

/// function prototypes
double tuitionCost(int credits, bool inState);   /// v1   /// notice that all three have SAME FUNCTION NAME
double tuitionCost(bool inState);                /// v2   /// This is an example of OVERLOADED functions
void tuitionCost(void);                          /// v3   /// There are multiple versions to handle different argument types

/// declare global constants
const double INSTATE = 500;    /// the in-state cost per credit
const double OUTSTATE = 650;

int main(){

    /// There are many times when we want to use the same essential function (or similar function) but with different args
    /// Overloading functions can allow us to re-use the same function name in logical ways

    /// Ask the user whether they are in-state or out-of-state, and how many credits......
    string studentType;
    int creditNum;
    bool studentTypeBool;
    cout << "State if you are in-state or out-of-state: " << endl;
    cin >> studentType;
    cout << "How many credits do you have?" << endl;
    cin >> creditNum;
    if (studentType == "in-state")
    {
        studentTypeBool = true;
    }
    else 
    {
        studentTypeBool = false;
    }
    /// Call the appropriate version of the function......
    
    cout << "Tuition is: " << tuitionCost(studentTypeBool) << endl;        /// here I am calling the function with only a bool -> which version?
    cout << "Tuition is: " << tuitionCost(creditNum,studentTypeBool) << endl;    /// here I am calling the function with an int and a bool -> which version?
    tuitionCost();                              /// here I am calling the functin with no args -> which version?

    return 0;
}

/// Note that as we write functions, we need to write a comment block for each function definition...

/*This function computes the cost of tuition.
* Arguments: number of credits as integer, inState status as bool
* Return: cost of tuition as double
* Assumptions: Number of credits is fifteen or fewer. 
*/
double tuitionCost(int credits, bool inState){
    if (inState){
        return credits * INSTATE;     ///you may still need other comments INSIDE the function itself!
    }
    else return credits * OUTSTATE;
}

/*This function computes the cost of tuition.
* Argumentt: inState status as bool
* Return: cost of tuition as double
* Assumptions: Number of credits is above fifteen. 
*/
double tuitionCost(bool inState){
    if (inState){
        return 16 * INSTATE;
    }
    else return 16 * OUTSTATE;
}

/*This function reports average cost of tuition.
* Arguments: none
* Return: none
*/
void tuitionCost(void){
    cout << "Average tuition cost is: " << 15 * INSTATE << endl;
}