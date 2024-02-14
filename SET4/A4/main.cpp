/* CSCI 200: Assignment A4: Bubble Bobble
 *
 * Author: Thomas McInnes
 * Resources used: SFML API Documentation
 * 
 *
 * Creates a window with bubbles that float around and can be created/popped
 */
#include "Bubble.h"
#include "BubbleFunctions.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    // seed RNG, throw away first value
    srand(time(0));
    rand();

    // setup window
    int windowWidth = 800, windowHeight = 800;
    sf::RenderWindow window( sf::VideoMode(windowWidth, windowHeight), "A4: Bubble Bobble" );

    // create clock object to count time
    sf::Clock clock;

    // declare vector of bubbles
    vector<Bubble> bubbleVector;

    // add five bubbles to vector of bubbles with random qualities
    for( int i = 0; i < 5; i++ ) {
        createBubble(bubbleVector, window, false);
    }

    sf::Event event;

    while( window.isOpen() ) {
        window.clear();

        for( size_t i = 0; i < bubbleVector.size(); i++) {
            bubbleVector.at(i).draw(window);
        }

        window.display();

        while( window.pollEvent(event) ) {

            if(event.type == sf::Event::Closed) {
                window.close();
            }
            // creates a bubble where the user clicks
            if(event.type == sf::Event::MouseButtonReleased) {
                createBubble(bubbleVector, window, true);
            }
            // closes window if user presses Q or ESC
            if(event.type == sf::Event::KeyPressed) {
                if( sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
                    if( bubbleVector.size() != 0) { bubbleVector.pop_back(); }
                }
                if( sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ) {
                    window.close();
                }
            }
        }

        // updates bubble positions every 1/60th of a second
        if( clock.getElapsedTime().asMilliseconds() > 16 ) {
            for( size_t i = 0; i < bubbleVector.size(); i++) {
                bubbleVector.at(i).updatePosition(windowWidth, windowHeight);
            }
            clock.restart();
        }
        // clock.restart();
        // if (clock.getElapsedTime().asSeconds() == (1/60) ) {
        //     for( size_t i = 0; i < bubbleVector.size(); i++) {
        //         bubbleVector.at(i).updatePosition(windowWidth, windowHeight);
        //     }
        // }

    }

    return 0;
}