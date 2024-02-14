/* CSCI 200: Assignment A4: Bubble Bobble
 *
 * Author: Thomas McInnes
 * Resources used: SFML API Documentation
 * 
 *
 * Creates a window with bubbles that float around and can be created/popped
 */
#include "Bubble.h"

Bubble::Bubble() {
    _bubble.setRadius(20);
    _bubble.setPosition(0, 0);
    _bubble.setFillColor(sf::Color(255, 255, 255, 255));
    _xDir = 1;
    _yDir = 1;
}

Bubble::Bubble(const int RADIUS, const float X, const float Y, const double XDIR, const double YDIR, const int COLOR_R, const int COLOR_G, const int COLOR_B) {
    _bubble.setRadius(RADIUS);
    _bubble.setPosition(X, Y);
    _bubble.setFillColor(sf::Color(COLOR_R, COLOR_G, COLOR_B, 255));
    _xDir = XDIR;
    _yDir = YDIR;
}

sf::CircleShape Bubble::getBubble() const {
    return _bubble;
}

double Bubble::getXDir() const {
    return _xDir;
}

double Bubble::getYDir() const {
    return _yDir;
}

void Bubble::draw( sf::RenderWindow& window ) const {
    window.draw( _bubble );
}

void Bubble::updatePosition(const int WIDTH, const int HEIGHT) {
    _bubble.setPosition((_bubble.getPosition().x + _xDir), (_bubble.getPosition().y + _yDir));
    // check left and right borders
    if( (_bubble.getPosition().x + (_bubble.getRadius() * 2) > WIDTH) || (_bubble.getPosition().x < 0) ) {
        _bubble.setPosition((_bubble.getPosition().x - _xDir), _bubble.getPosition().y);
        _xDir *= -1; // turns the bubble around when hitting a border
    }
    // check top and bottom borders
    if( (_bubble.getPosition().y + (_bubble.getRadius() * 2) > HEIGHT) || (_bubble.getPosition().y < 0) ) {
        _bubble.setPosition(_bubble.getPosition().x, _bubble.getPosition().y - _yDir);
        _yDir *= -1; // turns the bubble around when hitting a border
    }
}