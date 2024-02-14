/* CSCI 200: Assignment A5: Polygon Land
 *
 * Author: Thomas McInnes
 * Resources used: SFML API Documentation, Shoelace formula (for determining area of a triangle with vertices)
 * 
 *
 * Draws shapes (triangles and rhombuses) based on an input file using various classes
 */
#include "Quadrilateral.h"

AQuadrilateral::AQuadrilateral() {
    mVertices = 4;
    mVertexArray = new Coordinate[4];
}
