/*  Author: Jo Crandall
    CPSC 121 Function Basics 2
    Feb 2022
    Gonzaga University
    This program demonstrates function basics: declaration, implementation, calling.
*/

#include <iostream>
#include <fstream>
using namespace std;

int doubleFileInput( string fileName );    //this is the function prototype. Notice no instructions inside function are included yet
void sqNum(int);
void addNum (int,int);
double subNum (double, double);
int readNumFromFile(string);

int main(){

    //Let's write some prototypes and implementations....
    
    //function to square an integer and print result to screen - 1 arg, void return type

    sqNum(8);

    //function to take a filename as a string and return something read from file - 1 arg, return type?

    doubleFileInput("nums.txt");
    readNumFromFile("nums.txt");
    
    //function to add two nums and print sum to screen - 2 args, void return type

    addNum (3,4);

    //function to subtract two nums and return difference - 2 args, double return type

    subNum(8,2);


    return 0;
}

double subNum(double num1, double num2)
{
    cout << num1 - num2 << endl;
    return 0;
}

void sqNum(int num)
{
    float squareNum;
    squareNum = num * num;
    cout << squareNum << endl;
}

void addNum(int num1,int num2)
{
    cout << num1 + num2 << endl;
}

int readNumFromFile (string fileName)
{
    ifstream inFile;
    string theNum;
    inFile.open(fileName);
    inFile >> theNum;
    cout << theNum << endl;
    inFile.close();
    return 0;
}

int doubleFileInput( string fileName ){      ///this is the function implementation (after main) where we add in the instructions in the body
    ifstream inFile;
    int inNum, doubleNum = -1;
    inFile.open(fileName);
    while (inFile >> inNum){
        doubleNum = inNum * 2;
        cout << inNum << " doubled is " << doubleNum << endl;
    }
    if (!inFile){
        cout << "No int to read from file: " << fileName << endl;
        inFile.close();
    }
    return doubleNum;
}