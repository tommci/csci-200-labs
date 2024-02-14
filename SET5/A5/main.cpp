/* CSCI 200: Assignment A5: Polygon Land
 *
 * Author: Thomas McInnes
 * Resources used: SFML API Documentation, Shoelace formula (for determining area of a triangle with vertices)
 * 
 *
 * Draws shapes (triangles and rhombuses) based on an input file using various classes
 */
#include "ScaleneTriangle.h"
#include "EquilateralTriangle.h"
#include "IsoscelesTriangle.h"
#include "Rhombus.h"
#include "PolygonFunctions.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    // polygon+file setup
    vector<APolygon*> polygonList;
    string filename;
    ifstream fileIn;
    char character;

    // prompts user to enter filename (how filenames are to be handled was not specified in project description, so this is how I went about it)
    cout << "Enter name of file to read:" << endl;
    cin >> filename;

    // opens file, checks for error
    fileIn.open( filename );
    if ( fileIn.fail() ) {
        cerr << "Error opening file \"" << filename << "\"" << endl;
        return -1;
    }

    // do stuff with file (adds each polygon as specified in file to polygon list)
    while( !fileIn.eof() ) {
        fileIn.get(character);
        if( fileIn.fail() ) { break; } // checks if getting from file failed: always occurs at EOF
        if( character == 'S' ) {
            ScaleneTriangle* pScaleneTri = new ScaleneTriangle;
            buildPolygon(pScaleneTri, fileIn, polygonList, character);
        }
        if( character == 'E' ) {
            EquilateralTriangle* pEquilTri = new EquilateralTriangle;
            buildPolygon(pEquilTri, fileIn, polygonList, character);
        }
        if( character == 'I' ) {
            IsoscelesTriangle* pIsoTri = new IsoscelesTriangle;
            buildPolygon(pIsoTri, fileIn, polygonList, character);
        }
        if( character == 'R' ) {
            Rhombus* pRhombus = new Rhombus;
            buildPolygon(pRhombus, fileIn, polygonList, character);
        }
    }
    
    // close file, done with it now
    fileIn.close();

    // SFML window setup
    int windowWidth = 800, windowHeight = 800;
    sf::RenderWindow window( sf::VideoMode(windowWidth, windowHeight), "A5: Polygon Land" );
    sf::Event event;

    while( window.isOpen() ) {
        window.clear();

        // iterates through polygon list, draws each polygon
        for( size_t i = 0; i < polygonList.size(); i++ ) {
            polygonList.at(i)->draw(window);
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