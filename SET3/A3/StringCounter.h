/* CSCI 200: Assignment A3: Green Eggs and Ham Classes
 *
 * Author: Thomas McInnes
 * Resources used: N/A
 * 
 *
 * Parses files and gets word/letter data about them
 */
#ifndef STRING_COUNTER_H
#define STRING_COUNTER_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

/**
 * @brief String Counter class that creates a list of all words and adds up all letters
 * 
 */
class StringCounter {
public:

// methods
/**
 * @brief Initializes private data members to sensible values
 * 
 */
StringCounter();

/**
 * @brief Get the All Words object
 * 
 * @return std::vector<std::string> Vector of strings containing all the words
 */
std::vector<std::string> getAllWords();

/**
 * @brief Read all the words that are in the input stream and store in the private vector of all words
 * 
 * @param inStream Reference to the input stream 
 * @param REMOVE_CHARS string of characters to remove from any read words
 */
void readAllWords( std::istream& inStream, const std::string REMOVE_CHARS );

/**
 * @brief For each letter, prints out the letter and its corresponding count to the provided output stream
 * 
 * @param outStream Reference to the output stream
 */
void printLetterCounts( std::ostream& outStream );

/**
 * @brief Prints out the two letters that occur least often and most often to the provided output stream, as well as their percentage of occurances
 * 
 * @param outStream Reference to the output stream
 */
void printLetterStats( std::ostream& outStream );

/**
 * @brief Counts the number of digits of a given number
 * 
 * @param value Number to have digits counted. Type is size_t to account for .length() from a string
 * @return int Number of digits from input 
 */
int countDigits( const size_t value );


private:

// attributes
std::vector<std::string> _allWords;         // list of all words
std::vector<unsigned int> _letterCounts;    // list of letter counts
unsigned int _totalLetterCount;             // the total number of letters read

};

#endif