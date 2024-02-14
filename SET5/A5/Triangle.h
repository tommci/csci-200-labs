/* CSCI 200: Assignment A5: Polygon Land
 *
 * Author: Thomas McInnes
 * Resources used: SFML API Documentation, Shoelace formula (for determining area of a triangle with vertices)
 * 
 *
 * Draws shapes (triangles and rhombuses) based on an input file using various classes
 */
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Polygon.h"

/**
 * @brief Generic Abstract Triangle object. Has 3 vertices.
 * 
 */
class ATriangle : public APolygon {
public:
    /**
     * @brief Construct a new ATriangle object
     * 
     */
    ATriangle();
};

#endif