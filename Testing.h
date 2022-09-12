//
// Created by Annalise G on 8/30/22.
//

#ifndef ASSIGNMENT2_SENTIMENT_TESTING_H
#define ASSIGNMENT2_SENTIMENT_TESTING_H
#include "DSString.h"
#include <fstream>
#include <map>
using namespace std;

        /*read input file
        * store info which is text and ID no sentiment
        * split text into word *
        * count how many pos words and neg words in each tweet
        * guess if tweet is pos/neg
        * store guesses with id numbers
*/
class Testing {
public:
    Testing(char*, map<DSString, int>&);
    void readInput();
    void split(DSString, DSString&);
    int getWord(int&, int, DSString);
    map<DSString, bool>& getSentiment();

private:
    char* fileName;
    map<DSString, int> words;
    map<DSString, bool> results;



};


#endif //ASSIGNMENT2_SENTIMENT_TESTING_H
