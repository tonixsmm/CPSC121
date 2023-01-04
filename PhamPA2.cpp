#include <iostream>
#include <string> 
#include <unistd.h>

using namespace std;

int main() {
    int count = 0;
    char answer = ' ';
    char answer2 = ' ';
    char answer3 = ' ';
    char answer4 = ' ';
    int answer5 = 0;
    int answer6 = 0;
    bool answer7 = false;
    bool answer8 = false;
    bool answer9 = false;
    bool answer10 = false;

    cout << "1) Who gave Harry Potter his first broomstick? (Enter a-e)" << endl;
    cout << "a. Sirius Black \nb. Albus Dumbledore \nc. Hagrid \nd. Minerva Mcgonagall \ne. Draco Malfoy" << endl;
    cin >> answer;

    if (answer == 'd'){
        cout << "Correct" << endl;
        count += 1;
    }
    else {
        cout << "Wrong. The answer is d) Minerva Mcgonagall" << endl;
    }
    
    sleep(1);
    cout << "2) What's Ron Weasly's rat called? (Enter a-e)" << endl;
    cout << "a. Hedwig \nb. Scabbers \nc. Fang \nd. Crookshanks \ne. Fluffy" << endl;
    cin >> answer2;

    if (answer2 == 'b') {
        cout << "Correct" << endl;
        count += 1;
    }
    else {
        cout << "Wrong. The answer is b) Scabbers" << endl;
    }
    
    sleep(1);
    cout << "3) Who opened the Chamber of Secrets in Harry's second year at Hogwart? (Enter a-e)" << endl;
    cout << "a. Draco Malfoy \nb. Dobby \nc. Moaning Myrtle \nd. Tom Riddle \ne. Ginny Weasly" << endl;
    cin >> answer3;

    if (answer3 == 'e') {
        cout << "Correct" << endl;
        count += 1;
    }
    else {
        cout << "Wrong. The answer is e) Ginny Weasly" << endl;
    }
    
    sleep(1);
    cout << "4) Which hocrux of Voldemort's was destroyed second? (Enter a-e)" << endl;
    cout << "a. Marvolo Gaunt's Ring \nb. Tom Riddle's Diary  \nc. Salazar Slytherin's Locket \nd. Helga Hufflpuff's Cup \ne. Rovena Ravenclaw's Diadem" << endl;
    cin >> answer4;

    if (answer4 == 'a') {
        cout << "Correct" << endl;
        count += 1;
    }
    else {
        cout << "Wrong. The answer is a) Marvolo Gaunt's Ring" << endl;
    }
    
    sleep(1);
    cout << "5) How many hocruxes does Voldemort have? (Enter an integer)" << endl;
    cin >> answer5;

    if (answer5 == 7){
        cout << "Correct" << endl;
        count += 1;
    }
    else {
        cout << "Wrong. The answer is 7" << endl;
    }
    
    sleep(1);
    cout << "6) At what age did Harry Potter discovered that he is a wizzard? (Enter an integer)" << endl;
    cin >> answer6;

    if (answer6 == 11){
        cout << "Correct" << endl;
        count += 1;
    }
    else {
        cout << "Wrong. The answer is 11" << endl;
    }

    sleep(1);
    cout << "7) Is   Harry Potter's birthday on July 13th? (1 for True and 0 for False)" << endl;
    cin >> answer7;

    if (answer7 == 0) {
        cout << "Correct" << endl;
        count += 1;
    }
    else {
        cout << "Wrong. The answer is False" << endl;
    }

    sleep(1);
    cout << "8) Do Harry's wand and Voldemort's wand have the same core? (1 for True and 0 for False)" << endl;
    cin >> answer8;

    if (answer8 == 1) {
        cout << "Correct" << endl;
        count += 1;
    }
    else {
        cout << "Wrong. The answer is True" << endl;
    }

    sleep(1);
    cout << "9) Do house-elves hate Hermione Granger? (1 for True and 0 for False)" << endl;
    cin >> answer9;

    if (answer9 == 1) {
        cout << "Correct" << endl;
        count += 1;
    }
    else {
        cout << "Wrong. The answer is True" << endl;
    }

    sleep(1);
    cout << "10) Did Harry name his firstborn James Sirius Potter (1 for True and 0 for False)" << endl;
    cin >> answer10;

    if (answer10 == 0) {
        cout << "Correct" << endl;
        count += 1;
    }
    else {
        cout << "Wrong. The answer is False" << endl;
    }

    if (count < 5){
        cout << "You got " << count << " questions right. Better luck next time." << endl;
    }
    else if (count < 8){
        cout << "You got " << count << " questions right. Impressive." << endl;
    }
    else {
        cout << "You got " << count << " questions right. Wow!! You really know your Harry Potter!" << endl;
    }


    return 0;
}

