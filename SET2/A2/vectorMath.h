/* CSCI 200: Assignment A2: Complex Vector Math!
 *
 * Author: Thomas McInnes
 * Resources used: 
 * TA Help Hours
 *
 * Does complex vector math to find how points rotate 
 */
#ifndef VECTOR_MATH_H // if not defined
#define VECTOR_MATH_H

/**
 * @brief prompts the user to enter the (x, y) coordinate and updates the corresponding parameters
 * 
 * @param pX float pointer corresponding to the point's x coordinate
 * @param pY float pointer corresponding to the point's y coordinate
 */
void point_input(float *pX, float *pY);

/**
 * @brief prompts the user to enter an angle and updates the corresponding parameter
 * 
 * @param pAngle float pointer corresponding to the angle
 */
void angle_input(float *pAngle);

/**
 * @brief converts an angle with the positive X-axis to the resultant vector on the unit circle
 * 
 * @param xAngle float corresponding to the angle from the positive X-axis
 * @param pVectorX float pointer corresponding to the resultant vector's x coordinate
 * @param pVectorY float pointer corresponding to the resultant vector's y coordinate
 */
void angle_to_vector(float xAngle, float *pVectorX, float *pVectorY);

/**
 * @brief prompts the user to enter the <x, y> coordinate and updates the corresponding parameters
 * 
 * @param pVectorX float pointer corresponding to the vector's x coordinate
 * @param pVectorY float pointer corresponding to the vector's y coordinate
 */
void vector_input(float *pVectorX, float *pVectorY);

/**
 * @brief normalizes the input vector setting the corresponding pointer parameters to the output normalized vector
 * 
 * @param vectorX float corresponding to the input vector's x coordinate
 * @param vectorY float corresponding to the input vector's y coordinate
 * @param pVectorX float pointer corresponding to the output normalized vector's x coordinate
 * @param pVectorY float pointer corresponding to the output normalized vector's y coordinate
 */
void vector_normalize(float vectorX, float vectorY, float *pVectorX, float *pVectorY);

/**
 * @brief determines the angle the vector forms with the positive X-axis based on where it intersects the unit circle
 * 
 * @param vectorX float corresponding to the vector's x coordinate
 * @param vectorY float corresponding to the vector's y coordinate
 * @return float corresponding to the angle the vector forms with the positive X-axis
 */
float vector_to_angle(float vectorX, float vectorY);

/**
 * @brief 
 * 
 * @param x float corresponding to the input point's x coordinate
 * @param y float corresponding to the input point's y coordinate
 * @param vectorX float corresponding to the input vector's x coordinate
 * @param vectorY float corresponding to the input vector's y coordinate
 * @param pOutputX float pointer corresponding to the output rotated point's x coordinate
 * @param pOutputY float pointer corresponding to the output rotated point's y coordinate
 */
void rotate_point_by_vector(float x, float y, float vectorX, float vectorY, float *pOutputX, float *pOutputY);

/**
 * @brief finds the magnitude of a given vector
 * 
 * @param vectorX float corresponding to vector's x value
 * @param vectorY float corresponding to vector's y value
 * @return float corresponding to magnitude of vector
 */
float find_vector_length(float vectorX, float vectorY);

#endif