//This IMPLEMENTATION FILE must #include the header file which contains its associated prototypes.
#include "maxnum.h"


/*This function accepts two integers and returns the larger of the two.
* (If the integers are equal, the first value is returned)
* Default args: num1 = 9, num2 = 13.*/
int maxNumber(int num1, int num2){
    if (num1 >= num2){
        return num1;
    }
    else return num2;
}
