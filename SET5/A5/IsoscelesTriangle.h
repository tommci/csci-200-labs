/* CSCI 200: Assignment A5: Polygon Land
 *
 * Author: Thomas McInnes
 * Resources used: SFML API Documentation, Shoelace formula (for determining area of a triangle with vertices)
 * 
 *
 * Draws shapes (triangles and rhombuses) based on an input file using various classes
 */
#ifndef ISOSCELES_TRIANGLE_H
#define ISOSCELES_TRIANGLE_H

#include "Triangle.h"

/**
 * @brief Isosceles Triangle object (at least 2 sides of same length)
 * 
 */
class IsoscelesTriangle : public ATriangle {
public:
    /**
     * @brief Validates the vertices provided create an isosceles triangle
     * 
     * @return true 
     * @return false 
     */
    bool validate() override;
};

#endif