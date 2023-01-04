/*  Tony Nguyen
    January 18th, 2022
    CSPS 121 02
    Programming Assignment #1: Hello
*/

#include <iostream> /// This one is for the iostream library to execute cout, cin, endl, etc.
#include <string>   /// This one is for the string objects
using namespace std;

int main () ///Starting clause
{
    string userName;    /// Declare the type of variable

    cout << "Hello, my name is Tony." << endl;  /// Introducing my name
    cout << "What is your name?" << endl;   /// Asking the user's name
    cin >> userName; /// The variable that saves the user's name
    cout << "Nice to meet you, " << userName << endl; /// Responding to the previous question

    return 0;
}
