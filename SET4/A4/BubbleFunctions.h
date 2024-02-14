/* CSCI 200: Assignment A4: Bubble Bobble
 *
 * Author: Thomas McInnes
 * Resources used: SFML API Documentation
 * 
 *
 * Creates a window with bubbles that float around and can be created/popped
 */
#ifndef BUBBLE_FUNCTIONS_H
#define BUBBLE_FUNCTIONS_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Bubble.h"

/**
 * @brief Creates a bubble and adds it to a vector of bubbles
 * 
 * @param bubbleVector The bubble vector to add a bubble to
 * @param window The window in which the bubble is drawn
 * @param MOUSE Whether or not the bubble is created at the mouse's position
 */
void createBubble( std::vector<Bubble>& bubbleVector, sf::RenderWindow& window, const bool MOUSE );

#endif