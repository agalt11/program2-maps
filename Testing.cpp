//
// Created by Annalise G on 8/30/22.
//

#include "Testing.h"

Testing::Testing(char* f, map<DSString, int>& w) {
    fileName=f;
    words = w;
    readInput();
}

void Testing::readInput() {
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
        if (strlen(buffer) == 0) {
            break;
        }
        DSString id= buffer;
        for (int i = 0; i < 3; i++) {
            input.getline(buffer, 5000, ',');
        }
        input.getline(buffer, 5000);
        DSString text= buffer;
        split(text, id);
    }
    delete[] buffer;
    input.close();
}


void Testing::split(DSString text, DSString& id) {
    int counter=0;
    int sentiment=0;

    for (int i=0; i< text.length();i++){
        if(!isalpha(text[i])) {
            sentiment += getWord(counter, i, text);
        }
    }
    sentiment +=getWord(counter, text.length(), text);
    results[id]= (sentiment > 0);
}

int Testing::getWord(int& counter, int i, DSString text) {
    if (i > counter){
        DSString word;
        word= text.substring(counter, i - counter);
        word.toLower();
        if (words.find(word) != words.end()) {
            if (words[word] > 0){
                return 1;
            }else if (words[word] < 0) {
                return -1;
            }
        }
        counter = i + 1;
    } else {
        counter++;
    }
    return 0;
}

map<DSString, bool> &Testing::getSentiment() {
    return results;
}
