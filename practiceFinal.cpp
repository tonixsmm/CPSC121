// CPSC 121 Spring 2022 Practice Lab Final 
// Write the indicated functions with appropriate arguments (inputs) and returns. 

#include <iostream>
#include <string>
using namespace std;

// This function prompts the user to enter the names of their pets, up to 10 pets, storing the names in an array
// Input: string array
// Return: numbers of pets added
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


// This function prompts the user to add pet grooming to their veterinary bill
// They can only add as many grooming services as they have pets, but don't have to purchase one for every pet
// Each grooming service adds $25 to their veterinary bill
// Input: number of pets (which could be more than number of services they are adding)
// Return: total cost of grooming
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
  

// This function takes the array of pet names populated earlier as well as a veterinary bill total
// It displays the total bill to the user along with all pet names
// Input: string array and bill amount as a double. 
// Return: none
void displayVetBill(string inArray[10], int num){
    int i = 0;
    while(!inArray[i].empty()){
        cout << "Pet name: " << inArray[i] << endl;
        i++;
    }
    cout << "Billed amount: " << num << " Dollars" << endl;
}
    

// This function displays a list of appointment time options and returns the user's choice
// The menu options are 1. Morning 2. Afternoon 3. Evening
// Input: none
// Return: user choice number
char displayAppointmentOptions(){
    char answer;

    cout << "List of appointment time:" << endl;
    cout << "1. Morning\t 2.Afternoon\t 3. Evening" << endl;
    cout << "Choose an appointment time (number): ";
    cin >> answer;

    return answer;
}



int main(){
    string myArray[10];
    //call each of your functions here, sending appropriate arguments, and storing returned values
    // A customer at a veterinarian has a base appointment cost of $85
    // The idea is to get the names of their pets, set up an appointment, then calculate total vet bill...
    cout << "Welcome to the Vet!" << endl;
    int petNum = getPetNames(myArray);
    int serviceCost = selectGrooming(petNum);

    displayAppointmentOptions();

    // displayVetBill(myArray, serviceCost);
    cout << "Total cost is: " << 85 + serviceCost;

    return 0;
}    
