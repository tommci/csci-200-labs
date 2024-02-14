/* CSCI 200: Assignment A5: Polygon Land
 *
 * Author: Thomas McInnes
 * Resources used: SFML API Documentation, Shoelace formula (for determining area of a triangle with vertices)
 * 
 *
 * Draws shapes (triangles and rhombuses) based on an input file using various classes
 */
#include "Polygon.h"

APolygon::APolygon() {
    _triangleColor = sf::Color::White;
    mVertices = 0;
    mVertexArray = nullptr;
}

APolygon::~APolygon() {
    delete[] mVertexArray;
    delete this;
}

void APolygon::setColor(const sf::Color color) {
    _triangleColor = color;
}

void APolygon::draw(sf::RenderTarget& window) const {
    sf::ConvexShape shape;
    shape.setPointCount(mVertices);
    for( int i = 0; i < mVertices; i++) {
        shape.setPoint(i, {(float)mVertexArray[i].x, (float)mVertexArray[i].y});
    }
    shape.setFillColor(_triangleColor);
    window.draw(shape);
}

void APolygon::setCoordinate(const int IDX, const Coordinate COORD) {
    mVertexArray[IDX] = COORD;
}
