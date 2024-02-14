/* CSCI 200: Assignment A5: Polygon Land
 *
 * Author: Thomas McInnes
 * Resources used: SFML API Documentation, Shoelace formula (for determining area of a triangle with vertices)
 * 
 *
 * Draws shapes (triangles and rhombuses) based on an input file using various classes
 */
#ifndef POLYGON_H
#define POLYGON_H

#include <SFML/Graphics.hpp>
#include "Coordinate.h"

/**
 * @brief Generic abstract Polygon class. Creates a polygon with a color and shape, and draws it to the window
 * 
 */
class APolygon {
public:
    /**
     * @brief Construct a new APolygon object
     * 
     */
    APolygon();

    /**
     * @brief Destroy the APolygon object
     * 
     */
    virtual ~APolygon();

    /**
     * @brief Set the Color of the polygon
     * 
     * @param color SFML Color value, of form (r, g, b)
     */
    void setColor(const sf::Color color);

    /**
     * @brief Draws the polygon to the window
     * 
     * @param window SFML RenderWindow object
     */
    void draw(sf::RenderTarget& window) const;

    /**
     * @brief Sets the coordinates of the polygon
     * 
     * @param IDX Index of coordinate
     * @param COORD Coordinate object, containing an x and y value
     */
    void setCoordinate(const int IDX, const Coordinate COORD);

    /**
     * @brief Pure abstract function, utilized to validate if a polygon is valid or not
     * 
     * @return true 
     * @return false 
     */
    virtual bool validate() = 0;

protected:
    short int mVertices; // number of vertices in polygon
    Coordinate* mVertexArray; // array of coordinates of the vertices
private:
    sf::Color _triangleColor; // SFML color object that colors the polygon
};

#endif