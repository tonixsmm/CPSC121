/*  Author: Jo Crandall
    CPSC 121 Function Basics 3
    Feb 2022
    Gonzaga University
    This program demonstrates variable scope, global, const, and static.
*/

#include <iostream>
using namespace std;

///Here are the function prototypes:
void myFunc(void);
void myOtherFunc(void);
bool yetAnotherFunc(void);
void amazingFunc(void);
void theLastFunc(void);
int reallyTheLastFunc(void);
int okThisIsIt(const int);


/// because these two variables are defined outside main(), they are GLOBAL variables
int globalInt = 0;     //this is a global VARIABLE ==> BAD!!!                 
const double GLOBAL_CONST = 3.14;    //this is a global CONSTANT ==> GOOD!

int main(){

    //getline!!

    /// global vars can be seen within any of the functions (but beware of variables with same name that have block scope)
    
    cout << "Here's the value of globalInt: " << globalInt << endl;
    myFunc();  /// this function changes the value of globalInt
    cout << "Now here's the value of globalInt: " << globalInt << endl;
    //// what happened??

    // myOtherFunc();     /// this function creates the variable localInt
    //cout << "The value of localInt is: " << localInt << endl;

    /// Global constants can also be seen inside any function, but they CANNOT be changed by the code during runtime.
    // bool flag = yetAnotherFunc();
    // cout << "GLOBAL_CONST is 3.14? " << flag << endl;

    /// Variables and their values are "destroyed" between function calls
    // amazingFunc();
    // amazingFunc();
    // amazingFunc();
    // amazingFunc();
    
    ///... but a STATIC variable can have its value remembered
    theLastFunc();
    theLastFunc();
    theLastFunc();
    theLastFunc();

    // here we get the value RETURNED from the function, so we can print it here in main()
    cout << "result is: " << reallyTheLastFunc() << endl;
    cout << "result is: " << reallyTheLastFunc() << endl;
    cout << "result is: " << reallyTheLastFunc() << endl;
    cout << "result is: " << reallyTheLastFunc() << endl;
    
    /// A function that has a const modifier on a parameter is unable to change that parameter value
    // cout << okThisIsIt(4) << endl;

    return 0;
}

//This function sets the value of globalInt to 100.
void myFunc(void){
    globalInt = 100;
}

//This function sets the value of localInt to 42.
void myOtherFunc(void){
    /// A variable defined inside a function is a LOCAL VARIABLE
    /// It can only be seen inside that function
    int localInt = 0;
    cout << "Here's the value of localInt: " << localInt << endl;
    localInt = 42;
    cout << "Now here's the value of localInt: " << localInt << endl;
}

bool yetAnotherFunc(void){
    if (GLOBAL_CONST == 3.14){
        return true;
    }
    else return false;
}

void amazingFunc(void){
    int someVar = 0;
    someVar++;
    cout << "someVAr now has: " << someVar << endl;
}

void theLastFunc(void){
    static int staticInt1;
    staticInt1++;
    cout << "staticInt1 now has: " << staticInt1 << endl;;
}

int reallyTheLastFunc(void){
    static int staticInt2;
    staticInt2++;
    return staticInt2;
}

// int okThisIsIt(const int num){
    //This function can't change the incoming value 'num' since it came in as a const
//     num = num + 5;
//     return num;
// }