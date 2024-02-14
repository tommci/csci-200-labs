/* CSCI 200: Assignment L6C: Maze Drawer
 *
 * Author: Thomas McInnes
 * Resources used: Lecture Notes, SFML API Documentation
 * 
 *
 * Draws a maze using SFML based on an input file using a 2D dynamic array
 */
#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>

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

    // inserts each item from the input maze into the 2D array
    char character;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            fileIn >> character;
            pArray[i][j] = character;
        }
    }

    // i scaled the size of the boxes up because the smaller mazes are smaller than my SFML window's minimum size.
    int windowWidth = cols * 30, windowHeight = rows * 30;

    // sets up window
    sf::RenderWindow window( sf::VideoMode(windowWidth, windowHeight), "L6C: Maze Drawer" );
    sf::Event event;

    sf::RectangleShape rect;

    while( window.isOpen() ) {

        window.clear();

        // draws each box within the 2D array
        for( int i = 0; i < rows; i++ ) {
            for( int j = 0; j < cols; j++ ) {
                rect.setPosition(j * 30, i * 30);
                rect.setSize({30, 30});
                if( pArray[i][j] == '.' ) { rect.setFillColor(sf::Color::White); }
                if( pArray[i][j] == '#' ) { rect.setFillColor(sf::Color::Black); }
                if( pArray[i][j] == 'S' ) { rect.setFillColor(sf::Color::Green); }
                if( pArray[i][j] == 'E' ) { rect.setFillColor(sf::Color::Red); }
                window.draw(rect);
            }
        }

        window.display();

        while( window.pollEvent(event) ) {
            // closes window when user closes window
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    return 0;
}