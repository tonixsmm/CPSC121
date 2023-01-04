#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int userInput;
    cout << "Enter number: ";
    cin >> userInput;

    // Part 1
    for (int i = 1; i <= userInput; i++){
        for (int j = 1; j <= i; j++){
            cout << i;
        }
        cout << endl;
    }

    // Part 2
    for (int i = 1; i <= userInput; i++){
        for (int j = 1; j <= i; j++){
            cout << i;
        }
        cout << " " << i * i;
        cout << endl;
    }

    return 0;
}