/*
    Tony Nguyen
    CPSC 121 02
    April 22, 2022
    PA8: Decoder
*/

#include "decoder.h"

int main(){

    //initialize vectors for ciphers
    vector<vector<char>> method1;
    vector<vector<char>> method2;

    //create the method vector
    key1(method1);
    //print2dvec(method1);//see the algorithm

    key2(method2);
    //print2dvec(method2); //see the algorithm

    // encrypt and decrypt the text using the first method
    encrypt1(method1);
    decrypt1(method1);

    //encrypt and decrypt the text using the second method
    encrypt2(method2);
    decrypt2(method2);

    return 0;
}