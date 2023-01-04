// CPSC 121 Spring 2022 Lab Final - Pizza Planet ordering application
// You need to write the indicated functions to get this application running 
// For each function stub, write the body of the function and add parameters and return types as appropriate

#include <iostream>
using namespace std;

// 10 points - This function prompts the user to enter their first name, last name, and phone num, stored as the 3 string elements of an array.
// Input: string array size 3 to hold first name, last name, phone number
// Return: none
void getCustomerInfo(string arr[3]){
    cout << "Getting customer info!" << endl;
    cout << "Please enter your First Name." << endl;
    cin >> arr [0];

    cout << "Please enter yout Last Name." << endl;
    cin >> arr [1];

    cout << "Please enter your phone number." << endl;
    cin >> arr[2];
}


// 15 points - This function prompts the user to say what topping type they would like added WHILE they haven't reached the maximum num toppings
// You should choose what the max num toppings is and store that in a variable
// Each pizza starts with a base pizza cost of $10 then adds $2.50 for each additional topping
// Input: none
// Return: total cost of this pizza as a double
double createPizza(){
    int maxTop = 10;
    int count = 0;
    char answer;
    int option;

    cout << "Creating this pizza!" << endl;
    
    while(count <= 10){
        cout << "Do you want to add more topping? (y/n)" << endl;
        cin >> answer;
        if (answer == 'y'){
            cout << "Enter the topping number: ";
            cin >> option;
            count++;
        }
        else if (answer == 'n'){
            break;
        }
    }

    return 10 + (count * 2.50);
}


// 5 points - This function displays the toppings your store offers
// Input: none
// Return: none
void displayToppingList(void){
    cout << "Displaying toppings!" << endl;
    cout << "1.Pepporoni \t 2. Pineapple \t 3.Chicken \t 4.Salmon \t 5.Veggies \t 6.Tomato \t 7.Seafood \t 8.Mushroom \t 9.Cheese \t 10.Bacon" << endl;
}
    

// 10 points - This function displays the total order cost and a msg that uses the customer's first and last name
// Input: string array and order total amount as a double. (Note, this is the same string array as the getCustomerInfo function.)
// Return: none
void displayOrderTotal(string arr[3], double num){
    cout << "Displaying order total!" << endl;
    cout << " The total cost for ";
    cout << arr[0];
    cout << " ";
    cout << arr[1];
    cout << " is " << num " dollars.";
}
    

// 10 points - This function displays the menu options to the user and prompts the user for their choice
// The menu options are 1. See toppings, 2. Add pizza, 3. Complete order
// Input: none
// Return: user choice as an int
int displayOrderMenu(){
    int choice;
    cout << "Displaying menu!" << endl;
    cout << "1. See toppings \t 2.Add pizza \t 3.Complete order" << endl;
    cout << "Please input your choice as a number!" << endl;
    cin >> choice;
    return choice;
}


// 15 points
int main(){
    string array[3];
    cout << "Welcome to Pizza Planet!" <<  endl;
    // Initialize the order total to $0
    static double total = 0;
    double num = 0;
    int choice;
    // Get the customer's name and phone info with the getCustomerInfo() function
    getCustomerInfo(array);
    // Show the customer the Order Menu WHILE they haven't selected the 'complete order' option
    // IF they chose 'see toppings' use the displayToppingList() function
    // IF they chose 'add pizza' , use the createPizza() function
    // Be sure to add to their order total each time you use the createPizza() function

    while (choice != 3){
        choice = displayOrderMenu();
        if (choice == 1){
            displayToppingList();
        }
        if (choice == 2){
            total += createPizza();
        }
        if (choice == 3){
            break;
        }
    }
    // Once the customer has selected 'complete order', use the displayOrderTotal() function
    displayOrderTotal(array, total);
}    
