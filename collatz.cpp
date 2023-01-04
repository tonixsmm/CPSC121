#include <iostream>
using namespace std;

int collatz_searching (int starting_house_number, int days_passed){
    int next_house;
    int k = starting_house_number;
    for (int i = 1; i <= days_passed; i++){
        if (k % 2 == 0){
            next_house = k/2;
            k = next_house;
            }
        else if (k % 2 != 0){
            next_house = k*3 + 1;
            k = next_house;
            }
    }
    return next_house;
}

int main(){
    cout << collatz_searching (1,5) << endl;
    cout << collatz_searching (7,9) << endl;
    return 0;
}