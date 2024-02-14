/* CSCI 200: Lab 3B: Strings Test Suite
 *
 * Author: Thomas McInnes
 *
 * This program runs multiple operations on strings using various functiions
 */
#include "string_functions.h"

#include <iostream>

unsigned long string_length(const string STR)  {
    unsigned long result = -1;
    result = STR.length();  // set result to the length of the string
    return result;
}

char string_char_at(const string STR, const int IDX) {
    char result = '\0';
    std::cout << "TODO: implement string_char_at(\"" << STR << "\", " << IDX << ")" << std::endl;
    // my changes start here:
    result = STR.at(IDX);
    return result;
}

string string_append(const string LEFT, const string RIGHT)  {
    string result = LEFT;
    std::cout << "TODO: implement string_append(\"" << LEFT << "\", \"" << RIGHT << "\")" << std::endl;
    // my changes start here:
    result = LEFT + RIGHT;
    return result;
}

string string_insert(const string STR, const string TO_INSERT, const int IDX) {
    string result = STR;
    std::cout << "TODO: implement string_insert(\"" << STR << "\", \"" << TO_INSERT << "\", " << IDX << ")" << std::endl;
    // my changes start here:
    result = result.insert(IDX, TO_INSERT);
    return result;
}

size_t string_find(const string STR, const char C)  {
    size_t result = 0;
    std::cout << "TODO: implement string_find(\"" << STR << "\", '" << C << "')" << std::endl;
    // my changes start here:
    result = STR.find(C);
    return result;
}

string string_substring(const string STR, const int IDX, const int LEN) {
    string result = STR;
    std::cout << "TODO: implement string_substring(\"" << STR << "\", " << IDX << ", " << LEN << ")" << std::endl;
    // my changes start here:
    result = result.substr(IDX, LEN);
    return result;
}

string string_replace(const string STR, const string TEXT_TO_REPLACE, const string REPLACE_WITH) {
    string result = STR;
    std::cout << "TODO: implement string_replace(\"" << STR << "\", \"" << TEXT_TO_REPLACE << "\", \"" << REPLACE_WITH << ")\"" << std::endl;
    // my changes start here:
    if( result.find(TEXT_TO_REPLACE) < result.length() ) {  // checks if text being replaced is in the string to begin with
        result.replace(result.find(TEXT_TO_REPLACE), TEXT_TO_REPLACE.length(), REPLACE_WITH);  // first parameter is index, second is length, third is string itself
    }       // if text to replace is not within the string, find() returns -1 (which underflows to max long int)
            // therefore by comparing the length of the string to find() it checks if this underflow occurs
    return result;
}

string string_first_word(const string STR)  {
    string result = STR;
    std::cout << "TODO: implement string_first_word(\"" << STR << "\")" << std::endl;
    // my changes start here: 
    size_t index = result.find(' ');    // allows comparison later to work properly
                                        // finds first occurance of a space. if there is no space, returns -1 which underflows to max long int
    if( index < result.length() ) {     // same check with same reasoning as before in string_replace
        result.erase(index, result.length()); // erases all but the first word in the designated string
    }
    return result;
}

string string_remove_first_word(const string STR)  {
    string result = STR;
    std::cout << "TODO: implement string_remove_first_word(\"" << STR << ")\"" << std::endl; // cout output looks a little awkward in execution but works
    // my changes start here:
    size_t index = 0; // allows comparison later to work properly
    index = result.find(' '); 
    if( index < result.length() ) {
        result = result.substr(index + 1, result.length()); // index iterated by one since it initially stores index of first space
    } else { result = ""; } // if there are no spaces, there is either only one word or the string is empty, so returns an empty string
    return result;
}

// Note: this function uses the same code as the nth word function.
//       see that function for comments explaining how it's meant to work
string string_second_word(const string STR)  {
    string result = STR;
    std::cout << "TODO: implement string_second_word(\"" << STR << "\")" << std::endl;
    // my changes start here:
    size_t spaceLocation = 0;
    for( int i = 1; i < 2; i++) {
        spaceLocation = result.find(' ');
        if( spaceLocation < result.length() ) {
            result = result.substr(spaceLocation + 1, result.length());
        } else { result = ""; }
    }
    spaceLocation = result.find(' ');
    if( spaceLocation < result.length() ) { result.erase(spaceLocation, result.length()); }
    return result;
}

// Note: this function uses the same code as the nth word function.
//       see that function for comments explaining how it's meant to work
string string_third_word(const string STR)  {
    string result = STR;
    std::cout << "TODO: implement string_third_word(\"" << STR << "\")" << std::endl;
    // my changes start here:
    size_t spaceLocation = 0;
    for( int i = 1; i < 3; i++) {
        spaceLocation = result.find(' ');
        if( spaceLocation < result.length() ) {
            result = result.substr(spaceLocation + 1, result.length());
        } else { result = ""; }
    }
    spaceLocation = result.find(' ');
    if( spaceLocation < result.length() ) { result = result.erase(spaceLocation, result.length()); }
    return result;
    return result;
}

// Note: I completed this before the third and second word functions to reuse this code rather than write it 3 times
//       this code is a combination of string_remove_first_word and string_first_word
string string_nth_word(const string STR, const int N)  {
    string result = STR;
    std::cout << "TODO: implement string_nth_word(\"" << STR << "\", " << N << ")" << std::endl;
    // my changes start here:
    size_t spaceLocation = 0;
    for( int i = 1; i < N; i++) {           // this loop removes the first word of the string until it reaches the target word,
        spaceLocation = result.find(' ');   // then sets the result to that string
        if( spaceLocation < result.length() ) {
            result = result.substr(spaceLocation + 1, result.length());
        } else { result = ""; }     // if the string runs out of sentence, each loop sets to an empty string to avoid errors and stuff
    }
    spaceLocation = result.find(' ');   // after the target word is the first word in the new string, it removes all but the first word of the string
    if( spaceLocation < result.length() ) { result = result.erase(spaceLocation, result.length()); }
    return result;
}

vector<string> string_tokenize(const string STR, const char DELIMINATOR) {
    vector<string> result;
    std::cout << "TODO: implement string_tokenize(\"" << STR << "\", '" << DELIMINATOR << "')" << std::endl;
    // my changes start here:
    string temporary = "";  // temporary string that builds each "word" between deliminators
    for( size_t i = 0; i < STR.length(); i++ ) {
        if( STR.at(i) != DELIMINATOR ) {
            temporary += STR.at(i);            // builds the words between deliminator char by char
        } else {
            result.push_back(temporary);    // if the character being checked is the deliminator, adds what's in temporary to 
            temporary = "";                 // the vector and resets temporary
        }
    }
    result.push_back(temporary);            // need to add last word since there's no deliminator at the end
    return result;
}

string string_substitute(const string STR, const char TARGET, const char REPLACEMENT)  {
    string result = STR;
    std::cout << "TODO: implement string_substitute(\"" << STR << "\", '" << TARGET << "', '" << REPLACEMENT << "')" << std::endl;
    // my changes start here
    for( size_t i = 0; i < result.length(); i++) {  // iterates through the entire string
        if( result.at(i) == TARGET ) {
            result = result.erase(i, 1);    // erases the target character
            result = result.insert(i, 1, REPLACEMENT);  // inserts replacement character at old target character's position
        }
    }
    return result;
}

string string_to_lower(const string STR) {
    string result = STR;
    std::cout << "TODO: implement string_to_lower(\"" << STR << "\")" << std::endl;
    // my changes start here:
    for( size_t i = 0; i < result.length(); i++) {  // iterates through the entire string
        char check = result.at(i); // creates character we're checking
        if( isupper(check) != 0 ) {     // apparently these handy lil functions exist
            result = result.erase(i, 1);    // erases the target character
            result = result.insert(i, 1, tolower(check));  // inserts replacement lowercase character at old target character's position
        }    
    }
    return result;
}

string string_to_upper(const string STR) {
    string result = STR;
    std::cout << "TODO: implement string_to_upper(\"" << STR << "\")" << std::endl;
    // my changes start here:
    for( size_t i = 0; i < result.length(); i++) {  // iterates through the entire string
        char check = result.at(i); // creates character that we're checking
        if( islower(check) != 0 ) { 
            result = result.erase(i, 1);    // erases the target character
            result = result.insert(i, 1, toupper(check));  // inserts replacement uppercase character at old target character's position
        }    
    }
    return result;
}

int string_compare(const string LHS, const string RHS) {
    int result = 0;
    std::cout << "TODO: implement string_compare(\"" << LHS << "\", \"" << RHS << "\")" << std::endl;
    // my changes start here:
    if( LHS.compare(RHS) > 0 ) { result = 1; }
    else if( LHS.compare(RHS) < 0 ) { result = -1; }
    return result;
}
