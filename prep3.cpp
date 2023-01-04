#include <iostream>
using namespace std;

int myFunc(int num){
    string myStr = "banana";
    return 42;
}

// int myfunc(){
//     rand
// }

int main(){
    //int someVar;
    cin >> int someVar;

    //int i starts at 5, goes while less than 10, increments by 1, each time cout "hi"
    //for loop
    for( int count = 5 ; count < 10 ; count++ ){
        cout << "hi" << endl;
    }

    //while loop
    int i = 5;
    while( i <= 10 ){
        cout << "hi" << i << endl;
        i++;
    }
    cout << "hi\t"

    if(){
        if(){

        }
        else{

        }
    }
    else if(){
        ....
    }
    else{
        ....
    }



    // int myNum = myFunc(2);
    // cout << myStr;

    //modulus
    // int a = 27;
    // int result = a % 6;
    // cout << result << endl;

    // result = a % 5;
    // cout << result << endl;
   
    // result = a % 9;
    // cout << result << endl;

    // if(a % 9 == 0){ //if a is evenly divisible by 9...
    //     .....
    // }

    // int b = 1;
    // switch(b){
    //     case 2: .......; 
    //     case 1: .......
    // }
    //unsigned seed = time(0);
    // srand(time(0));
    // int randnum = rand() % 5;
    // cout << randnum << endl;
    float myDecNum = 3.14;
    double myOtherDecNum = 2.72;

    //block scope
    if(myDecNum < 4){
        double coolVar = 3;
    }

    cout << coolVar << endl;

    while(true){
        float otherVar = 2;
    }
    cout << otherVar;

    return 0;
}