#include <iostream>
#include <string> 
#include <iomanip>
#include <cctype>
#include <unistd.h> 
#include <limits>
#include <cstdlib>


using namespace std;

int main (){
    int bankBalance = 0.0;
    int diceOne = 0;
    int diceTwo = 0;
    int betAmount = 0;
    int sumDice = 0;
    int i = 0;
    int newsumDice = 0;
    int rediceOne = 0;
    int rediceTwo = 0;

    cout << "Welcome to Craps! The rules are simple. You roll two dice and then sum up the numbers on two dice." << endl;
    cout << "If the sum is 7 or 11 on the first throw, you win. If the sum is 2, 3, or 12 on the first throw, the you lose." << endl;
    cout << "If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes your point." << endl;
    cout << "To win, you must continue rolling the dice until you make your point." << endl;
    cout << "You will lose by rolling a 7 before making the point." << endl;
    
    
    cout << "What is your intial bank balance: $ ";
    cin >> bankBalance;
    if (bankBalance < 0){
        cout << endl;
        cout << "Invalid bank balance! Please enter a valid amount: $";
        cin >> bankBalance;
        cout << "Current bank balance: $" << bankBalance << endl;
    }
    else {
        cout << "Current bank balace: $" << bankBalance << endl;
    }

    cout << "How much do you want to bet?" << endl;
        cout << ">> ";
        cin >> betAmount;

        srand(time(0));
        cout << "Press Enter To Roll" << endl;
        cin.ignore();
        diceOne = rand() % 6 + 1;
        diceTwo = rand() % 6 + 1;
        sumDice = diceOne + diceTwo;
    if (sumDice == 7 || sumDice == 11)
    {
        cout << "You rolled a " << diceOne << " and a " << diceTwo << endl;
        cout << "You won $" << betAmount << endl;
        bankBalance += betAmount;
        cout << "Current bank balace: $" << bankBalance << endl;
    }
    else if (sumDice == 2 || sumDice == 3 ||sumDice == 12)
    {
        cout << "You rolled a " << diceOne << " and a " << diceTwo << endl;
        cout << "You lost $" << betAmount << endl;
        bankBalance -= betAmount;
        cout << "Current bank balace: $" << bankBalance << endl;
    }
    else{
        while (newsumDice != sumDice){
            cout << "Press Enter To Roll" << endl;
            cin.ignore();
            rediceOne = rand() % 6 + 1;
            rediceTwo = rand() % 6 + 1;
            newsumDice = rediceOne + rediceTwo;
            cout << "You rolled a " << rediceOne << " and a " << rediceTwo << endl;
            if (newsumDice == 7){
                cout << "You rolled a " << rediceOne << " and a " << rediceTwo << endl;
                cout << "You lost $" << betAmount << endl;
                bankBalance -= betAmount;
                cout << "Current bank balace: $" << bankBalance << endl;
                break;
            }


        }
    }
    

    
    // do{
    //     cout << "How much do you want to bet?" << endl;
    //     cout << ">> ";
    //     cin >> betAmount;

    //     srand(time(0));
    //     diceOne = rand() % 6 + 1;
    //     diceTwo = rand() % 6 + 1;


    // } while (bankBalance > 0 || keepPlaying != 'q');
    
    

    return 0;
}


