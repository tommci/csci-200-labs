/* CSCI 200: Assignment L5A: Escape Room
 *
 * Author: Thomas McInnes
 * Resources used: N/A
 * 
 *
 * Use class inheritance to escape the infinite loop!
 */
#include "ExitRoom.h"

#include <iostream>
using namespace std;

ExitRoom::ExitRoom() {
    cout << "ExitRoom() called" << endl;
    mRoomName = "Exit Room";
}

ExitRoom::~ExitRoom() {
    cout << "~ExitRoom() called" << endl;
}

bool ExitRoom::escapeTheRoom() {
    cout << "Exit found!" << endl;
    return true;
}
