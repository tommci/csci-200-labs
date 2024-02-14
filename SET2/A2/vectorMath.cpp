/* CSCI 200: Assignment A2: Complex Vector Math!
 *
 * Author: Thomas McInnes
 * Resources used: 
 * TA Help Hours
 *
 * Does complex vector math to find how points rotate 
 */
#include "vectorMath.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void point_input(float *pX, float *pY) {

    cout << "Enter point x coordinate: ";
    cin >> *pX;
    cout << "Enter point y coordinate: ";
    cin >> *pY;

}

void angle_input(float *pAngle) {

    cout << "Enter an angle in degrees: ";
    cin >> *pAngle;

}

void angle_to_vector(float xAngle, float *pVectorX, float *pVectorY) {

    *pVectorX = cos(xAngle * (M_PI/180)); // cmath works in radians. converts degrees to radians
    *pVectorY = sin(xAngle * (M_PI/180));

}

void vector_input(float *pVectorX, float *pVectorY) {

    cout << "Enter vector x coordinate: ";
    cin >> *pVectorX;
    cout << "Enter vector y coordinate: ";
    cin >> *pVectorY;

}

void vector_normalize(float vectorX, float vectorY, float *pVectorX, float *pVectorY) {

    *pVectorX = vectorX / find_vector_length(vectorX, vectorY);
    *pVectorY = vectorY / find_vector_length(vectorX, vectorY);

}

float vector_to_angle(float vectorX, float vectorY) {

    // checks edge cases, where x = 0 and y < 0
    if ( (vectorX != 0) && (vectorY >= 0) ) {    // want to avoid divide by 0 error, and when the vector points downward
        return atan2(vectorY, vectorX) * (180/M_PI);    // if no edge cases
    } else if( vectorX == 0 ) {
        if( vectorY < 0 ) {  // checks if both y < 0 and x = 0
            return 270;     
        } else { 
            return 90; 
        }
    } else {    // if x is not 0 but y < 0
        return 360 + atan2(vectorY, vectorX) * (180/M_PI);  // makes angle non-negative
    }
}

void rotate_point_by_vector(float x, float y, float vectorX, float vectorY, float *pOutputX, float *pOutputY) {

    *pOutputX = ((x * vectorX) - (y * vectorY));
    *pOutputY = ((x * vectorY) + (y * vectorX));

}

float find_vector_length(float vectorX, float vectorY) {

    return sqrt( (vectorX * vectorX) + (vectorY * vectorY) );

}
