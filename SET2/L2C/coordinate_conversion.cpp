/* CSCI 200: Assignment L2C: Coordinate Conversion By Pointer
 *
 * Author: Thomas McInnes
 * Coauthor: Nev Ahrendsen, Macy Algrim
 *
 * Converts polar coordinates to cartesian and vice versa.
 */
#include "coordinate_conversion.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void polar_to_cartesian( double RADIUS, const double ANGLE, double *pXCoordinate, double *pYCoordinate ) {

    *pXCoordinate = RADIUS * cos(ANGLE);
    *pYCoordinate = RADIUS * sin(ANGLE);

}

void cartesian_to_polar( const double X, const double Y, double *pRadius, double *pAngle ) {

    *pRadius = sqrt((X * X) + (Y * Y));
    *pAngle = atan2(Y, X);

}
