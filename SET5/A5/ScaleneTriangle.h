/* CSCI 200: Assignment A5: Polygon Land
 *
 * Author: Thomas McInnes
 * Resources used: SFML API Documentation, Shoelace formula (for determining area of a triangle with vertices)
 * 
 *
 * Draws shapes (triangles and rhombuses) based on an input file using various classes
 */
#ifndef SCALENE_TRIANGLE_H
#define SCALENE_TRIANGLE_H

#include "Triangle.h"

/**
 * @brief Scalene Triangle object. Comprised of 3 vertices, with no sides being equal
 * 
 */
class ScaleneTriangle : public ATriangle {
public:
    /**
     * @brief Validates that the vertices provided form a valid scalene triangle
     * 
     * @return true 
     * @return false 
     */
    bool validate() override;
};

#endif