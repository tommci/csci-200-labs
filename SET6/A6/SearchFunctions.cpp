/* CSCI 200: Assignment A6: Maze Runner
 *
 * Author: Thomas McInnes
 * Resources used: Lecture Notes, SFML API Documentation
 * 
 *
 * Finds a path through a given maze using BFS and DFS searching methods of 2D arrays.
 */
#include "SearchFunctions.h"

#include <stack>
#include <queue>
#include <iostream>

using namespace std;

void dfs(char** &pMaze, bool** &pSpaceChecked, const int ROWS, const int COLS, const Position START, vector<Position>& toColor) {
    stack<Position> stack;
    Position currentPos, tempPos;
    stack.push(START);
    
    // dfs uses stack
    while( !stack.empty() ) {
        currentPos = stack.top();
        stack.pop();
        if( !pSpaceChecked[currentPos.r][currentPos.c] ) {
            pSpaceChecked[currentPos.r][currentPos.c] = true;
            if( pMaze[currentPos.r][currentPos.c] == '.' ) { 
                toColor.push_back(currentPos);
            }
        }

        // i is direction
        for( int i = 0; i < 4; i++ ) {
            tempPos = currentPos;
            // down
            if( i == 0 ) {
                tempPos.r += 1;
                if( !(tempPos.r >= ROWS) ) {
                    if( check(pMaze, pSpaceChecked, tempPos) == 1 ) {
                        cout << "End found" << endl;
                        return; // end found
                    } else if( check(pMaze, pSpaceChecked, tempPos) == 0 ) {
                        stack.push(tempPos);
                    }
                }
            // right
            } else if( i == 1 ) {
                tempPos.c += 1;
                if( !(tempPos.c >= COLS) ) {
                    if( check(pMaze, pSpaceChecked, tempPos) == 1 ) {
                        cout << "End found" << endl;
                        return; // end found
                    } else if( check(pMaze, pSpaceChecked, tempPos) == 0 ) {
                        stack.push(tempPos);
                    }
                }
            // up
            } else if( i == 2 ) {
                tempPos.r -= 1;
                if( !(tempPos.r < 0) ) {
                    if( check(pMaze, pSpaceChecked, tempPos) == 1 ) {
                        cout << "End found" << endl;
                        return; // end found
                    } else if( check(pMaze, pSpaceChecked, tempPos) == 0 ) {
                        stack.push(tempPos);
                    }
                }
            // left
            } else {
                tempPos.c -= 1;
                if( !(tempPos.c < 0) ) {
                    if( check(pMaze, pSpaceChecked, tempPos) == 1 ) {
                        cout << "End found" << endl;
                        return; // end found
                    } else if( check(pMaze, pSpaceChecked, tempPos) == 0 ) {
                        stack.push(tempPos);
                    }
                }                
            }
        }
    }
}

void bfs(char** &pMaze, bool** &pSpaceChecked, const int ROWS, const int COLS, const Position START, vector<Position>& toColor) {
    queue<Position> queue;
    Position currentPos, tempPos;
    queue.push(START);

    // bfs uses queue
    while( !queue.empty() ) {
        currentPos = queue.front();
        queue.pop();

        if( !pSpaceChecked[currentPos.r][currentPos.c] ) {
            pSpaceChecked[currentPos.r][currentPos.c] = true;
            if( pMaze[currentPos.r][currentPos.c] == '.' ) { 
                toColor.push_back(currentPos);
            }
        }

        // i is direction
        for( int i = 0; i < 4; i++ ) {
            tempPos = currentPos;
            // down
            if( i == 0 ) {
                tempPos.r += 1;
                if( !(tempPos.r >= ROWS) ) {
                    if( check(pMaze, pSpaceChecked, tempPos) == 1 ) {
                        cout << "End found" << endl;
                        return; // end found
                    } else if( check(pMaze, pSpaceChecked, tempPos) == 0 ) {
                        queue.push(tempPos);
                    }
                }
            // right
            } else if( i == 1 ) {
                tempPos.c += 1;
                if( !(tempPos.c >= COLS) ) {
                    if( check(pMaze, pSpaceChecked, tempPos) == 1 ) {
                        cout << "End found" << endl;
                        return; // end found
                    } else if( check(pMaze, pSpaceChecked, tempPos) == 0 ) {
                        queue.push(tempPos);
                    }
                }
            // up
            } else if( i == 2 ) {
                tempPos.r -= 1;
                if( !(tempPos.r < 0) ) {
                    if( check(pMaze, pSpaceChecked, tempPos) == 1 ) {
                        cout << "End found" << endl;
                        return; // end found
                    } else if( check(pMaze, pSpaceChecked, tempPos) == 0 ) {
                        queue.push(tempPos);
                    }
                }
            // left
            } else {
                tempPos.c -= 1;
                if( !(tempPos.c < 0) ) {
                    if( check(pMaze, pSpaceChecked, tempPos) == 1 ) {
                        cout << "End found" << endl;
                        return; // end found
                    } else if( check(pMaze, pSpaceChecked, tempPos) == 0 ) {
                        queue.push(tempPos);
                    }
                }                
            }
        }
    }
}

int check(char** pMaze, bool** pCheck, const Position POS) {
    if(pCheck[POS.r][POS.c] == 0) {
        if( pMaze[POS.r][POS.c] == '.' ) {
            return 0; // position is valid to move to
        } else if( pMaze[POS.r][POS.c] == 'E' ) {
            return 1; // position is the end point
        }
    }
    return -1; // position is not valid to move to (been checked or is wall)
}