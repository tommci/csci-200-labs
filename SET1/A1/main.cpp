/* CSCI 200: Assignment 1: A1 - Rock Paper Scissor Throw Down!
 *
 * Author: Thomas McInnes
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 * Lecture slides for RNG calculation
 *     
 *
 * Rock paper scissors versus RNG. Tracks wins and losses, and 
 */
// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <cstdlib>  // rand()
#include <ctime>    // time()

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.

// Must have a function named "main", which is the starting point of a C++ program.
int main() {

  /******** INSERT YOUR CODE BELOW HERE ********/

    srand(time(0)); // seeds the rng
    rand();         // throw away first rng value

    string playerMove;  // initializing variables BEFORE while loop so they're not getting re-initialized
    int computerMove;
    int playerWins = 0;
    int playerLosses = 0;
    int ties = 0;

    string playAgain = "Y";
    while( (playAgain == "Y") || (playAgain == "y") ) {

        cout << "Welcome to Rock, Paper, Scissors. Make your choice (Enter P, R, or S)\nPlayer: ";
        cin >> playerMove;

        if( (playerMove == "p") || (playerMove == "P") ) {
            cout << "Player chose Paper" << endl;
            playerMove = "p";   // i reset playerMove just for conciseness later
        } else if( (playerMove == "r") || (playerMove == "R") ) {
            cout << "Player chose Rock" << endl;
            playerMove = "r";
        } else if( (playerMove == "s") || (playerMove == "S") ) {
            cout << "Player chose Scissors" << endl;
            playerMove = "s";
        }

        computerMove = rand() % 3;  // initializes and sets computerMove to a number, 0 to 2
        if( computerMove == 0 ) {
            cout << "Computer chose Rock" << endl;
        } else if( computerMove == 1 ) {
            cout << "Computer chose Paper" << endl;
        } else if( computerMove == 2) {
            cout << "Computer chose Scissors" << endl;
        }

        if( playerMove == "p") {    // when player chooses paper
            if ( computerMove == 0 ) {
                cout << "Paper beats Rock. Player wins!" << endl;
                ++playerWins;
            }
            if ( computerMove == 1 ) {
                cout << "Paper ties with Paper. It's a tie!" << endl;
                ++ties;
            }
            if ( computerMove == 2 ) {
                cout << "Scissors beats Paper. Computer wins!" << endl;
                ++playerLosses;
            }                       
        }

        if( playerMove == "r") {    // when player chooses rock
            if ( computerMove == 0 ) {
                cout << "Rock ties with Rock. It's a tie!" << endl;
                ++ties;
            }
            if ( computerMove == 1 ) {
                cout << "Paper beats Rock. Computer wins!" << endl;
                ++playerLosses;
            }
            if ( computerMove == 2 ) {
                cout << "Rock beats Scissors. Player wins!" << endl;
                ++playerWins;
            }    
        }

        if( playerMove == "s") {    // when player chooses scissors
            if ( computerMove == 0 ) {
                cout << "Rock beats Scissors. Computer wins!" << endl;
                ++playerLosses;
            }
            if ( computerMove == 1 ) {
                cout << "Scissors beats Paper. Player wins!" << endl;
                ++playerWins;
            }
            if ( computerMove == 2 ) {
                cout << "Scissors ties with Scissors. It's a tie!" << endl;
                ++ties;
            }                       
        }


        cout << "Would you like to play again? (Y/N): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing!\n"  // newline in code for readability
    "You won " << playerWins << " game(s), lost " << playerLosses << " game(s), and tied " << ties << " game(s).";

  /******** INSERT YOUR CODE ABOVE HERE ********/

  return 0; // signals the operating system that our program ended OK.
}