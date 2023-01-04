/* Tony Nguyen
   CPSC 121 02
   April 4, 2022
   PA7: Connect Four
*/

#include "connect4.h"

// declare variables
bool vert;
bool hozt;
bool diagL;
bool diagR;

/*Fucntion to display the board
  Inputs: board
  Outputs: board
*/
char displayBoard(char inArray[6][7]){
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 7; j++){
            cout << inArray[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

/*Fucntion to place the chips in the desired place 
  Inputs: player number, player token, board
  Outputs: void
*/
void placeChip(int playerNum, char playerToken, char inArray[6][7]){
    int col;
    cout << "Player " << playerNum << " enter the column number that you want to place: " << endl;
    cin >> col;
    for (int i = 0; i < 7; i++){
        if (inArray[i][col] != '-'){
            inArray[i-1][col] = playerToken;
            break;
        }
    }
}

/*Fucntion to check if there is four chips placed vertically
  Inputs: board
  Outputs: bool
*/
bool hasFourVert(char inArray[6][7], char playerToken){
    for (int col = 0; col < 7; col++){
        for (int row = 0; row < 4; row++){
            if (inArray[row][col] == playerToken && inArray[row+1][col] == playerToken && inArray[row+2][col] == playerToken && inArray[row+3][col] == playerToken){
                vert = true;
            }
        }
    }
    return vert;
}

/*Fucntion to check if there is four chips placed horizontally
  Inputs: board
  Outputs: bool
*/
bool hasFourHozt(char inArray[6][7], char playerToken){
    for (int row = 0; row < 6; row++){
        for (int col = 0; col < 4; col++){
            if (inArray[row][col] == playerToken && inArray[row][col+1] == playerToken && inArray[row][col+2] == playerToken && inArray[row][col+3] == playerToken){
                hozt = true;
            }
        }
    }
    return hozt;
}

/*Fucntion to check if there is four chips placed diagonally to the left
  Inputs: board
  Outputs: bool
*/
bool hasFourDiagLeft(char inArray[6][7], char playerToken){
    for (int row = 0; row < 6; row++){
        for (int col = 0; col < 7; col++){
            if (inArray[row][col] == playerToken && inArray[row+1][col-1] == playerToken && inArray[row+2][col-2] == playerToken && inArray[row+3][col-3] == playerToken){
                diagL = true;
            }
        }
    }
    return diagL;
}

/*Fucntion to check if there is four chips placed diagonally to the right
  Inputs: board
  Outputs: bool
*/
bool hasFourDiagRight(char inArray[6][7], char playerToken){
    for (int row = 0; row < 6; row++){
        for (int col = 0; col < 7; col++){
            if (inArray[row][col] == playerToken && inArray[row-1][col+1] == playerToken && inArray[row-2][col+2] == playerToken && inArray[row-3][col+3] == playerToken){
                diagR = true;
            }
        }
    }
    return diagR;
}

/*Fucntion to check if two players are tie
  Inputs: board
  Outputs: number of empty places
*/
int checkTie(char inArray[6][7]){
    int num = 0;
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 7; j++){
            if (inArray[i][j] == 'x' || inArray[i][j] == 'o'){
            num +=1;
            }
        }
    }
    return num;
}

/*Fucntion to control the game
  Inputs: board
  Outputs: void
*/
void playConnectFour(char inArray[6][7]){
    while (vert == false && hozt == false && diagL == false && diagR == false){
        // place chip for player 1
        displayBoard(inArray);
        placeChip(1, 'x', inArray);

        //check the winning condition
        hasFourVert(inArray, 'x');
        hasFourHozt(inArray, 'x');
        hasFourDiagLeft(inArray, 'x');
        hasFourDiagRight(inArray, 'x');

        // check if player 1 wins
        if (vert == true || hozt == true || diagL == true || diagR == true){
            cout << "Player 1 win!" << endl;
            break;
        }

        // check if the game is tie
        if (checkTie(inArray) == 42){
            cout << "Game over! Tie with no win" << endl;
            break;
        }

        // place chip for player 2
        displayBoard(inArray);
        placeChip(2, 'o', inArray);

        // check the winning condition
        hasFourVert(inArray, 'o');
        hasFourHozt(inArray, 'o');
        hasFourDiagLeft(inArray, 'o');
        hasFourDiagRight(inArray, 'o');

        // check if player 2 wins
        if (vert == true || hozt == true || diagL == true || diagR == true){
            cout << "Player 2 win!" << endl;
            break;
        }

        // check if the game is tie
        if (checkTie(inArray) == 42){
            cout << "Game over! Tie with no win" << endl;
            break;
        }
    }
}