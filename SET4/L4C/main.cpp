/* CSCI 200: Assignment L4C: SFML: Bob Ross
 *
 * Author: Thomas McInnes
 * Resources used: Lecture Slides, SFML API Documentation
 * 
 *
 * Experimenting with SFML to draw unique shapes
 */
#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
using namespace std;

void drawKitty(Font& font, RectangleShape& earOne, RectangleShape& earTwo, CircleShape& headBack, CircleShape& headFront, CircleShape& eyeOne, CircleShape& eyeTwo, Text& mouth);
void drawJake(CircleShape& jakeLeftEyeBack, CircleShape& jakeRightEyeBack, CircleShape& jakeLeftEyeTop, CircleShape& jakeRightEyeTop, CircleShape& jakeNose, ConvexShape& jakeMouth);
void drawJakeSnout(ConvexShape& jakeSnout);

int main() {
    // create a window
    RenderWindow window( VideoMode(600, 600), "L4C: Bob Ross" );

    /////////////////////////////////////
    // BEGIN ANY FILE LOADING
    
    Font font;
    if(!font.loadFromFile("data/arial.ttf")) { return -1; }

    //  END  ANY FILE LOADING
    /////////////////////////////////////

    // create an event object once to store future events
    Event event;

    // while the window is open
    while( window.isOpen() ) {
        // clear any existing contents
        window.clear(Color(255, 255, 255, 255));

        /////////////////////////////////////
        // BEGIN DRAWING HERE

        // Shape one: ( :3 )
        RectangleShape catEarOne, catEarTwo;
        CircleShape catHeadBack, catHeadFront, catEyeOne, catEyeTwo;
        Text catMouth;
        drawKitty(font, catEarOne, catEarTwo, catHeadBack, catHeadFront, catEyeOne, catEyeTwo, catMouth);
        window.draw(catEarOne), window.draw(catEarTwo), window.draw(catHeadBack), window.draw(catHeadFront), window.draw(catEyeOne), window.draw(catEyeTwo), window.draw(catMouth);

        // Shape two: Jake (this was physically agonizing to draw)
        CircleShape jakeLeftEyeTop, jakeLeftEyeBack, jakeRightEyeTop, jakeRightEyeBack, jakeNose;
        ConvexShape jakeSnout, jakeMouth;
        drawJake(jakeLeftEyeBack,jakeRightEyeBack, jakeLeftEyeTop, jakeRightEyeTop, jakeNose, jakeMouth);
        window.draw(jakeLeftEyeBack), window.draw(jakeRightEyeBack);
        window.draw(jakeLeftEyeTop), window.draw(jakeRightEyeTop);
        window.draw(jakeMouth);
        drawJakeSnout(jakeSnout);
        window.draw(jakeSnout);
        window.draw(jakeNose);

        // it was at this point that i realized i only needed five shape OBJECTS not five separate drawings. oh well

        //  END  DRAWING HERE
        /////////////////////////////////////


        // display the current contents of the window
        window.display();

        /////////////////////////////////////
        // BEGIN EVENT HANDLING HERE
        // check if any events happened since the last time checked
        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }
            // check addition event types to handle additional events
        }
        //  END  EVENT HANDLING HERE
        /////////////////////////////////////
    }

    return 0;
}

void drawKitty(Font& font, RectangleShape& earOne, RectangleShape& earTwo, CircleShape& headBack, CircleShape& headFront, CircleShape& eyeOne, CircleShape& eyeTwo, Text& mouth) {
    // ears
    earOne.setSize({50, 50}), earTwo.setSize({50, 50});
    earOne.setPosition({95, 105}), earTwo.setPosition({175, 105});
    earOne.setFillColor(Color(0, 0, 0, 255)), earTwo.setFillColor(Color(0, 0, 0, 255));

    // head
    headBack.setRadius(70), headFront.setRadius(65);
    headBack.setFillColor(Color(0, 0, 0, 255)), headFront.setFillColor(Color(255, 255, 255, 255));
    headBack.setPosition({90, 100}), headFront.setPosition({95, 105});

    // eyes
    eyeOne.setRadius(5), eyeTwo.setRadius(5);
    eyeOne.setFillColor(Color(0, 0, 0, 255)), eyeTwo.setFillColor(Color(0, 0, 0, 255));
    eyeOne.setPosition({130, 150}), eyeTwo.setPosition({180, 150});

    // mouth ( 3 )
    mouth.setFont(font);
    mouth.setString("3");
    mouth.setCharacterSize(50);
    mouth.setPosition({190, 170});
    mouth.setRotation(90);
    mouth.setFillColor(Color(0, 0, 0, 255));
}

void drawJake(CircleShape& jakeLeftEyeBack, CircleShape& jakeRightEyeBack, CircleShape& jakeLeftEyeTop, CircleShape& jakeRightEyeTop, CircleShape& jakeNose, ConvexShape& jakeMouth) {
    // back layer of eyes
    jakeLeftEyeBack.setFillColor(Color(0, 0, 0, 255)), jakeRightEyeBack.setFillColor(Color(0, 0, 0, 255));
    jakeLeftEyeBack.setRadius(30), jakeRightEyeBack.setRadius(30);
    jakeLeftEyeBack.setPosition({230, 270}), jakeRightEyeBack.setPosition({310, 270});

    // top layer of eyes (whites)
    jakeLeftEyeTop.setFillColor(Color(255, 255, 255, 255)), jakeRightEyeTop.setFillColor(Color(255, 255, 255, 255));
    jakeLeftEyeTop.setRadius(25), jakeRightEyeTop.setRadius(25);
    jakeLeftEyeTop.setPosition({238, 275}), jakeRightEyeTop.setPosition({318, 275});

    // smile
    jakeMouth.setPointCount(5);
    jakeMouth.setScale({2, 2});
    jakeMouth.setOutlineThickness(2);
    jakeMouth.setOutlineColor(Color(0, 0, 0, 255));
    jakeMouth.setPoint(0, {-10, 0}), jakeMouth.setPoint(1, {-5, 2}), jakeMouth.setPoint(2, {0, 4}), jakeMouth.setPoint(3, {5, 2}), jakeMouth.setPoint(4, {10, 0});
    jakeMouth.setPosition({299, 335});

    // nose
    jakeNose.setFillColor(Color(0, 0, 0, 255));
    jakeNose.setPosition({277, 315});
    jakeNose.setRadius(12);
    jakeNose.scale({2, 1});
}

void drawJakeSnout(ConvexShape& jakeSnout) {
    // jake's snout thing
    jakeSnout.setPointCount(15);
    jakeSnout.setScale({2, 2});
    jakeSnout.setOutlineThickness(3);
    jakeSnout.setOutlineColor(Color(0, 0, 0, 255));
    jakeSnout.setPoint(0, {0, 0}); 

    // right half of snout
    jakeSnout.setPoint(1, {8, 5}), jakeSnout.setPoint(2, {18, 15}), jakeSnout.setPoint(3, {19, 25}), jakeSnout.setPoint(4, {15, 30}),
    jakeSnout.setPoint(5, {12, 22}), jakeSnout.setPoint(6, {10, 20}), jakeSnout.setPoint(7, {8, 15});

    // left half of snout
    jakeSnout.setPoint(8, {-8, 15}), jakeSnout.setPoint(9, {-10, 20}), jakeSnout.setPoint(10, {-12, 22}), jakeSnout.setPoint(11, {-15, 30}),
    jakeSnout.setPoint(12, {-19, 25}), jakeSnout.setPoint(13, {-18, 15}), jakeSnout.setPoint(14, {-8, 5});

    jakeSnout.setPosition({300, 300});
}