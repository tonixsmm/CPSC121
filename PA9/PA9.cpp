#include "PA9.h"

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
            if (playerToken == 'x'){       
                drawX(col, 5-(i-1));  
                glFlush();   
            }
            if (playerToken == 'o'){       
                drawCircle(col, 5-(i-1));  
                glFlush();   
            }
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

/*Fucntion to draw openGL line 
  Inputs: coordinates of two end points
  Outputs: void
*/
void drawLine(double x1, double y1, double x2, double y2){

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);

    glColor3f(1.0, 1.0, 1.0);

    glVertex2f(x1, y1);
    glVertex2f(x1 + .005, y1 + .005);
    glVertex2f(x2, y2);
    glVertex2f(x2 + .005, y2 + .005);

    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

/*Fucntion to draw circle to place in the board
  Inputs: number of steps from the lowest left cell of the board
  Outputs: void
*/
void drawCircle(double x, double y){
    double h1, h2, r;
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);   

    double incr = 0.5;
    r = 0.1;

    if (x < 3){
        h1 = -(0.855-(0.29*x));
    }
    if (x > 3){
        h1 = (-0.855+(0.29*x));
    }
    if (y <= 3){
        h2 = -(0.835-(0.33*y));
    }
    if (y > 3){
        h2 = (-0.835+(0.33*y));
    }
    if (x == 3){
        h1 = 0.006;
    }

    for (double i = 0; i*M_PI/180 < 2*M_PI; i += incr){
        glVertex2f(h1, h2);
        glVertex2f(h1 + r * cos(i * M_PI / 180), h2 + r * sin(i * M_PI / 180));
        glVertex2f(h1 + r * cos((incr + i) * M_PI / 180), h2 + r * sin((incr + i) * M_PI / 180));
    }
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

/*Fucntion to draw the X sign to place in the board
  Inputs: number of steps from the lowest left cell of the board 
  Outputs: void
*/
void drawX(double x, double y){
    double h1, h2;
    double v1, v2;
    double j1, j2;

    glBegin(GL_POLYGON);

    glColor3f(0.988, 0.82, 0.757);

    if (x < 3){
        h1 = -(0.95-(0.29*x));
        v1 = -(0.76-(0.29*x));
    }
    if (x > 3){
        h1 = (-0.95+(0.29*x));
        v1 = (-0.76+(0.29*x));
    }
    if (y <= 3){
        h2 = -(0.95-(0.33*y));
        v2 = -(0.72-(0.33*y));
    }
    if (y > 3){
        h2 = (-0.95+(0.33*y));
        v2 = (-0.72+(0.33*y));
    }
    if (x == 3){
        h1 = -0.08;
        v1 = 0.11;
    }

    drawLine(h1, h2, v1, v2);
    drawLine(h1, v2, v1, h2);

    glEnd();
}

/*Fucntion to display the board and initiate the game
  Inputs: board
  Outputs: void
*/
void display(void){
    char boardE[6][7] = {{'-','-','-','-','-','-','-'},
                         {'-','-','-','-','-','-','-'},
                         {'-','-','-','-','-','-','-'},
                         {'-','-','-','-','-','-','-'},
                         {'-','-','-','-','-','-','-'},
                         {'-','-','-','-','-','-','-'}};

    glClearColor(0.682, 0.776, 0.812, 1);

    glClear(GL_COLOR_BUFFER_BIT);

    //draw the grid
    //column
    drawLine(0.71, 1, 0.71, -1);
    drawLine(0.43, 1, 0.43, -1);
    drawLine(0.14, 1, 0.14, -1);
    drawLine(-0.14, 1, -0.14, -1);
    drawLine(-0.43, 1, -0.43, -1);
    drawLine(-0.72, 1, -0.72, -1);
    //row
    drawLine(1, 0.67, -1, 0.67);
    drawLine(1, 0.33, -1, 0.33);
    drawLine(1, -0, -1, -0);
    drawLine(1, -0.34, -1, -0.34);
    drawLine(1, -0.67, -1, -0.67);

    //play game
    playConnectFour(boardE);

    glFlush();
}