#include <iostream>
using namespace std;

int main()
{
    const float GRADE_A = 90;
    const float GRADE_B = 80;
    const float GRADE_C = 70;
    const float GRADE_D = 60;

    float yourGrade;

    cout << "What is your grade?" << endl;
    cin >> yourGrade;

    if (yourGrade >= GRADE_A)
    {
        cout << "You grade is A" << endl;
    }
    else if (yourGrade >= GRADE_B)
    {
        cout << "Your grade is B" << endl;
    }
    else if (yourGrade >= GRADE_C)
    {
        cout << "Your grade is C" << endl;
    }
    else if (yourGrade >= GRADE_D)
    {
        cout << "Your grade is D" << endl;
    }
    else 
    {
        cout << "Your grade is F" << endl;
    }
    return 0;
}