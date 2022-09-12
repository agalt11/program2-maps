//
// Created by Annalise G on 8/29/22.
//

#include "Training.h"

Training::Training(char* f) {
    fileName=f;
    readInput();
}

void Training::readInput() {
    ifstream input;
    input.open(fileName);
    if (!input.is_open()) {
        cout << fileName << " failed to open" << endl;
        exit(1);
    }
    char* buffer = new char[5000];
    input.getline(buffer, 5000);
    while(!input.eof()) {
        input.getline(buffer, 5000, ',');
        bool sentiment = (buffer[0] == '4');
        for (int i = 0; i < 4; i++) {
            input.getline(buffer, 5000, ',');
        }
        input.getline(buffer, 5000);
        DSString text= DSString(buffer);
        split(text, sentiment);
    }
    delete[] buffer;
    input.close();
}

void Training::split(DSString text, bool sentiment) {
    int counter=0;
    for (int i=0; i< text.length();i++){
        if(!isalpha(text[i])) {
            getWord(counter, i, text, sentiment);
        }
    }
    getWord(counter, text.length(), text, sentiment);
}

void Training::getWord(int& counter, int i, DSString text, bool sentiment) {
    if (i > counter){
        DSString word;
        word= text.substring(counter, i - counter);
        word.toLower();
        if (results.find(word) != results.end()) {
            if (sentiment){
                results[word]++;
            } else {
                results[word]--;
            }
        } else {
            if (sentiment){
                results[word] = 1;
            } else {
                results[word] = -1;
            }
        }
        counter = i + 1;
    } else {
        counter++;
    }
}

map<DSString, int>& Training::getSentiment() {
    return results;
}
