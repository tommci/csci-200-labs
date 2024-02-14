/* CSCI 200: Assignment A5: Polygon Land
 *
 * Author: Thomas McInnes
 * Resources used: SFML API Documentation, Shoelace formula (for determining area of a triangle with vertices)
 * 
 *
 * Draws shapes (triangles and rhombuses) based on an input file using various classes
 */
#include "Coordinate.h"

Coordinate::Coordinate() {
    x = 0;
    y = 0;
}

Coordinate::Coordinate(const double X_VAL, const double Y_VAL) {
    x = X_VAL;
    y = Y_VAL;
}