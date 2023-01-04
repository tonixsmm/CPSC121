/*  Author: Jo Crandall
    CPSC 121 Hello World
    Jan 14, 2022
    Gonzaga University
    This is a comment block to communicate to myself and other programmers essential info about this program.
    This program displays Hello World! to the screen and asks the user for a name and a number.
*/


/// Triple ///'s are meant to explain concepts. Double //'s are lines of code for you to un-comment and run.


#include <iostream>    /// This line is necessary for objects such as cout, cin, and endl
#include <string>      /// This line is necessary for using string objects
using namespace std;   /// More on this later...

int main(){        /// Every C++ program MUST have a main() function. This is the place your program 'starts'
    /// cout << "Hello World!" << endl; /// prints Hello World to the screen
    /// I can put a comment anywhere in my program

    /// Try again without using endl:
    //cout << "Hello World!";
    /// What changed?

    /// Try without using quotes:
    //cout << Hello World!;

    /// Declare a string variable to hold a name the user will enter:
    string inputName;

    /// Now ask the user to enter a name:
    cout << "What's your name?" << endl;
    cin >> inputName;   /// This line is how we store the user's answer in the variable inputName

    /// We can see that the name is stored in the variable:
    cout << inputName;

    /// We can also ouput multiple things with the << operator
    cout << "So your name is" << inputName << endl;
    /// What might we want to change about this output??
    
    /// Declare an integer variable to hold number user will enter, then get and store user answer
    //int inputNum;
    //cout << "What's your favorite number?" << endl;
    //cin >> inputNum;

    /// Put together multiple outputs:
    //cout << "so your name is" << inputName << "and your number is" << inputNum <<endl;


    return 0;  /// Every main() ends with return 0; by convention. It basically means exited successfully.
}