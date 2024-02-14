/* CSCI 200: Assignment A5: Polygon Land
 *
 * Author: Thomas McInnes
 * Resources used: SFML API Documentation, Shoelace formula (for determining area of a triangle with vertices)
 * 
 *
 * Draws shapes (triangles and rhombuses) based on an input file using various classes
 */
#ifndef POLY_FUNCTIONS_H
#define POLY_FUNCTIONS_H

#include "Polygon.h"

/**
 * @brief Calculates the length of a side of a polygon given its vertices
 * 
 * @param vertexArray List of vertices within polygon object
 * @param IDX_ONE Index of point one
 * @param IDX_TWO Index of point two
 * @return double, side length cooresponding to vertexes chosen
 */
double sideLength(Coordinate* vertexArray, const int IDX_ONE, const int IDX_TWO);

/**
 * @brief Checks if the sides of a triangle provided form a triangle. Does NOT check for triangle type
 * 
 * @param SIDE_ONE Length of side one
 * @param SIDE_TWO Length of side two
 * @param SIDE_THREE Length of side three
 * @return true, the sides form a triangle
 * @return false, the sides do not form a triangle
 */
bool sideCheck(const double SIDE_ONE, const double SIDE_TWO, const double SIDE_THREE);

/**
 * @brief Checks if the three provided points form a proper triangle of specified type
 * 
 * @param TYPE Character denoting type of triangle
 * @param vertexArray Array of coordinates of points comprising triangle
 * @param IDX_ONE Index of point one in array
 * @param IDX_TWO Index of point two in array
 * @param IDX_THREE Index of point three in array
 * @return true, points form isosceles triangle
 * @return false, points do not form isosceles triangle
 */
bool triCheck(const char TYPE, Coordinate* vertexArray, const int IDX_ONE, const int IDX_TWO, const int IDX_THREE);

/**
 * @brief Checks if a polygon is valid, and adds it to a list of polygon pointers if it is
 * 
 * @param polygon Polygon pointer object
 * @param fileIn Input file object
 * @param polygonList List of polygon pointers
 * @param TYPE Character denoting polygon type. S, E, I are triangles, R is rhombus
 */
void buildPolygon(APolygon* polygon, std::ifstream& fileIn, std::vector<APolygon*>& polygonList, const char TYPE);

#endif