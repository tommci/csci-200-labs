/* CSCI 200: Assignment L5A: Escape Room
 *
 * Author: Thomas McInnes
 * Resources used: N/A
 * 
 *
 * Use class inheritance to escape the infinite loop!
 */
#include "Room.h"

#include <iostream>
using namespace std;

ARoom::ARoom() {
    cout << "ARoom() called" << endl;

    mRoomName = "Vacant Room";
}

ARoom::~ARoom() {
    cout << "~ARoom() called" << endl;
}

string ARoom::getRoomName() const {
    return mRoomName;
}
