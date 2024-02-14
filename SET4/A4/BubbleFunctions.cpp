/* CSCI 200: Assignment A4: Bubble Bobble
 *
 * Author: Thomas McInnes
 * Resources used: SFML API Documentation
 * 
 *
 * Creates a window with bubbles that float around and can be created/popped
 */
#include "BubbleFunctions.h"

void createBubble( std::vector<Bubble>& bubbleVector, sf::RenderWindow& window, const bool MOUSE) {
    int radius = rand() % ((50 + 1) - 10) + 10;
    int colorR = rand() % ((255 + 1) - 0) + 0;
    int colorG = rand() % ((255 + 1) - 0) + 0;
    int colorB = rand() % ((255 + 1) - 0) + 0;
    float x, y;
    if( !MOUSE ) {
        x = rand() / (float)RAND_MAX * (400 - 100) + 100;
        y = rand() / (float)RAND_MAX * (400 - 100) + 100;
    } else {
        x = sf::Mouse::getPosition(window).x - radius;
        y = sf::Mouse::getPosition(window).y - radius;
    }
    double xDir = (rand() / (float)RAND_MAX * (0.1667 - 0) + 0) - (rand() / (float)RAND_MAX * (0.1667 - 0) + 0);
    double yDir = (rand() / (float)RAND_MAX * (0.1667 - 0) + 0) - (rand() / (float)RAND_MAX * (0.1667 - 0) + 0);
    bubbleVector.push_back(Bubble(radius, x, y, xDir, yDir, colorR, colorG, colorB));
}