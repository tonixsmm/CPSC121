#include <iostream>
using namespace std;


void func(void)
{
    int num = 1;
    cout << num << endl;
    num++;
    cout << num << endl;
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        func();
    }
    return 0;
}