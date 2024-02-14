/* CSCI 200: Assignment L2C: Coordinate Conversion By Pointer
 *
 * Author: Thomas McInnes
 * Coauthor: Nev Ahrendsen, Macy Algrim
 *
 * Converts polar coordinates to cartesian and vice versa.
 */
#ifndef COORDINATE_CONVERSION_H
#define COORDINATE_CONVERSION_H

/**
 * @brief converts polar coordinates to cartesian
 * 
 * @param radius double, r in polar
 * @param angle double, theta in polar in radians
 */
void polar_to_cartesian( double RADIUS, const double ANGLE, double *pXCoordinate, double *pYCoordinate );

/**
 * @brief converts cartesian coordinates to polar
 * 
 * @param xCoordinate double, x value
 * @param yCoordinate double, y value
 */
void cartesian_to_polar( const double X, const double Y, double *pRadius, double *pAngle );

#endif