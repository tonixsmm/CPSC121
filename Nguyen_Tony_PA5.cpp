/*  
    Tony Nguyen
    28 February 2022
    CPSC 121 02
    PA5: Mad Lib Generator
*/

#include <iostream> //flush
#include <fstream>  //for ifstream and ofstream
#include <string>   //for using string-related functions
using namespace std;

//Declare variables
ifstream inFile;
ofstream outFile;

//This function accepts no argument
//It returns the first line of text in two consecutive lines, from the file
//It prints the first line of text in two consecutive, to a new file
void readFile(void)
{
    //Declare variable
    string textFromFile;
    //Writing the function
    getline(inFile, textFromFile);  //Read the line
    cout << textFromFile << endl;   //Print the text to user
    outFile << textFromFile << endl;//Print the text to a new file
}

//This function accepts no argument
//It returns the second line of text in two consecutive lines, from the file
//It prints the second line of text in two consecutive lines, to a new file
void writeFile(void)
{
    //Declare variables
    string userInput1;
    string userInput2;
    //Writing the function
    getline(inFile, userInput1);    //Read the line
    cout << "Enter a " << userInput1 << ". If more than one word, write them together WITHOUT the space" << endl;   //Print the prompt for user to type in
    cin >> userInput2;  //User type in
    outFile << userInput2; //Print what user types in to a new file
}

//This function accepts no argument
//This function controls the command lines and does not return anything
void letsgo(void)
{
    cout << "Welcome to Mad Lib Generator!" << endl;
    //While-loop to execute functions
    while (!inFile.eof())
    {
        readFile();
        writeFile();
    }
}

//This function accepts no argument
//It returns the text from the new file
void printFile(void)
{
    //Declare variable
    string result;
    //Writing the function
    cout << endl;
    cout << "Here is your Mad Lib:" << endl;
    while (!inFile.eof())
    {
        getline(inFile, result);
        cout << result << endl;
    }
}

//Main function
int main()
{
    inFile.open("lib_input.txt", ios::in); //Open the original text file
    outFile.open("mylib.txt", ios::app); //Create a new file to save the story

    //Call the control function
    letsgo();

    //Close both file
    inFile.close();
    outFile.close();

    //Print out the content for the text file
    inFile.open("mylib.txt", ios::in); //Open file
    printFile(); //Print file
    inFile.close(); //Close file

    return 0;
}