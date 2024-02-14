/* CSCI 200: Assignment A5: Polygon Land
 *
 * Author: Thomas McInnes
 * Resources used: SFML API Documentation, Shoelace formula (for determining area of a triangle with vertices)
 * 
 *
 * Draws shapes (triangles and rhombuses) based on an input file using various classes
 */
#ifndef EQUIL_TRIANGLE_H
#define EQUIL_TRIANGLE_H

#include "Triangle.h"

/**
 * @brief Equilateral Triangle object (all 3 sides of same length)
 * 
 */
class EquilateralTriangle : public ATriangle {
public:
    /**
     * @brief Validates the vertices provided create an equilateral triangle
     * 
     * @return true 
     * @return false 
     */
    bool validate() override;
};

#endif