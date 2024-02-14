/* CSCI 200: Assignment A5: Polygon Land
 *
 * Author: Thomas McInnes
 * Resources used: SFML API Documentation, Shoelace formula (for determining area of a triangle with vertices)
 * 
 *
 * Draws shapes (triangles and rhombuses) based on an input file using various classes
 */
#include "Rhombus.h"
#include "PolygonFunctions.h"

bool Rhombus::validate() {
    double sideOne = sideLength(mVertexArray, 0, 1);
    double sideTwo = sideLength(mVertexArray, 1, 2);
    double sideThree = sideLength(mVertexArray, 2, 3);
    double sideFour = sideLength(mVertexArray, 3, 0);

    if( triCheck('I', mVertexArray, 0, 1, 2) && triCheck('I', mVertexArray, 0, 2, 3) ) {
        if( (sideOne == sideTwo) && (sideOne == sideThree) && (sideOne == sideFour) ) {
            return true; // if the two triangles are isosceles and all four sides are equal, returns true
        }
    }
    return false; // if rhombus conditions fail, returns false
}