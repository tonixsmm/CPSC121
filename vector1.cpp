/*  Author: Jo Crandall
    CPSC 121 Vector Basics
    March 2022
    Gonzaga University
    This program demonstrates STL vector (Standard Template Library).
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){

    /// Initialize a vector of integers
    /// unlike arrays, we do not have to give vectors a size
    vector<int> myIntVec;
    cout << myIntVec.size() << endl;   //vectors have several methods, size() for example

    /// We can also initialize a vector with elements
    vector<double> myDblVec{ 3.14, 35.9, 2, 11.11};   /// Notice no '=' sign to initialize in this way!!
    // cout << myDblVec.size() << endl;

    /// or we can declare a size if we want
    vector<char> myCharVec (5);
    cout << myCharVec.size() << endl;

    /// We can access individual elements just as we did with arrays
    // cout << myDblVec[0] << endl;
    /// replace the data at that location by assigning
    // myDblVec[0] = 42;
    // cout << myDblVec[0] << endl;

    /// Try a vector of strings    ... remember to #include <string>
    vector<string> myStringVec {"cat", "dog"};

    /// Traversing a vector with a for loop
    // for (int i = 0; i < myDblVec.size(); i++){
    //     cout << "The item at index " << i << " is " << myDblVec[i] << endl;
    // }

    /// Try traversing you vector of strings...
    for (int i = 0; i < myStringVec.size(); i++){
        cout << "The item at index " << i << "is " << myStringVec[i] << endl;
    }

    /// Traversing a vector with a range-based for loop
    myCharVec[0] = 'a';
    myCharVec[1] = '&';
    myCharVec[2] = '(';
    myCharVec[3] = 'z';
    myCharVec[4] = '+';
    for (char sym : myCharVec){
        cout << sym << ' ';
    }
    cout << endl;



    return 0;
}