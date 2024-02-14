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

int main() {

    double radius, angle, x, y;
    double *pRadius = &radius, *pAngle = &angle, *pX = &x, *pY = &y;

    cout << "Welcome to the polar-cartesian converter.\nSelect your preferred conversion now:" << endl;
    cout << "1. (r, theta) -> (x, y)\n2. (x, y) -> (r, theta)" << endl;

    int selection = 0;
    cin >> selection;
    while( selection != 1 || selection != 2 ) {
        if( selection == 1 ) {     // only checks 2nd character in entry since it's always either r or x depending on the conversion
            cout << "Enter the radius: ";
            cin >> radius;
            cout << "Enter the angle (in radians): ";
            cin >> angle;
            polar_to_cartesian(radius, angle, pX, pY);

            cout << "(" << radius << ", " << angle << ") in polar = (" << x << ", " << y << ") in cartesian." << endl;
            break;

        } else if( selection == 2) {    // cartesian to polar
            cout << "Enter the x value: ";
            cin >> x;
            cout << "Enter the y value: ";
            cin >> y;
            cartesian_to_polar(x, y, pRadius, pAngle);

            cout << "(" << x << ", " << y << ") in cartesian = (" << radius << ", " << angle << ") in polar, with angle theta in radians." << endl;
            break;

        } else {
            cout << "Please select either 1 or 2." << endl;
            cin >> selection;
        }
    }
    cout << "Thanks for using the polar-cartesian converter." << endl;
    return 0;
}
