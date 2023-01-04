// Jo Crandall
// March 2022
// Multidimensional vectors, structs

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/// Struct declaration
struct Student{
    int ID; //student id           //these are data members of the struct
    string name; //student name
    double balance; //meal plan balance
};

struct Employee{
    int ID;
    double hour;
    string name;
    double wage;
};

/// Function prototypes
void print2dvec(vector<vector<int>>);
void print2dvec(vector<vector<string>>);
void printStudent(Student);


int main(){

    ///  we can have a vector of lots of data types and structures...including other vectors
    vector<vector<int>> vec2dInt {{1,2},{3,4},{5,6}};
    print2dvec(vec2dInt);

    /// We can access the elements of a certain 'row' of the vector
    /// Recognize that this row is itself a VECTOR
    for (int i = 0; i < vec2dInt[0].size(); i++){
         cout << vec2dInt[0][i] << ' ';
    }
    cout << endl;

    /// How would we walk down a 'column' of the vector?
    for (int i = 0; i < vec2dInt.size(); i++){
         cout << vec2dInt[i][0] << endl;
    }
    cout << endl;

    /// *****Write an overloaded version of the print function to handle 2d vectors of strings
    /// Here is a 2d vector of strings
    vector<vector<string>> vec2dStr {{"cat","dog"},{"fish","llama","giraffe"},{"pterodactyl"}};
    /// Let's try the new print function
    print2dvec(vec2dStr);


    /// The arrays and vectors we have used have been limited to a single data type.
    /// Structs allow us to combine multiple data types in a logically related structure
    Student student1;  //declare a Student structure and name it student1
    student1.ID = 123;   //assign 123 to the ID member of student1
    student1.name = "Jo";  //assign Jo to the name member of student1
    student1.balance = 42.50;   //assign 42.50 to the balance member of student1

    //cout << student1.name << endl;

    /// Declare a different Student structure
    /// This time we'll initialize all at once
    Student student2 = {456, "Bob", 18.96}; // must come in the same order as the struct
    
    //cout << student2.name << endl;
    //cout << student2.ID << endl;
    //cout << student2.balance << endl;

    ///Now write a struct Employee and then declare an instance of it
    Employee emp1;
    emp1.wage = 10000000;

    /// Write a function called printStudent() to print the data members of a Student struct
    /// call the function to print the contents of each Student struct
    printStudent(student1);
    printStudent(student2);

    

    return 0;
}

/*This function prints the contents of a 2-dimensional vector to the screen.
* Notice that we do not need to send the size as an argument with vectors
* Argument- vector<vector<int>>
* No return.*/
void print2dvec(vector<vector<int>> invec){
    // we walk through the OUTER and INNER vectors in a nested loop
    for(vector<int> subvec: invec){
        for(int i = 0; i < subvec.size(); i++){
            cout << subvec[i] << ' ';
        }
        cout << endl;
    }
}

void print2dvec (vector<vector<string>> invec){
    for (vector<string> elem : invec){
        for (int i = 0; i < elem.size(); i++){
            cout << elem[i] << " ";
        }
        cout << endl;
    }
}

void printStudent(Student stu){
    cout << stu.name << endl;
    cout << stu.ID << endl;
    cout << stu.balance << endl;
}

