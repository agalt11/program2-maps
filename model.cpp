//
// Created by Annalise G on 8/29/22.
//

#include "model.h"
#include "Training.h"
#include "Testing.h"
#include "Checking.h"


model::model(char ** a) {
    arg = a;
}

/*
 * training:
 * read input file, while do that store neccsary info from input file
 * nesccary info is text and sentiment (pos/neg tweet)
 * split text into words (lower case)
 * count how many times each time word appears in pos/neg tweet
 * store result in their sentiments
 *
 * testing:
 * read input file
 * store info which is text and ID no sentiment
 * split text into word *
 * count how many pos words and neg words in each tweet
 * guess if tweet is pos/neg
 * store guesses with id numbers
 *
 * check:
 * read in last input file
 * store everything
 * iterate through id and compare actual sentiment to guess sentiement
 * save tweets you get wrong
 * create output files
 */
void model::Train() {
    Training train(arg[1]);
    trainResult = train.getSentiment();
//    for (const auto& curr : trainResult) {
//        cout << curr.first << " " << curr.second << endl;
//    }
}

void model::Test() {
    Testing test(arg[2], trainResult);
    testResult = test.getSentiment();
}

void model::Check() {
     Checking check(arg[3], arg[4], arg[5], testResult);
}
