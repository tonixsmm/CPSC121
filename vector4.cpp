// Jo Crandall
// April 2022
// Gonzaga University
// This file demonstrates taking in command line args as well as more vector work

#include <iostream>
#include <vector>
#include <string>
#include <cstring>  //for strlen()
#include <cctype>  //for isdigit() and isalpha()
using namespace std;

void printElements(char* arr[], int size){
  for (int i = 0; i < size; i++){
         cout << arr[i] << endl;
  }
}

int sumElements(char* arr[], int size){
  int sum = 0;
  for (int i = 0; i < size; i++){
    sum += atoi(arr[i]); // put the value of the memmory address to use
  }
  return sum;
}

int main(int argc, char* argv[]){ //char* means string

    // argc is the NUMBER of command line arguments
    // let's call the program several times to see the number change
    cout << "The number of args is: " << argc << endl;

    // argv is the array of arguments themselves
    // how do we print out the elements of an array?

    for (int i = 0; i < argc; i++){
      cout << argv[i] << " ";
    }
    cout << endl;

    // Let's do an experiment to help understand the char* part
    int x = 5;
    // we know we can print out the VALUE of x:
    // cout << x << endl;
    // we also know we can print out the memory location of x:
    // cout << &x << endl;

    // a POINTER is a variable specifically designed to hold the memory address of another item
   
    int* px;  // px is a variable that holds the memory address of an integer
    char* py; // py is a variable that holds the memory address of a character
    float* pz;

    // since px is designed to hold the memory address of an int, we can store the memory address of x in it
    px = &x;
    // cout << "the value of x is: " << x << " and the address of x is " << px << endl;
    // cout << "the value of x is: " << x << " and the address of x is " << &x << endl;

   
    // If we have an array of type char*, that means we have an array full of pointers to characters
    // char arr1[3] = {'c' , 'a' , 't', '\0'};
    // char arr2[3] = {'p' , 'a' , 't', '\0'};
    // char arr3[3] = {'s' , 'a' , 't', '\0'};

    // char* arr[3] = {arr1, arr2, arr3};

    const char* myCharPointArray[] = {"cat", "dog", "123"};
    
    // for (int i = 0; i < 3; i++){
    //     cout << myCharPointArray[i] << endl;
    // }
    
    // thus, we are doing something SIMILAR when we print out the elements of the command line arguments
    // for (int i = 0; i < argc; i++){
    //     cout << argv[i] << endl;
    // }
    
    // cout << argv[2] << endl;

    // What if we want to pass one or more command line args to another function?
    // write a function that will print out all the command line args
    printElements(argv, argc);
    // write a function that will sum up all the command line args     ....atoi()
    

    // Now let's bring vectors back into the mix
    // We want to use push_back to add each arg to a vector
    vector<int> vec1;
    vector<string> vec2;
    for (int i = 1; i < argc; i++){
         vec1.push_back(atoi(argv[i]));
         cout << vec1[i-1] << ' ';
    }
    cout << endl;

    // What if we have a mix of words and numbers??
    // Notice first that the char*'s or strings are indexable since they themselves are arrays:
    cout <<"cat"[0] << endl;
    cout << argv[0][1] << endl;
    
    // a loop to go through each arg (which is an array) and determine if it's all digits
    bool digit;
    for (int argument = 0; argument <  argc; argument++){
        digit = false;
        for (int index = 0; index < strlen(argv[argument]); index++){
            if (!isdigit(argv[argument][index])){
                cout << "Argument " << argument << " is not a number" << endl;
                break;
            }
            else{
                digit = true;
            }
            
        }
        if (digit){cout << "Argument " << argument << " is a number" << endl;}
    }

    // Now modify the loop to determine if an argument is all letters with isalpha()
    bool alpha;
    for (int argument = 0; argument < argc; argument++){
      alpha = false;
      for (int index = 0; index < strlen(argv[argument]); index++){
        if (!isalpha(argv[argument][index])){
          cout << "Argument " << argument << " is not a character" << endl;
        }
        else{
          alpha = true;
        }
      }
      if (alpha){
        cout << "Argument " << argument << " is a character" << endl;
    }

    // Can you add to the loop to push each arg onto an int vec or string vec depending on whether it's word or number?
    vector<int> vec1;
    vector<string> vec2;
    for (int argument = 0; argument < argc; argument++){
      for (int index = 0; argument < strlen(argv[argument]); index++){
        if (isalpha(argv[argument][index])){
          vec1.push_back(argv[argument][index]);
        }
        else if (isdigit(argv[argument][index])){
          vec2.push_back(atoi(argv[argument][index]));
        }
      }
    }
    

    //strlen()

    cout << strlen("cat") << endl;

    char c[] = {'c', 'a', 't', '\0'};
    cout << strlen(c) << endl;

    // isdigit() - whether the character is a numeric input
    cout << isdigit('5') << endl;

    // isalpha() - whether the character is a letter
    if (isalpha('b')){
      cout << "it is a letter!" << endl;
    }
    else{
      cout << "nah it's not" << endl;
    }

    return 0;
}