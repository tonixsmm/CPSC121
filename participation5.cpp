#include <iostream>
using namespace std;

void assignGrid (char array[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            array[i][j] = '_';
        }
    }
}

void player1(char array[3][3]){
    int userRow;
    int userCol;
    cout << "Player 1 row: " << endl;
    cin >> userRow;
    cout << "Player 1 column: " << endl;
    cin >> userCol;
    array[userRow][userCol] = 'x';
}

void player2(char array[3][3]){
    int userRow;
    int userCol;
    cout << "Player 2 row: " << endl;
    cin >> userRow;
    cout << "Player 2 column: " << endl;
    cin >> userCol;
    array[userRow][userCol] = 'o';
}

void printGrid (char array[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << array[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){

    char tttGrid[3][3];

    assignGrid(tttGrid);

    player1(tttGrid);
    player2(tttGrid);
    printGrid(tttGrid);

    return 0;
}