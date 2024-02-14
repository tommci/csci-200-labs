/* CSCI 200: Assignment L5A: Escape Room
 *
 * Author: Thomas McInnes
 * Resources used: N/A
 * 
 *
 * Use class inheritance to escape the infinite loop!
 */
#include "GuessTheNumberRoom.h"
#include "ExitRoom.h"

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

ARoom* go_to_next_room() {
    int randRoomChoice = rand() % 10; // a 10% chance to get directly out
    switch(randRoomChoice) {
    case 7:     return new ExitRoom();
    default:    return new GuessTheNumberRoom(); // normally sends to Guess Number rom
    }
}

int main() {
    srand( time(0) );
    rand();

    ARoom* pCurrentRoom;

    do {    
        pCurrentRoom = go_to_next_room();
        cout << "Welcome to the " << pCurrentRoom->getRoomName() << endl;
    } while( !pCurrentRoom->escapeTheRoom() );

    cout << "You made it out!" << endl;

    return 0;
}