/* CSCI 200: Assignment A6: Maze Runner
 *
 * Author: Thomas McInnes
 * Resources used: Lecture Notes, SFML API Documentation
 * 
 *
 * Finds a path through a given maze using BFS and DFS searching methods of 2D arrays.
 */
#include "Position.h"

Position::Position() {
    r = 0;
    c = 0;
}

Position::Position(const int R, const int C) {
    r = R;
    c = C;
}