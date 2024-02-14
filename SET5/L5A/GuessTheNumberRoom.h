/* CSCI 200: Assignment L5A: Escape Room
 *
 * Author: Thomas McInnes
 * Resources used: N/A
 * 
 *
 * Use class inheritance to escape the infinite loop!
 */
#ifndef GUESS_THE_NUMBER_ROOM_H
#define GUESS_THE_NUMBER_ROOM_H

#include "Room.h"

class GuessTheNumberRoom : public ARoom {
public:
    GuessTheNumberRoom();
    ~GuessTheNumberRoom();
    bool escapeTheRoom() override;
private:
    int _secretNumber;
};

#endif//GUESS_THE_NUMBER_ROOM_H