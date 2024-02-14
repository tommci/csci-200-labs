/* CSCI 200: Assignment A3: Green Eggs and Ham Classes
 *
 * Author: Thomas McInnes
 * Resources used: N/A
 * 
 *
 * Parses files and gets word/letter data about them
 */
#ifndef STRING_FILTER_H
#define STRING_FILTER_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

/**
 * @brief String Filter class that creates a list of all unique words and adds up all words
 * 
 */
class StringFilter {
public:

// methods
/**
 * @brief Initializes private data members to sensible values
 * 
 */
StringFilter();

/**
 * @brief Get the Unique Words object
 * 
 * @return std::vector<std::string> Vector of strings containing all the unique words
 */
std::vector<std::string> getUniqueWords();

/**
 * @brief Computes the unique set of words present in the input vector
 * 
 * @param allWords Vector of strings containing all the words
 */
void addWords( const std::vector<std::string> allWords );

/**
 * @brief For each word, prints out the word and its corresponding count
 * 
 * @param outStream Reference to the output stream
 */
void printUniqueWordCounts( std::ostream& outStream );

/**
 * @brief Prints out the two words that occur least often and most often, and their percentage of occurances
 * 
 * @param outStream Reference to the output stream
 */
void printUniqueWordStats( std::ostream& outStream );

/**
 * @brief Counts the number of digits of a given number
 * 
 * @param value Number to have digits counted. Type is size_t to account for .length() from a string
 * @return int Number of digits from input 
 */
int countDigits( const size_t value );


private:

// attributes
std::vector<std::string> _uniqueWords;      // list of all unique words
std::vector<unsigned int> _wordCounts;      // list of all word counts (per word)
unsigned int _totalWordCount;               // the total number of words overall

};

#endif