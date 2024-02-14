/* CSCI 200: Assignment A6: Maze Runner
 *
 * Author: Thomas McInnes
 * Resources used: Lecture Notes, SFML API Documentation
 * 
 *
 * Finds a path through a given maze using BFS and DFS searching methods of 2D arrays.
 */
#ifndef SEARCH_FUNCTIONS_H
#define SEARCH_FUNCTIONS_H

#include "Position.h"

#include <vector>

/**
 * @brief Searches a maze using Depth-First Search
 * 
 * @param pMaze 2D Array of a maze
 * @param pSpaceChecked 2D Array of booleans
 * @param ROWS Total rows
 * @param COLS Total columns
 * @param START Start position
 * @param toColor Vector of spaces to color
 */
void dfs(char** &pMaze, bool** &pSpaceChecked, const int ROWS, const int COLS, const Position START, std::vector<Position>& toColor);

/**
 * @brief Searches a maze using Breadth-First Search
 * 
 * @param pMaze 2D Array of a maze
 * @param pSpaceChecked 2D Array of booleans
 * @param ROWS Total rows
 * @param COLS Total columns
 * @param START Start position
 * @param toColor Vector of spaces to color
 */
void bfs(char** &pMaze, bool** &pSpaceChecked, const int ROWS, const int COLS, const Position START, std::vector<Position>& toColor);

/**
 * @brief Checks that the current position in the maze is navigatable and hasn't been checked
 * 
 * @param pMaze 2D Array of a maze
 * @param pCheck 2D Array of booleans
 * @param POS Position to check
 * @return int 
 */
int check(char** pMaze, bool** pCheck, const Position POS);

#endif