/* CSCI 200: Assignment A5: Polygon Land
 *
 * Author: Thomas McInnes
 * Resources used: SFML API Documentation, Shoelace formula (for determining area of a triangle with vertices)
 * 
 *
 * Draws shapes (triangles and rhombuses) based on an input file using various classes
 */
#ifndef COORDINATE_H
#define COORDINATE_H

/**
 * @brief Coordinate object that holds an x and a y value
 * 
 */
class Coordinate {
public:
    /**
     * @brief Construct a new Coordinate object
     * 
     */
    Coordinate();
    /**
     * @brief Construct a new Coordinate object
     * 
     * @param X_VAL X coordinate value
     * @param Y_VAL Y coordinate value
     */
    Coordinate(const double X_VAL, const double Y_VAL);

    double x; // x coordinate
    double y; // y coordinate
};

#endif