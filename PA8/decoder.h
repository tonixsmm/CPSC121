/*
    Tony Nguyen
    CPSC 121 02
    April 22, 2022
    PA8: Decoder
*/

#ifndef DECODER_H
#define DECODER_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//function prototypes
void key1(vector<vector<char>> &vect);
void key2(vector<vector<char>> &vect);
void encrypt1(vector<vector<char>> vect);
void decrypt1(vector<vector<char>> vect);
void encrypt2(vector<vector<char>> vect);
void decrypt2(vector<vector<char>> vect);
void print2dvec (vector<vector<char>> invec);

#endif