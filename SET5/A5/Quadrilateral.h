/* CSCI 200: Assignment A5: Polygon Land
 *
 * Author: Thomas McInnes
 * Resources used: SFML API Documentation, Shoelace formula (for determining area of a triangle with vertices)
 * 
 *
 * Draws shapes (triangles and rhombuses) based on an input file using various classes
 */
#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include "Polygon.h"

/**
 * @brief Generic Abstract Quadrilateral object. Holds 4 vertices
 * 
 */
class AQuadrilateral : public APolygon {
public:
    /**
     * @brief Construct a new AQuadrilateral object
     * 
     */
    AQuadrilateral();
};

#endif