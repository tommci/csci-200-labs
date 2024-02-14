/* CSCI 200: Assignment A6: Maze Runner
 *
 * Author: Thomas McInnes
 * Resources used: Lecture Notes, SFML API Documentation
 * 
 *
 * Finds a path through a given maze using BFS and DFS searching methods of 2D arrays.
 */
#ifndef POSITION_H
#define POSITION_H

/**
 * @brief Struct that holds a position in a 2D list
 * 
 */
struct Position {
    /**
     * @brief Construct a new Position object
     * 
     */
    Position();
    /**
     * @brief Construct a new Position object
     * 
     * @param R Row number
     * @param C Column Number
     */
    Position(const int R, const int C);
    int r, c; 
};

#endif