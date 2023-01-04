#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream inFile;
    string myArray[50];
    string textFromFile;
    int index = 0;
    inFile.open("bday.txt");

    while (inFile >> textFromFile)
    {
        myArray[index] = textFromFile;
        index++;
    }

    for (int i = 0; i < 17; i++)
    {
        cout << myArray[i] << endl;
    }

    inFile.close();

    return 0;

}