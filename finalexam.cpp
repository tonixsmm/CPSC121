#include <iostream>
#include <vector>
#include <string>
//#include <cctype>

using namespace std;

void printArray(char array[3][3]);
string myArray1[10];

// vector<string> myVec {"happy", "birthday"};
// string myArray[5] = {"happy", "birthday"};
// char ticTacToe[3][3] = {{'-','-','-'},
//                         {'-','-','-'},
//                         {'-','-','-'}};

int getPetNames(string inArray[10]){
    string petName;
    char answer;
    int num = 0;
    cout << "Enter pets name" << endl;
    for (int i = 0; i < 10; i++){
        cin >> petName;
        inArray[i] = petName;
        num++;
        cout << "Do you want to stop? (y/n)" << endl;
        cin >> answer;
        if (answer == 'y'){
            break;
        }
    }
    return num;
}

int selectGrooming(int num){
    // use a loop to keep asking the user if they want to add a grooming service (up to max)
    // once they have finished, return the total cost of pet grooming
    double cost;
    int serviceNum = 0;
    char answer;
    while(serviceNum < num){
        cout << "Do you want to add more service to the bill? (y/n)" << endl;
        cin >> answer;
        if (answer == 'y'){
            serviceNum++;
        }
        if (answer == 'n'){
            break;
        }
    }
    return serviceNum * 25;

}

void displayVetBill(string inArray[10], int num){
    int i = 0;
    while(!inArray[i].empty()){
        cout << "Pet name: " << inArray[i] << endl;
        i++;
    }
    cout << "Billed amount: " << num << " Dollars" << endl;
}

char displayAppointmentOptions(){
    char answer;

    cout << "List of appointment time:" << endl;
    cout << "1. Morning\t 2.Afternoon\t 3. Evening" << endl;
    cout << "Choose an appointment time (number): ";
    cin >> answer;

    return answer;
}


int main(){

    // myVec.push_back("to");
    // myVec.push_back("you");

    // myArray[2] = "to";
    // myArray[3] = "you";

    // for (int i = 2, j = 0; i > 0, j < 3; i--, j++){
    //     ticTacToe[i][j] = 'o';
    // }
    
    // for (int i = 0; i < 3; i++){
    //     ticTacToe[i][2] = 'x';
    // }

    // printArray(ticTacToe);
    //cout << getPetNames(myArray1) << endl;
    //displayVetBill(myArray1, selectGrooming(getPetNames(myArray1)));
    cout << displayAppointmentOptions();

    return 0;
}

//function stub is a complete function that allows you to call the function to compile
//default in SWITCH is just another case

void printArray (char array[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << array[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}