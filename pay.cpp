#include <iostream>
using namespace std;

double computePay (double hours, double rate)
{
    double pay = 0;
    if (hours < 40)
    {
        pay = hours * rate;
    }
    else 
    {
        pay = 40 * rate;
    }
    return pay;
}

int main()
{
    double myHours = 10;
    double myRate = 45.00;
    cout << "My pay is " << computePay(myRate,myHours) << endl;
    return 0;
}