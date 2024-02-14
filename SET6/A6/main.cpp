/* CSCI 200: Assignment A6: Maze Runner
 *
 * Author: Thomas McInnes
 * Resources used: Lecture Notes, SFML API Documentation
 * 
 *
 * Finds a path through a given maze using BFS and DFS searching methods of 2D arrays.
 */
#include "Position.h"
#include "SearchFunctions.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace std;

int main() {

    ifstream fileIn;
    string filename;

    // takes filename input
    cout << "Enter filename:" << endl;
    cin >> filename;

    // opens file and checks for error
    fileIn.open( filename );
    if( fileIn.fail() ) {
        cerr << "Error opening file \"" << filename << "\"" << endl;
        return -1;
    }

    // reads in the numbers for the rows and columns of the maze
    int rows, cols;
    fileIn >> rows;
    fileIn >> cols;

    // creates a 2D array of characters
    char** pArray = new char*[rows];
    for( int i = 0; i < rows; i++ ) {
        pArray[i] = new char[cols];
    }

    // creates 2D array of booleans, checking if each space has been visited or not
    bool** pSpaceChecked = new bool*[rows];
    for( int i = 0; i < rows; i++ ) {
        pSpaceChecked[i] = new bool[cols];
    }

    // inserts each item from the input maze into the 2D array, also adds start position to toCheck list
    char character;
    Position start;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            fileIn >> character;
            pArray[i][j] = character;
            pSpaceChecked[i][j] = false;
            if( character == 'S' ) {
                start = Position(i, j);
            }
        }
    }

    // the squares to draw
    sf::RectangleShape rect;

    // animation stuff
    vector<Position> toColor; // holds the order in which to animate the squares
    int oneAtATimePlease = 0; // this makes sure the loop only colors one square at a time

    // prompts user to select DFS or BFS
    int choice;
    cout << "How would you like to solve this maze?\n1 - DFS\n2 - BFS" << endl;
    cin >> choice;

    if( choice == 1 ) {
        dfs(pArray, pSpaceChecked, rows, cols, start, toColor);
    } else {
        bfs(pArray, pSpaceChecked, rows, cols, start, toColor);
    }

    // sets up window
    // i scaled the size of the boxes up because the smaller mazes are smaller than my SFML window's minimum size
    int winWidth = 30 * cols;
    int winHeight = 30 * rows;

    sf::RenderWindow window( sf::VideoMode(winWidth, winHeight), "L6C: Maze Drawer" );
    sf::Event event;

    while( window.isOpen() ) {

        window.clear();

        // draws each box within the 2D array
        for( int i = 0; i < rows; i++ ) {
            for( int j = 0; j < cols; j++ ) {
                rect.setPosition(j * 30, i * 30);
                rect.setSize({30, 30});
                if( pArray[i][j] == 'P' ) { rect.setFillColor(sf::Color::Magenta); }
                if( pArray[i][j] == '.' ) {
                    Position currentCheck(i, j);
                    if( oneAtATimePlease == 0 && toColor.size() > 0 && currentCheck.c == toColor.at(0).c && currentCheck.r == toColor.at(0).r ) {
                        pArray[i][j] = 'P';
                        toColor.erase(toColor.begin());
                        oneAtATimePlease = 1;
                    }
                    rect.setFillColor(sf::Color::White); 
                }
                if( pArray[i][j] == '#' ) { rect.setFillColor(sf::Color::Black); }
                if( pArray[i][j] == 'S' ) { rect.setFillColor(sf::Color::Green); }
                if( pArray[i][j] == 'E' ) { rect.setFillColor(sf::Color::Red); }
                window.draw(rect);
            }
        }

        oneAtATimePlease = 0;
        window.display();

        while( window.pollEvent(event) ) {
            // closes window when user closes window
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::sleep( sf::milliseconds(50) );
    }

    return 0;
}