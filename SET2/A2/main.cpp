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

int main() {

    // floats
    float x, y, angle, vectorX, vectorY, rotatedX, rotatedY, inputVectorX, inputVectorY;

    // float pointers
    float *pX = &x, *pY = &y, *pAngle = &angle,
          *pVectorX = &vectorX, *pVectorY = &vectorY,
          *pRotatedX = &rotatedX, *pRotatedY = &rotatedY;

    int menuChoice = -1;    // sets to -1, not 0, so loop actually starts
    while( menuChoice != 0) {

        cout << "Menu:\n    1) Enter point (x, y) coordinate\n"
        "    2) Rotate point by angle\n    3) Rotate point by vector\n"
        "    0) Quit\nChoice: ";
        cin >> menuChoice;

        if( menuChoice == 1 ) {     // enter (x, y) coord

            point_input(pX, pY);

        } else if( menuChoice == 2 ) {  // rotate point by angle

            angle_input(pAngle);
            angle_to_vector(angle, pVectorX, pVectorY); // convert given angle to vector, and then computes rotation
            vector_normalize(vectorX, vectorY, pVectorX, pVectorY); // normalizes vector found just now
            rotate_point_by_vector(x, y, vectorX, vectorY, pRotatedX, pRotatedY);

            cout << "The point (" << x << ", "
            << y << ") rotated by " << angle << " degrees is now at (" << rotatedX << ", " << rotatedY << ")" << endl;
            x = rotatedX, y = rotatedY;     // sets our effective x and y values to what we just found

        } else if( menuChoice == 3 ) { // rotate point by vector

            vector_input(pVectorX, pVectorY);
            inputVectorX = vectorX, inputVectorY = vectorY;     // distinguishes between the normalized vector and the actual vector input by the user, for the console output
            vector_normalize(vectorX, vectorY, pVectorX, pVectorY);     // normalizes the vector that the user entered
            rotate_point_by_vector(x, y, vectorX, vectorY, pRotatedX, pRotatedY);

            cout << "The point (" << x << ", " << y << ") rotated by the vector <" << inputVectorX << ", " << inputVectorY << "> (" << vector_to_angle(vectorX, vectorY) << " degrees) is now at (" << rotatedX << ", " << rotatedY << ")" << endl;
            x = rotatedX, y = rotatedY;

        } else if( menuChoice == 0) { 
            break; 
        } else {  // If entered input is not 0, 1, 2, or 3

            cout << "Invalid input, enter a valid option" << endl;
            
        }
    }

    cout << "Ending program gracefully..." << endl;
    return 0;
}
