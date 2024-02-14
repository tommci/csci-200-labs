/* CSCI 200: Assignment A5: Polygon Land
 *
 * Author: Thomas McInnes
 * Resources used: SFML API Documentation, Shoelace formula (for determining area of a triangle with vertices)
 * 
 *
 * Draws shapes (triangles and rhombuses) based on an input file using various classes
 */
#include "EquilateralTriangle.h"
#include "PolygonFunctions.h"

bool EquilateralTriangle::validate() {
    return triCheck('E', mVertexArray, 0, 1, 2);
}