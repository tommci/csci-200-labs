/* CSCI 200: Assignment A5: Polygon Land
 *
 * Author: Thomas McInnes
 * Resources used: SFML API Documentation, Shoelace formula (for determining area of a triangle with vertices)
 * 
 *
 * Draws shapes (triangles and rhombuses) based on an input file using various classes
 */
#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Quadrilateral.h"

/**
 * @brief Rhombus object. Comprised of 2 isosceles triangles and 4 vertices
 * 
 */
class Rhombus : public AQuadrilateral {
public:
    /**
     * @brief Validates that the vertices provided form a valid rhombus
     * 
     * @return true 
     * @return false 
     */
    bool validate() override;
};

#endif