/* CSCI 200: Assignment L5A: Escape Room
 *
 * Author: Thomas McInnes
 * Resources used: N/A
 * 
 *
 * Use class inheritance to escape the infinite loop!
 */
#include "GuessTheNumberRoom.h"

#include <cstdlib>
#include <iostream>
using namespace std;

GuessTheNumberRoom::GuessTheNumberRoom() {
    cout << "GuessTheNumberRoom() called" << endl;
    mRoomName = "Number Room";

    _secretNumber = rand() % 20 + 1;
}

GuessTheNumberRoom::~GuessTheNumberRoom() {
    cout << "~GuessTheNumberRoom() called" << endl;
}

bool GuessTheNumberRoom::escapeTheRoom() {
    unsigned int numGuesses = 0;
    int guess;
    while( numGuesses < 5 ) {
        cout << "Enter your guess:" << endl;
        cin >> guess;
        numGuesses++;
        if( guess < _secretNumber ) { cout << "Guess is too low." << endl; }
        else if( guess > _secretNumber ) { cout << "Guess is too high." << endl; }
        else if( guess == _secretNumber ) {
            cout << "You guessed the number!" << endl;
            return true;
        }
    }
    cout << "You didn't guess the number in time." << endl;
    return false;
}