/*  Author: Jo Crandall
    CPSC 121 More Conditionals
    Jan 31, 2022
    Gonzaga University
    This program demonstrates, user menu, logical expressions, and the conditional operator.
*/

#include <iostream>
#include <string>
using namespace std;

int main(){

    // unsigned seed = time(0);
    // srand(seed);
    // int mysteryNum = rand() % 21; //random runs from 0-20

    /// Declare all variables UP FRONT in the program:
    int userOption;
    double userBal;
    string userType;
    int days;
    const double RATE30 = .005, RATE90 = .008;      /// What have we declared here??
    
    /// User Menu Example
    /// banking application - display user menu    
    /// notice use of newlines and tabs to format output
    cout << "---Banking Application Options---\n\n";
    cout << "\t1. Deposit\n" << "\t2. Withdrawal\n" << "\t3. Check Balance\n" <<
        "\t4. ...\n\n" ;    

    /// get the user's choice
    cout << "Enter your choice:\n";
    /// What other options?   What will the user enter????

    cin >> userOption;
    if (userOption == 1){
        cout << "Let's make that deposit!" <<  endl;
    }


    /// Logical Expressions Example: we can combine logical expressions into compound conditional expressions
    /// banking application - check user account status
    userBal = 1200;
    userType = "Corporate";

    if (userBal < 0 && userType != "Corporate")   cout << "Send negative balance notice.\n";
    if (userBal < 5000 && userType == "Corporate")   cout << "Send low corporate account notice.\n";

    /// what takes operator precedence??
    cout << (false && false || true) << endl;
    cout << (false && (false || true)) << endl;


    /// it is sometimes necessary to use parentheses for clarity!!!
    //if (userBal < 25 && userType != "Corporate" || userBal < 5000 && userType == "Corporate")   cout << "Send Low Balance notice.\n";

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Conditional Operator Example
    /// format:
    /// <test cond> ? <what to do if true> : <what to do if false>
    //5 > 4 ? (cout << "hi" << endl) : (cout << "bye" << endl);

    /// banking application - apply account dividends
    days = 30;

    //days == 30 ? cout << "Dividends not due\n" : userBal += RATE90 * userBal;
    //days == 30 ? userBal += RATE30 * userBal : userBal += RATE90 * userBal;
    //cout << "New user balance: " << userBal << endl;

    /// another way to get a value from a conditional expression then assign it to the userBal variable
    /// format:
    /// <variable to hold result> = <test cond> ? <value if true> : <value if false>   ...the '=' could be another operation, as shown below
    //userBal += (days == 30) ? (RATE30 * userBal) : (RATE90 * userBal);
    //cout << "New user balance: " << userBal << endl;

    return 0;
}