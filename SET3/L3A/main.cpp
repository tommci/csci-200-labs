/* CSCI 200: Lab 3A: The Secret Moosage
 *
 * Author: Thomas McInnes
 *
 * This program opens a file and deciphers a secret message, outputting it to a new file
 */
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream secretMessage; // input stream file object
    ofstream decipheredMessage; // output stream file object

    secretMessage.open("secretMessage.txt"); // opens file to read to
    decipheredMessage.open("decipheredMessage.txt"); // opens file to write to

    if( secretMessage.fail() ) {
        cerr << "Error opening input file" << endl;
        return -1;  // if fails to open file
    }

    if( decipheredMessage.fail() ) {
        cerr << "Error opening output file" << endl;
        return -2;  // if fails to write to file
    }
    
    char character;
    while( !secretMessage.eof() ) {
        secretMessage.get(character);   // gets current character
        if( character == '\n' ) {   // checks for newlines
            decipheredMessage << endl;
        } else if( character == '~' ) { // checks for ~
            decipheredMessage << ' ';
        } else {    // checks for everything else
            decipheredMessage << (char)(character + 1);
        }
    }

    secretMessage.close(); // closes input file
    decipheredMessage.close(); // closes output file

    return 0;
}
