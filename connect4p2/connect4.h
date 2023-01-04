/* Tony Nguyen
   CPSC 121 02
   April 4, 2022
   PA7: Connect Four
*/

#ifndef CONN_FOUR_H
#define CONN_FOUR_H

#include <iostream>
#include <vector>
using namespace std;

// implementations
void playConnectFour(char inArray[6][7]);
char displayBoard(char inArray[6][7]);
void placeChip(int playerNum, char playerToken, char inArray[6][7]);
bool hasFourVert(char inArray[6][7], char playerToken);
bool hasFourHozt(char inArray[6][7], char playerToken);
bool hasFourDiagLeft(char inArray[6][7], char playerToken);
bool hasFourDiagRight(char inArray[6][7], char playerToken);
int checkTie(char inArray[6][7]);


#endif

/// Use these board configurations for testing your hasFour() function:

// empty board -> you can copy this to declare your board in your program if desired
// char boardE[6][7] = {{'-','-','-','-','-','-','-'},
//                      {'-','-','-','-','-','-','-'},
//                      {'-','-','-','-','-','-','-'},
//                      {'-','-','-','-','-','-','-'},
//                      {'-','-','-','-','-','-','-'},
//                      {'-','-','-','-','-','-','-'}};

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