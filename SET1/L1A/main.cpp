/* CSCI 200: Lab 1A: Math Equation Solver
 *
 * Author: Thomas McInnes
 *
 * This project computes the Ideal Gas Law and Ohm's Law.
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.
const double IDEAL_GAS = 0.08206;

// Must have a function named "main", which is the starting point of a C++ program.
int main() {

  /******** INSERT YOUR CODE BELOW HERE ********/

  float moles;
  cout << "First we will calculate pressure using the Ideal Gas Law.\nEnter the amount of moles of substance: ";
  cin >> moles;

  float temperature;
  cout << "Enter the temperature (in Kelvin!): ";
  cin >> temperature;

  float volume;
  cout << "Enter the volume (in Liters!): ";
  cin >> volume;

  float pressure = (moles * IDEAL_GAS * temperature) / volume;
  cout << "The pressure is " << pressure << " atm." << endl;

  float voltage;
  cout << "Now we will calculate current using Ohm's Law.\nEnter the voltage (in Volts!): ";
  cin >> voltage;

  float resistance;
  cout << "Enter the resistance (in Ohms!): ";
  cin >> resistance;

  float current = voltage / resistance;
  cout << "The current is " << current << " amp(s)." << endl;

  /******** INSERT YOUR CODE ABOVE HERE ********/

  return 0; // signals the operating system that our program ended OK.
}