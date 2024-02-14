/* CSCI 200: Assignment L5A: Escape Room
 *
 * Author: Thomas McInnes
 * Resources used: N/A
 * 
 *
 * Use class inheritance to escape the infinite loop!
 */
#ifndef EXIT_ROOM_H
#define EXIT_ROOM_H

#include "Room.h"

class ExitRoom : public ARoom {
public:
    ExitRoom();
    ~ExitRoom();
    bool escapeTheRoom() override;
};

#endif//EXIT_ROOM_H