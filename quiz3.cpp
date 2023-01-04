#include <iostream>
using namespace std;

int func1(int & num)
{
    return num++;
}

int func2(int num)
{
    return num++;
}

int main()
{
    int myInt = 5;
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << func1(myInt) << endl;
    // }
    for (int i = 0; i< 10; i++)
    {
        cout << func2(myInt) << endl;
    }
    return 0;
}