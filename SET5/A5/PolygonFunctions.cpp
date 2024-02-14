/* CSCI 200: Assignment A5: Polygon Land
 *
 * Author: Thomas McInnes
 * Resources used: SFML API Documentation, Shoelace formula (for determining area of a triangle with vertices)
 * 
 *
 * Draws shapes (triangles and rhombuses) based on an input file using various classes
 */
#include "PolygonFunctions.h"

#include <cmath>
#include <fstream>
#include <iostream>

double sideLength(Coordinate* vertexArray, const int IDX_ONE, const int IDX_TWO) {
    return abs( sqrt( pow((vertexArray[IDX_TWO].x - vertexArray[IDX_ONE].x), 2) + pow((vertexArray[IDX_TWO].y - vertexArray[IDX_ONE].y), 2)) );
}

bool sideCheck(const double SIDE_ONE, const double SIDE_TWO, const double SIDE_THREE) {
    if( (SIDE_ONE * SIDE_TWO * SIDE_THREE) == 0 ) { return false; } // check if any side length is 0
    if( (SIDE_ONE + SIDE_TWO) > SIDE_THREE ) { return true; } // checks if sum of any two sides > third side
    else if( (SIDE_TWO + SIDE_THREE) > SIDE_ONE ) { return true; }
    else if( (SIDE_ONE + SIDE_THREE) > SIDE_TWO ) { return true; }
    return false;
}

bool triCheck(const char TYPE, Coordinate* vertexArray, const int IDX_ONE, const int IDX_TWO, const int IDX_THREE) {
    // check if vertices form a straight line or not (if area = 0)
    double area = vertexArray[IDX_ONE].x * (vertexArray[IDX_TWO].y - vertexArray[IDX_THREE].y)
    + vertexArray[IDX_TWO].x * (vertexArray[IDX_THREE].y - vertexArray[IDX_ONE].y)
    + vertexArray[IDX_THREE].x * (vertexArray[IDX_ONE].y - vertexArray[IDX_TWO].y);
    if( area == 0 ) { return false; } // if area is 0, it's a straight line, not a triangle

    double sideOne = sideLength(vertexArray, IDX_ONE, IDX_TWO);
    double sideTwo = sideLength(vertexArray, IDX_TWO, IDX_THREE);
    double sideThree = sideLength(vertexArray, IDX_THREE, IDX_ONE);

    // checks each individual triangle's properties
    if( TYPE == 'I' && sideCheck(sideOne, sideTwo, sideThree) ) {
        if( (sideOne == sideTwo) || (sideTwo == sideThree) || (sideThree == sideOne) ) {
            return true; // if triangle is valid and has at least two identical side lengths, returns true
        }
    }
    if( TYPE == 'S' && sideCheck(sideOne, sideTwo, sideThree) ) {
        if( (sideOne != sideTwo) && (sideTwo != sideThree) && (sideThree != sideOne) ) {
            return true; // if triangle is valid and side lengths are all different, returns true
        }
    }
    if( TYPE == 'E' && sideCheck(sideOne, sideTwo, sideThree) ) {
        if( (sideOne == sideTwo) && (sideOne == sideThree) ) {
            return true; // if triangle is valid and all three sides are identical, returns true
        }
    }
    return false; // if all if conditions fail, returns false
}

void buildPolygon(APolygon* polygon, std::ifstream& fileIn, std::vector<APolygon*>& polygonList, const char TYPE) {
    std::vector<double> xVals, yVals;
    double x, y;
    int r, g, b;
    int vertices;
    if( TYPE == 'E' || TYPE == 'S' || TYPE == 'I' ) { vertices = 3; } // checks if triangle or rhombus
    else { vertices = 4; }
    for( int i = 0; i < vertices; i++ ) {
        fileIn >> x;
        fileIn >> y;
        polygon->setCoordinate(i, Coordinate(x, y));
        xVals.push_back(x), yVals.push_back(y);
    }
    fileIn >> r;
    fileIn >> g;
    fileIn >> b;
    if( polygon->validate() ) {
        polygon->setColor(sf::Color(r, g, b));
        polygonList.push_back(polygon);
    } else { // if polygon is invalid, loops for amount of vertices
        std::cout << "polygon is invalid - \"" << TYPE << " "; 
        for( int i = 0; i < vertices; i++) {
           std::cout << xVals.at(i) << " " << yVals.at(i) << " ";
        }
        std::cout << r << " " << g << " " << b << "\"" << std::endl;
    }
}