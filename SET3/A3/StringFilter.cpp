/* CSCI 200: Assignment A3: Green Eggs and Ham Classes
 *
 * Author: Thomas McInnes
 * Resources used: N/A
 * 
 *
 * Parses files and gets word/letter data about them
 */
#include "StringFilter.h"

using namespace std;

StringFilter::StringFilter() {
    _uniqueWords = {};
    _wordCounts = {};
    _totalWordCount = 0;
}

void StringFilter::addWords( const vector<string> allWords ) {
    int shouldAddWord = 0;
    for( size_t i = 0; i < allWords.size(); i++) {
        shouldAddWord = 1;
        _totalWordCount += 1;                              // counts every individual word, not every unique word
        for( size_t j = 0; j < _uniqueWords.size(); j++) { // this for loop checks current word in allWords against all words in uniqueWords
            if( allWords.at(i) == _uniqueWords.at(j) ) {   // if the word from allWords is already
                shouldAddWord = 0;                         // in uniqueWords, then it is not a unique word. iterates corresponding
                _wordCounts.at(j) += 1;                    // wordcount in wordCounts, then breaks INNER for loop, skipping to next word in allWords
                break;                                     // this should work since _wordCounts[j] should already have a val at j if the if statement returns true
            }
        }
        if( shouldAddWord == 1 ) {                     // if shouldAddWord = 0, word is already in uniqueWords    
            _uniqueWords.push_back(allWords.at(i));    // if it's = 1, it isn't in uniqueWords and is
            _wordCounts.push_back(1);                  // therefore unique, so it gets added to uniqueWords, and a value of 1 is inserted
        }                                              // into wordCounts, starting counting for that word at the same position of its word in uniqueWords
    }   
}

void StringFilter::printUniqueWordCounts( ostream& outStream ) {
    size_t longestWord = _uniqueWords.at(0).length();      // checks for the longest
    size_t largestAmount = _wordCounts.at(0);
    for( size_t i = 0; i < _uniqueWords.size(); i++ ) {    // word for formatting later
        if( _uniqueWords.at(i).length() > longestWord ) {  // output
            longestWord = _uniqueWords.at(i).length();
        }
        if( _wordCounts.at(i) > largestAmount ) {
            largestAmount = _wordCounts.at(i);      // this is for formatting the numbers
        }
    }
    for( size_t i = 0; i < _uniqueWords.size(); i++ ) {
        outStream << setw(longestWord + 1) << left << _uniqueWords.at(i) << ":" << setw(countDigits(largestAmount) + 1) << right << _wordCounts.at(i) << endl;
    }
}

void StringFilter::printUniqueWordStats( ostream& outStream ) {
    vector<unsigned int> mostFreq = {0, 0};
    mostFreq.at(0) = _wordCounts.at(0);   // index 0 = count, index 1 = location of count
    vector<unsigned int> leastFreq = {0, 0};
    leastFreq.at(0) = _wordCounts.at(0);  // index 0 = count, index 1 = location of count
    for( size_t i = 0; i < _wordCounts.size(); i++ ) {
        if( _wordCounts.at(i) > mostFreq.at(0) ) {
            mostFreq.at(0) = _wordCounts.at(i); // sets mostFreq values
            mostFreq.at(1) = i;
        } else if( _wordCounts.at(i) < leastFreq.at(0) ) {
            leastFreq.at(0) = _wordCounts.at(i);    // sets leastFreq values
            leastFreq.at(1) = i;
        }
    }
    int longestOfFrequency;
    double mostFreqPercent = ((double)mostFreq.at(0) / _totalWordCount) * 100;
    double leastFreqPercent = ((double)leastFreq.at(0) / _totalWordCount) * 100;
    if( _wordCounts.at(mostFreq.at(1)) < _wordCounts.at(leastFreq.at(1)) ) {
        longestOfFrequency = _uniqueWords.at(mostFreq.at(1)).length();
    } else {
        longestOfFrequency = _uniqueWords.at(leastFreq.at(1)).length();
    }
    outStream << " Most frequent word: " << left << setw(longestOfFrequency + 1) << _uniqueWords.at(mostFreq.at(1)) << right << setw(countDigits(leastFreq.at(0))) << mostFreq.at(0) << " (" << fixed << right << setprecision(3) << setw(7) << mostFreqPercent << "%)" << endl;
    outStream << "Least frequent word: " << left << setw(longestOfFrequency + 1) << _uniqueWords.at(leastFreq.at(1)) << right << setw(countDigits(mostFreq.at(0))) << leastFreq.at(0) << " (" << right << setw(7) << leastFreqPercent << "%)" << endl;
}

vector<string> StringFilter::getUniqueWords() {
    return _uniqueWords;
}

int StringFilter::countDigits( const size_t value ) {
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