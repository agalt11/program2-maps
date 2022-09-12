//
// Created by Annalise G on 8/29/22.
//

#ifndef ASSIGNMENT2_SENTIMENT_MODEL_H
#define ASSIGNMENT2_SENTIMENT_MODEL_H

#include "DSString.h"
#include <map>
using namespace std;

class model {
private:
    char** arg;
    map<DSString, int> trainResult;
    map<DSString, bool> testResult;
public:
    model(char**);
    void Train();
    void Test();
    void Check();

};


#endif //ASSIGNMENT2_SENTIMENT_MODEL_H
