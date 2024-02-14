/* CSCI 200: Lab 1B: Random Classification
 *
 * Author: Thomas McInnes
 *
 * Random number generator where the user picks the range and can generate as many
 * values as needed.
 */


#include <iostream> // For cin, cout, etc.
#include <cstdlib> // For random numbers
#include <ctime> // To use time for random seeds

using namespace std;

int main() {

    srand(time(0));     // seeds RNG
    rand();      // throws away first value since it's usually "predictable"

    float min;
    cout << "Enter a minimum value: ";
    cin >> min;

    float max;
    cout << "Enter a maximum value: ";
    cin >> max;

    char checkContinue = 'Y';
    while( checkContinue == 'Y' ) {  // loops until user enters "N"

        float randomValue = rand() / (float)RAND_MAX * (max - min) + min; // gets a random float in the range specified
        cout << "A random value is: " << randomValue << endl;

        string quartile;
        float quartileRange = (max - min) / 4;      // these if and else ifs check for quartiles
        if( (quartileRange + min) > randomValue ) {
            quartile = "first";         // quartile is output to a string to cut down on lines of code
        } else if( ((2 * quartileRange) + min) > randomValue ) {
            quartile = "second";
        } else if( ((3 * quartileRange) + min) > randomValue ) {
            quartile = "third";
        } else {
            quartile = "fourth";
        }

        cout << "This is in the " << quartile << " quartile\nWould you like to continue outputting values? (Y/N) ";
        cin >> checkContinue;

    }

    cout << "Have a nice day!" << endl;

  return 0;
}