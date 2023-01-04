#include <iostream>
#include <string>
using namespace std;

int main ()
{
    int totalTime = 0;
    int userTime;
    int trainingDays;

    while (totalTime < 50 || trainingDays >= 25)
    {
        cout << "Enter your time" << endl;
        cin >> userTime;
        totalTime += userTime;
        cout << "Your total time: " << totalTime;
        trainingDays++;
    }
    return 0;
}