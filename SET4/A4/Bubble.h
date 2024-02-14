/* CSCI 200: Assignment A4: Bubble Bobble
 *
 * Author: Thomas McInnes
 * Resources used: SFML API Documentation
 * 
 *
 * Creates a window with bubbles that float around and can be created/popped
 */
#ifndef BUBBLE_H
#define BUBBLE_H

#include <SFML/Graphics.hpp>

/**
 * @brief Creates a bubble to float around the window
 * 
 */
class Bubble {
public:

    /**
     * @brief Construct a new Bubble object
     * 
     */
    Bubble();
    /**
     * @brief Construct a new Bubble object
     * 
     * @param RADIUS Bubble radius
     * @param X Bubble starting pos (x)
     * @param Y Bubble starting pos (y)
     * @param XDIR Bubble movement direction (x)
     * @param YDIR Bubble movement direction (y)
     * @param COLOR_R Red value of bubble color
     * @param COLOR_G Green value of bubble color
     * @param COLOR_B Blue value of bubble color
     */
    Bubble(const int RADIUS, const float X, const float Y, const double XDIR, const double YDIR, const int COLOR_R, const int COLOR_G, const int COLOR_B);

    /**
     * @brief Get the Bubble object
     * 
     * @return sf::CircleShape bubble
     */
    sf::CircleShape getBubble() const;
    /**
     * @brief Get the bubble's x direction
     * 
     * @return double _xDir
     */
    double getXDir() const;
    /**
     * @brief Get the bubble's y direction
     * 
     * @return double _yDir
     */
    double getYDir() const;

    /**
     * @brief Draws the bubble to the specified window
     * 
     * @param window RenderWindow object to draw bubble to
     */
    void draw( sf::RenderWindow& window ) const;
    /**
     * @brief Updates the bubble's position in the window. Also checks for collision with window borders
     * 
     * @param WIDTH Width of window
     * @param HEIGHT Height of window
     */
    void updatePosition(const int WIDTH, const int HEIGHT);

private:

    sf::CircleShape _bubble;    // the bubble itself
    double _xDir;               // bubble's x velocity
    double _yDir;               // bubble's y velocity

};

#endif