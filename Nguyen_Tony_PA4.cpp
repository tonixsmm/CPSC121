/// Complete this file to implement the Robot Arena game

/* Developer comment block....who, when, what....*/

#include <iostream> //flush
#include <stdlib.h> //for system("clear")  or system("cls")
#include <unistd.h> //for sleep(), usleep()
using namespace std;

// Declare a global constant for maximum health
int maximumHealth = 50;

// This function accepts no arguments
// It returns the amount of health points to be gained back
int repairDamage(void){
    // Randomly generate an integer between 2 and 5 
    unsigned seed = time (0);
    srand(seed);
    int randomHealth = 2 + rand() % 5;
    // Return the number you've generated
    cout << "Health repaired: " << randomHealth << endl;
    return randomHealth; //return the health repaired
}


// This function accepts the name of the robot who is currently attacking
// It returns the amount of damage the attack does
int attack(string robot){
    // Declare variables
    char attackType; 
    int randomAttack;
    // Prompt the attacking robot (use the name passed into this function) to enter which attack type as a character (e.g. A, B, C..)
    cout << robot << " enter the attact type as a character (A, B, or C)" << endl;
    cin >> attackType;
    // Use a switch statement to execute the chosen attack type
    switch (attackType){
        case 'A':{
            // Randomly generated a damage point
            unsigned seedA = time (0);
            srand(seedA);
            randomAttack = 1 + rand() % 5; 
            // Return the amount of damage
            cout << "Amount of health damaged: " << randomAttack << endl;
        } break;
        case 'B':{
            // Randomly generated a damage point
            unsigned seedB = time (0);
            srand(seedB);
            randomAttack = 6 + rand() % 10; 
            // Return the amount of damage
            cout << "Amount of health damaged: " << randomAttack << endl;
        } break;
        case 'C':{
            // Randomly generated a damage point
            unsigned seedC = time (0);
            srand(seedC);
            randomAttack = 11 + rand() % 15; 
            // Return the amount of damage
            cout << "Amount of health damaged: " << randomAttack << endl;        
        } break;
        default:{
            randomAttack = 0; // In case user mistype attack types
        }
    }
    return randomAttack; // Return the amount of damage
}


// This function accepts the winning robot's name. No return
void declareWinner(string robot){
    //print a message that the robot who was passed into this function is the winner
    cout << robot << " is the winnter." << endl;
}


// This function accepts the number of the player who is choosing their name, 1 or 2
// It returns the chosen name.
string nameRobot(int num){
    //prompt the robot whose number was passed in to enter their player name 
    string robotName;
    cout << "Assign name to robot " << num << ":" << endl;
    cin >> robotName;
    //return the chosen name
    return robotName; // Return the name of robot
}


// This function takes the names of the two robot opponents and controls the main game flow. No return.
void spar(string robot1, string robot2){

    // Declare variables
    int robot1Health;
    int robot2Health;
    string robot1Option;
    string robot2Option;
    // start both players with the global constant maximum health you defined at the top
    robot1Health = maximumHealth;
    robot2Health = maximumHealth;
    sleep(1);
    cout << "\tReady?..." << flush;
    sleep(1);
    cout <<  "Spar!" << endl;
    sleep(1);
    // WHILE both players have >0 health:
    while (robot1Health > 0 && robot2Health > 0)
    {
        // Display both robots health points
        cout << robot1 << " health: " << robot1Health << endl;
        cout << robot2 << " health: " << robot2Health << endl;
        // Prompt robot 1 to choose attack or repair
        cout << robot1 << " chooses attack or repair:" << endl;
        cin >> robot1Option;
        // Execute the the options
        if (robot1Option == "attack")
        {
            robot2Health -= attack(robot1); 
        }
        else if (robot1Option == "repair")
        {
            robot1Health += repairDamage();
        }
        // Check health point conditions
        if (robot1Health <= 0)
        {
        declareWinner(robot2);
        break;
        }
        else if (robot2Health <= 0)
        {
        declareWinner(robot1);
        break;
        }
        // Display both robots health points
        cout << robot1 << " health: " << robot1Health << endl;
        cout << robot2 << " health: " << robot2Health << endl;
        // Prompt robot 1 to choose attack or repair
        cout << robot2 << " chooses attreack or repair:" << endl;
        cin >> robot2Option;
        if (robot2Option == "attack")
        {
             robot1Health -= attack(robot2);
        }
        else if (robot2Option == "repair")
        {
        robot2Health += repairDamage();
        }
        // Check health point conditions
        if (robot1Health <= 0)
        {
        declareWinner(robot2);
        break;
        }
        else if (robot2Health <= 0)
        {
        declareWinner(robot1);
        break;
        }
    }    
}


// Main function
int main(){

    srand(time(0));  //seeding the random algorithm 

    cout << "Welcome to Robot Arena!!!\n\n";

    // let both players choose their robot name:
    string robot1 = nameRobot(1);
    string robot2 = nameRobot(2);
   
    // begin the battle:
    spar(robot1, robot2);

    return 0;
}