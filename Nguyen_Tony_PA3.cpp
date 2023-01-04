/*
    Author: Tony Nguyen
    February 2, 2022
    CPSC 121 02
    Programming Assignment #3: Mystery Number
*/
#include <iostream>
#include <string>
using namespace std;

// Doubling function
int doubleNum (int num) 
{
    int doubleNumResult = num * 2;
    return doubleNumResult;
}

// Subtracting three function
int minusThree (int num) 
{
    int minusThreeResult = num - 3;
    return minusThreeResult;
}

// Check even-odd function
int modTwo (int num) 
{
    int modTwoResult = num % 2;
    return modTwoResult;
}

int main () 
{
    // Generating a random number
    unsigned seed = time (0);
    srand(seed);
    int mysteryNum = 1 + rand() % 20;
    
    // Declaring variables
    int hintNum;
    int guessNum;

    // Checking and giving the first hint
    hintNum = modTwo(mysteryNum);
    if (hintNum == 0)
    {
        cout << "Here is your first hint, the number is even. Enter your guess" << endl;
    }
    else 
    {
        cout << "Here is your first hint, the number is odd. Enter your guess" << endl;
    }
    cin >> guessNum;

    // Doubling the mystery number if the first guess is not correct
    if (guessNum != mysteryNum)
    {
        cout << "Incorrect! Here is your next hint, the number doubled is " << doubleNum(mysteryNum) << ". Enter your guess" << endl;
        cin >> guessNum;
    }
    
    // Subtracting three from the mystery number if the second guess is not correct
    if (guessNum != mysteryNum)
    {
        cout << "Incorrect! Here is your next hint, the number is subtracted by three is " << minusThree(mysteryNum) << ". Enter your guess" << endl;
        cin >> guessNum;
    }
    
    // Informing that you are out of attempts
    if (guessNum != mysteryNum)
    {
        cout << "Sorry! You run out of attempts. The mystery number is " << mysteryNum << endl;
    }
    
    // Congratulate if the guess is correct
    else 
    {
        cout << "Congratulation! The mystery number is " << mysteryNum << endl;
    }
    
    return 0;
}