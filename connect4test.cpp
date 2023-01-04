/* Tony Nguyen
   CPSC 121 02
   April 4, 2022
   PA7: Connect Four
*/

#include <iostream>
#include <vector>
using namespace std;

bool vertical;
bool horizontal;
bool diagLeft;
bool diagRight;

void playConnectFour(void);
char displayBoard(char inArray[6][7]);
void placeChip(int playerNum, char playerToken, char inArray[6][7]);
bool hasFourVert(char inArray[6][7], char playerToken);
bool hasFourHozt(char inArray[6][7], char playerToken);
bool hasFourDiagLeft(char inArray[6][7], char playerToken);
bool hasFourDiagRight(char inArray[6][7], char playerToken);
string checkWinner(int playerNum);
string checkTie(char inArray[6][7]);

/// Use these board configurations for testing your hasFour() function:

// empty board -> you can copy this to declare your board in your program if desired
char grid[6][7] = {{'-','-','-','-','-','-','-'},
                     {'-','-','-','-','-','-','-'},
                     {'-','-','-','-','-','-','-'},
                     {'-','-','-','-','-','-','-'},
                     {'-','-','-','-','-','-','-'},
                     {'-','-','-','-','-','-','-'}};

// // o has vertical win
// char board1[6][7] = {{'-','-','-','-','-','-','-'},
//                      {'-','-','-','-','-','-','-'},
//                      {'o','-','-','-','-','-','-'},
//                      {'o','-','-','x','-','-','-'},
//                      {'o','o','x','x','-','-','-'},
//                      {'o','x','o','x','-','-','-'}};

// // x has horizontal win
// char board2[6][7] = {{'-','-','-','-','-','-','-'},
//                      {'x','-','-','-','-','-','-'},
//                      {'o','o','-','-','-','-','-'},
//                      {'x','x','x','x','-','-','-'},
//                      {'o','x','o','o','-','-','-'},
//                      {'o','o','o','x','-','-','-'}};

// // o has diagonal right win
// char board3[6][7] = {{'-','-','-','-','-','-','-'},
//                      {'-','-','-','-','-','o','-'},
//                      {'-','-','-','o','o','o','-'},
//                      {'-','-','x','o','x','x','-'},
//                      {'-','-','o','x','o','x','-'},
//                      {'-','x','o','x','x','o','-'}};

// // x has diagonal left win
// char board4[6][7] = {{'-','x','x','-','-','-','-'},
//                      {'-','x','x','o','-','-','-'},
//                      {'-','o','x','x','o','-','-'},
//                      {'-','o','o','o','x','-','-'},
//                      {'-','o','x','o','x','-','-'},
//                      {'o','x','x','o','o','-','-'}};

// // no win yet
// char board5[6][7] = {{'-','-','-','-','-','-','-'},
//                      {'x','-','-','-','-','-','-'},
//                      {'o','o','-','-','-','-','-'},
//                      {'x','o','x','x','-','-','-'},
//                      {'o','x','o','o','-','-','-'},
//                      {'o','o','o','x','x','x','-'}};

// // tie with no win - game over
// char board6[6][7] = {{'o','x','x','o','x','x','x'},
//                      {'x','o','x','x','o','x','o'},
//                      {'o','o','o','x','o','x','o'},
//                      {'x','o','x','x','o','o','x'},
//                      {'o','x','o','o','x','x','o'},
//                      {'o','o','o','x','x','o','o'}};

int main(){
    // char grid[6][7] = {{'-','-','-','-','-','-','-'},
    //                  {'-','-','-','-','-','-','-'},
    //                  {'-','-','-','-','-','-','-'},
    //                  {'-','-','-','-','-','-','-'},
    //                  {'-','-','-','-','-','-','-'},
    //                  {'-','-','-','-','-','-','-'}};

    char grid6[6][7] = {{'o','x','x','o','x','x','x'},
                     {'x','o','x','x','o','x','o'},
                     {'o','o','o','x','o','x','o'},
                     {'x','o','x','x','o','o','x'},
                     {'o','x','o','o','x','x','o'},
                     {'o','o','o','x','x','o','o'}};
    
    playConnectFour();

    // checkTie(grid6);

    return 0;
}

/* Tony Nguyen
   CPSC 121 02
   April 4, 2022
   PA7: Connect Four
*/


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
  Inputs: player, character to be placed, board
  Outputs: void
*/
void placeChip(int playerNum, char playerToken, char inArray[6][7]){
    int col;
    cout << "Player " << playerNum << " enter the column number that you want to place: " << endl;
    cin >> col;
    for (int i = 0; i < 7; i++){
        if (inArray[i][col] != '-'){
            inArray[i-1][col] = playerToken;
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
                vertical = true;
            }
        }
    }
    return vertical;
}

/*Fucntion to check if there is four chips placed horizontally
  Inputs: board
  Outputs: bool
*/
bool hasFourHozt(char inArray[6][7], char playerToken){
    for (int row = 0; row < 6; row++){
        for (int col = 0; col < 4; col++){
            if (inArray[row][col] == playerToken && inArray[row][col+1] == playerToken && inArray[row][col+2] == playerToken && inArray[row][col+3] == playerToken){
                horizontal = true;
            }
        }
    }
    return horizontal;
}

/*Fucntion to check if there is four chips placed diagonally to the left
  Inputs: board
  Outputs: bool
*/
bool hasFourDiagLeft(char inArray[6][7], char playerToken){
    for (int row = 0; row < 6; row++){
        for (int col = 0; col < 7; col++){
            if (inArray[row][col] == playerToken && inArray[row+1][col-1] == playerToken && inArray[row+2][col-2] == playerToken && inArray[row+3][col-3] == playerToken){
                diagLeft = true;
            }
        }
    }
    return diagLeft;
}

/*Fucntion to check if there is four chips placed diagonally to the right
  Inputs: board
  Outputs: bool
*/
bool hasFourDiagRight(char inArray[6][7], char playerToken){
    for (int row = 0; row < 6; row++){
        for (int col = 0; col < 7; col++){
            if (inArray[row][col] == playerToken && inArray[row-1][col+1] == playerToken && inArray[row-2][col+2] == playerToken && inArray[row-3][col+3] == playerToken){
                diagRight = true;
            }
        }
    }
    return diagRight;
}

/*Fucntion to declare winner
  Inputs: player number
  Outputs: winner
*/
string checkWinner(int playerNum){
    if (vertical == true || horizontal == true || diagLeft == true || diagRight == true){
        cout << "Player " << playerNum << " win!" << endl;
    }
    return 0;
}

/*Fucntion to check if two players are tie
  Inputs: board
  Outputs: declare if the game are tie
*/
string checkTie(char inArray[6][7]){
    int num = 0;
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 7; j++){
            if (inArray[i][j] != '-'){
            num +=1;
            }
        }
    }
    if (num == 42){
        cout << "Game over! Tie with no win" << endl;
    }
    return 0;
}

/*Fucntion to check if there is four chips placed diagonally to the right
  Inputs: void
  Outputs: bool
*/
void playConnectFour(void){
    while (vertical == false && horizontal == false && diagLeft == false && diagRight == false){
        displayBoard(grid);
        placeChip(1, 'x', grid);

        hasFourVert(grid, 'x');
        hasFourHozt(grid, 'x');
        hasFourDiagLeft(grid, 'x');
        hasFourDiagRight(grid, 'x');

        checkWinner(1);
        checkTie(grid);

        displayBoard(grid);
        placeChip(2, 'o', grid);

        hasFourVert(grid, 'o');
        hasFourHozt(grid, 'o');
        hasFourDiagLeft(grid, 'o');
        hasFourDiagRight(grid, 'o');

        checkWinner(2);
        checkTie(grid);
    }
}
