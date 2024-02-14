/* CSCI 200: Assignment A3: Green Eggs and Ham Classes
 *
 * Author: Thomas McInnes
 * Resources used: N/A
 * 
 *
 * Parses files and gets word/letter data about them
 */
#include "StringCounter.h"

using namespace std;

// ALPHABET = {65, 66, 67, ... 90}
// alphabet = {97, 98, 99, ... 122}

StringCounter::StringCounter() {
    _allWords = {};
    _letterCounts = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    _totalLetterCount = 0;
}

void StringCounter::readAllWords( istream& inStream, const string REMOVE_CHARS ) {
    string inputString = "";     // istream input turned into a string
    string tempWord = "";        // string that builds each word to be put into allWords
    char character = '\0';
    char lastCharacter = '\0';
    while( !inStream.eof() ){
        inStream.get(character);          // reads in input, puts it into inputString
        if( inStream.fail() ) { break; }  // checks if getting from inStream failed, this always happens at the end of the file
        if ( REMOVE_CHARS.find_first_of(character) == std::string::npos ) { // checks if character is punctuation, removes it here
            inputString += character;
        }
    }
    inputString += '\n'; // adds a newline to the end of inputString, so any words at the end of the file still get added
    for( size_t i = 0; i < inputString.length(); i++) {     // until end of file reached,
        character = inputString.at(i);                      // reuses character from before 
        if( (character == '\n' || character == ' ') && (lastCharacter != '\n' && lastCharacter != ' ') ) {
            _allWords.push_back(tempWord);
            tempWord = "";
        }
        if( character != ' ' && character != '\n' ) { // checks if character is not whitespace in order to add letters
            for( int j = 97; j <= 122; j++ ) { // lowercase alphabet is a = 97 through z = 122
                if( (char)j == character ) {
                    tempWord += (char)(character - 32); // converts to uppercase
                    _letterCounts.at(j - 97)++; // adds one to position of letter in lettercounts
                    _totalLetterCount++;
                    break;
                } else if( (char)(j - 32) == character ) { // checks uppercase alphabet (32 less than lower)
                    tempWord += character;
                    _letterCounts.at(j - 97)++;
                    _totalLetterCount++;
                    break;
                }
            }  
        }
        lastCharacter = character; // sets last character to current character at end of loop, this checks for double spaces/newlines
    }
}

void StringCounter::printLetterCounts( ostream& outStream ) {
    size_t largestVal = _letterCounts.at(0);
    for( size_t i = 0; i < _letterCounts.size(); i++ ) {  // checks for largest value
        if( _letterCounts.at(i) > largestVal ) {          // to set output formatting
            largestVal = _letterCounts.at(i);
        }
    }
    for( size_t i = 0; i < _letterCounts.size(); i++ ) {  // iterates through all of letterCounts
        outStream << (char)(i + 65) << ":" << setw(countDigits(largestVal) + 1) << right << _letterCounts.at(i) << endl;  // outputs letter first, value second
    }               // (char)(i + 65) is the uppercase letter
}

void StringCounter::printLetterStats( ostream& outStream ) {
    vector<unsigned int> mostFreq = {0, 0};
    mostFreq.at(0) = _letterCounts.at(0);   // index 0 = count, index 1 = location of count
    vector<unsigned int> leastFreq = {0, 0};
    leastFreq.at(0) = _letterCounts.at(0);  // index 0 = count, index 1 = location of count
    for( size_t i = 0; i < _letterCounts.size(); i++ ) {
        if( _letterCounts.at(i) > mostFreq.at(0) ) {
            mostFreq.at(0) = _letterCounts.at(i);
            mostFreq.at(1) = i;
        } else if( _letterCounts.at(i) < leastFreq.at(0) ) {
            leastFreq.at(0) = _letterCounts.at(i);
            leastFreq.at(1) = i;
        }
    }
    double mostFreqPercent = ((double)mostFreq.at(0) / _totalLetterCount) * 100;
    double leastFreqPercent = ((double)leastFreq.at(0) / _totalLetterCount) * 100;
    outStream << " Most frequent letter: " << (char)(mostFreq.at(1) + 65) << right << setw(countDigits(mostFreq.at(0)) + 1) << right << mostFreq.at(0) << " (" << fixed << setprecision(3) << setw(7) << mostFreqPercent << "%)" << endl;
    outStream << "Least frequent letter: " << (char)(leastFreq.at(1) + 65) << right << setw(countDigits(mostFreq.at(0)) + 1) << leastFreq.at(0) << " (" << setw(7) << leastFreqPercent << "%)" << endl;
}

vector<string> StringCounter::getAllWords() {
    return _allWords;
}

int StringCounter::countDigits( const size_t value ) {
    if( value == 0 ) {   // in case the % is less than one but greater than 0
        return 1;       
    }
    int count = 0;
    int testValue = value;
    while ( testValue > 0 ) {
        testValue = testValue / 10;
        count++;
    }
    return count;
}