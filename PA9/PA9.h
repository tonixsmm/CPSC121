#include <iostream>
#include <GLUT/glut.h>
#include <cmath>

using namespace std;

void drawLine(double x1, double y1, double x2, double y2);
void drawCircle(double x, double y);
void drawX(double x, double y);
void display(void);
void playConnectFour(char inArray[6][7]);
void placeChip(int playerNum, char playerToken, char inArray[6][7]);
bool hasFourVert(char inArray[6][7], char playerToken);
bool hasFourHozt(char inArray[6][7], char playerToken);
bool hasFourDiagLeft(char inArray[6][7], char playerToken);
bool hasFourDiagRight(char inArray[6][7], char playerToken);
int checkTie(char inArray[6][7]);