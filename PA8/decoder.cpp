/*
    Tony Nguyen
    CPSC 121 02
    April 22, 2022
    PA8: Decoder
*/

#include "decoder.h"

//declare variables
ifstream inFile;
fstream outFile;
char charFromFile;

/*Fucntion to build the algorith for method 1
  Inputs: method vector
  Outputs: void
*/
void key1(vector<vector<char>> &vect){
    char orgLetter = ' ';
    char decLetter = '~';
    for (int i = 32; i < 127; i++){ //according to ASCII table
        vector<char> innerVec1;
        for (int j = 0; j < 1; j++){
            innerVec1.push_back(orgLetter);
            innerVec1.push_back(decLetter);
            orgLetter++;
            decLetter--;
        }
        vect.push_back(innerVec1);
    }
}

/*Fucntion to build the Caeser cipher algorith for method 2
  Inputs: method vector
  Outputs: void
*/
void key2(vector<vector<char>> &vect){
    char orgLetter1 = 'A', decLetter1 = 'B', orgLetter2 = 'Z', decLetter2 = 'A';
    char orgLetter3 = 'a', decLetter3 = 'b', orgLetter4 = 'z', decLetter4 = 'a';
    char orgLetter5 = 32, decLetter5 = 33, orgLetter6 = 64, decLetter6 = 32;
    for (int i = 0; i < 25; i++){ //according to ASCII table
        vector<char> innerVec2;
        for (int j = 0; j < 1; j++){
            innerVec2.push_back(orgLetter1);
            innerVec2.push_back(decLetter1);
            orgLetter1++;
            decLetter1++;
        }
        vect.push_back(innerVec2);
    }
    for (int i = 0; i < 1; i++){
        vector<char> innerVec2;
        for (int j = 0; j < 1; j++){
            innerVec2.push_back(orgLetter2);
            innerVec2.push_back(decLetter2);
        }
        vect.push_back(innerVec2);
    }
    for (int i = 0; i < 25; i++){ //according to ASCII table
        vector<char> innerVec2;
        for (int j = 0; j < 1; j++){
            innerVec2.push_back(orgLetter3);
            innerVec2.push_back(decLetter3);
            orgLetter3++;
            decLetter3++;
        }
        vect.push_back(innerVec2);
    }
    for (int i = 0; i < 1; i++){
        vector<char> innerVec2;
        for (int j = 0; j < 1; j++){
            innerVec2.push_back(orgLetter4);
            innerVec2.push_back(decLetter4);
        }
        vect.push_back(innerVec2);
    }
    for (int i = 0; i < 25; i++){ //according to ASCII table
        vector<char> innerVec2;
        for (int j = 0; j < 1; j++){
            innerVec2.push_back(orgLetter3);
            innerVec2.push_back(decLetter3);
            orgLetter3++;
            decLetter3++;
        }
        vect.push_back(innerVec2);
    }
    for (int i = 0; i < 1; i++){ 
        vector<char> innerVec2;
        for (int j = 0; j < 1; j++){
            innerVec2.push_back(orgLetter4);
            innerVec2.push_back(decLetter4);
        }
        vect.push_back(innerVec2);
    }
    for (int i = 0; i < 32; i++){ //according to ASCII table
        vector<char> innerVec2;
        for (int j = 0; j < 1; j++){
            innerVec2.push_back(orgLetter5);
            innerVec2.push_back(decLetter5);
            orgLetter5++;
            decLetter5++;
        }
        vect.push_back(innerVec2);
    }
    for (int i = 0; i < 1; i++){ 
        vector<char> innerVec2;
        for (int j = 0; j < 1; j++){
            innerVec2.push_back(orgLetter6);
            innerVec2.push_back(decLetter6);
        }
        vect.push_back(innerVec2);
    }
}

/*Fucntion to take the text from the original file, encrypt using the first method,
  and export the encrypted version to a new file
  Inputs: method vector
  Outputs: void
*/
void encrypt1(vector<vector<char>> vect){
        inFile.open("PA8text.txt");
        outFile.open("PA8encrypted1.txt", ios::app);

    while (!inFile.eof()){
        inFile >> charFromFile;
        for (int i = 0; i < vect.size(); i++){
            if (charFromFile == vect[i][0]){
                outFile << vect[i][1];
                break;
            }
        }
    }
    inFile.close();
    outFile.close();
}

/*Fucntion to take the text from the original file, encrypt using the second method,
  and export the encrypted version to a new file
  Inputs: method vector
  Outputs: void
*/
void encrypt2(vector<vector<char>> vect){
    inFile.open("PA8text.txt");
    outFile.open("PA8encrypted2.txt", ios::app);

    while (!inFile.eof()){
        inFile >> charFromFile;
        for (int i = 0; i < vect.size(); i++){
            if (charFromFile == vect[i][0]){
                outFile << vect[i][1];
                break;
            }
        }
    }
    inFile.close();
    outFile.close();
}

/*Fucntion to take the text from the previous encrypted file, decrypt using the 
  first method, and export the decrypted version to a new file
  Inputs: method vector
  Outputs: void
*/
void decrypt1(vector<vector<char>> vect){
    inFile.open("PA8encrypted1.txt");
    outFile.open("PA8decrypted1.txt", ios::app);

    while (!inFile.eof()){
        inFile >> charFromFile;
        for (int i = 0; i < vect.size(); i++){
            if (charFromFile == vect[i][1]){
                outFile << vect[i][0];
                break;
            }
        }
    }

    inFile.close();
    outFile.close();
}

/*Fucntion to take the text from the previous encrypted file, decrypt using the 
  first method, and export the decrypted version to a new file
  Inputs: method vector
  Outputs: void
*/
void decrypt2(vector<vector<char>> vect){
    inFile.open("PA8encrypted2.txt");
    outFile.open("PA8decrypted2.txt", ios::app);

    while (!inFile.eof()){
        inFile >> charFromFile;
        for (int i = 0; i < vect.size(); i++){
            if (charFromFile == vect[i][1]){
                outFile << vect[i][0];
                break;
            }
        }
    }

    inFile.close();
    outFile.close();
}

/*Fucntion to print a 2d vector, used to check the method vector
  Inputs: method vector
  Outputs: void
*/
void print2dvec (vector<vector<char>> invec){
    for (vector<char> elem : invec){
        for (int i = 0; i < elem.size(); i++){
            cout << elem[i] << " ";
        }
        cout << endl;
    }
}