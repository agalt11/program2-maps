//
// Created by Annalise G on 8/29/22.
//

#ifndef ASSIGNMENT2_SENTIMENT_TRAINING_H
#define ASSIGNMENT2_SENTIMENT_TRAINING_H

#include "DSString.h"
#include <fstream>
#include <map>
using namespace std;

/*
 * training:
 * read input file, while do that store neccsary info from input file
 * nesccary info is text and sentiment (pos/neg tweet)
 * split text into words (lower case)
 * count how many times each time word appears in pos/neg tweet
 * store result in their sentiments
 */

class Training {
public:
    Training(char*);
    void readInput();
    void split(DSString, bool);
    void getWord(int&, int, DSString, bool);
    map<DSString, int>& getSentiment();
private:
    char* fileName;
    map<DSString, int> results;

};


#endif //ASSIGNMENT2_SENTIMENT_TRAINING_H
