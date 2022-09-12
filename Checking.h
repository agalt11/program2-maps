//
// Created by Annalise G on 9/1/22.
//

#ifndef ASSIGNMENT2_SENTIMENT_CHECKING_H
#define ASSIGNMENT2_SENTIMENT_CHECKING_H
#include "DSString.h"
#include "DSVector.h"
#include <fstream>
#include <map>
using namespace std;


        /* check:
        * read in last input file
        * store everything
        * iterate through id and compare actual sentiment to guess sentiment
        * save tweets you get wrong
        * create output files
        */

class Checking {
    public:
        Checking(char*, char*, char*, map<DSString, bool>&);
        void readInput();
        void outputOne();
        void outputTwo(double accuracy);
        void checkAccuracy();
private:
    char* inputFile;
    char* outputFile1;
    char* outputFile2;
    map<DSString, bool> check;
    map<DSString, bool> guess;
    DSVector<DSString> wrongID;

};


#endif //ASSIGNMENT2_SENTIMENT_CHECKING_H
