/*  
Tony Nguyen
January 28, 2022
CPSC 121 02
Programming Assignment #2
*/

#include <iostream> /// This one is for the iostream library to execute cout, cin, endl, etc.
#include <string> /// This one is for the string objects
using namespace std;

int main () //Starting clause
{
    ///Declare the variables
    string SysCode = "Batman123"; 
    string Agent1;
    string Agent2;

    cout << "Agent 1 enters codename" << endl; ///Prompt Agent 1 to enter codename
    cin >> Agent1; ///Agent 1 codename input
    if (Agent1 == SysCode) ///Agent 1 first attempt
    {
        cout << "Agent 2 enters codename" << endl; ///Prompt Agent 2 to enter codename
        cin >> Agent2; ///Agent 2 codename input
        if (Agent2 == SysCode) ///If Agent 2 first attempt is correct
        {
            cout << "System Access Granted. Both Agent Validated" << endl;
        }
        else ///Agent 2 second attempt
        {
            cout << "Agent 2 try again" << endl;
            cin >> Agent2;
            if (Agent2 == SysCode) ///If Agent 2 second attempt is correct
            {
                cout << "System Access Granted. Both Agent Validated" << endl;
            }
            else ///If not
            {
                cout << "Agent 1 has been validated. Agent 2 has been deactivated" << endl;
            }
        }
    }
    else if (Agent1 != SysCode) ///If Agent 1 is incorrect
    {
        cout << "Agent 1 try again" << endl; ///Agent 1 second attempt
        cin >> Agent1;
        if (Agent1 == SysCode) ///If Agent 1 second attempt is correct
        {
            cout << "Agent 2 enters codename" << endl; ///Agent 2 enter codename
            cin >> Agent2;
            if (Agent2 == SysCode) ///If Agent 2 is correct
            {
                cout << "System Access Granted. Both Agent Validated" << endl;
            }
            else ///If Agent 2 is incorrect
            {
                cout << "Agent 2 try again" << endl; ///Agent 2 second attempt
                cin >> Agent2;
                if (Agent2 == SysCode) ///If Agent 2 second attempt is correct
                {
                    cout << "System Access Granted. Both Agent Validated" << endl;
                }
                else ///If Agent 2 second attempt is incorrect
                {
                    cout << "Agent 1 has been validated. Agent 2 has been deactivated" << endl;
                }
            }
        }
        else ///Agent 1 is incorrect
        {
            cout << "Agent 2 enters codename" << endl; ///Agent 2 enters codename
            cin >> Agent2;
            if (Agent2 == SysCode) ///If Agent 2 first attempt is correct
            {
                cout << "Agent 2 has been validated. Agent 1 has been deactivated" << endl;
            }
            else ///Agent 2 first attempt is incorrect
            {
                cout << "Agent 2 try again" << endl; ///Agent 2 second attempt
                cin >> Agent2;
                if (Agent2 == SysCode) ///If Agent 2 second attempt is correct
                {
                    cout << "Agent 2 has been validated. Agent 1 has been deactivated" << endl;
                }
                else ///If Agent 2 second attempt is incorrect, ie. both are incorrect
                {
                cout << "System is being shutting down. Headquarter is being alerted" << endl;
                }
            }
        }
    }
return 0;
}