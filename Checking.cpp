//
// Created by Annalise G on 9/1/22.
//


#include "Checking.h"
#include <iomanip>

Checking::Checking(char *i, char* o1, char* o2, map<DSString, bool>& g) {
    inputFile=i;
    outputFile1= o1;
    outputFile2= o2;
    guess=g;
    readInput();
    outputOne();
}

void Checking::readInput() {
    ifstream input;
    input.open(inputFile);
    if (!input.is_open()) {
        cout << inputFile << " failed to open" << endl;
        exit(1);
    }
    char* buffer = new char[5000];
    input.getline(buffer, 5000);
    while(!input.eof()) {
        input.getline(buffer, 5000, ',');
        if (strlen(buffer) == 0) {
            break;
        }
        bool sentiment = (buffer[0] == '4');
        input.getline(buffer, 5000);
        DSString id= buffer;
        cout << id << "," << sentiment << endl;
        check[id] = sentiment;
    }
    delete[] buffer;
    input.close();
    checkAccuracy();
}

void Checking::outputOne() {
    ofstream output;
    output.open(outputFile1);
    if (!output.is_open()) {
        cout << outputFile1 << " failed to open" << endl;
        exit(1);
    }
    output << "sentiment,id" << endl;
    for (const auto& it : check) {
        if (it.second){
            output << "4,";
        } else {
            output << "0,";
        }
        output << it.first;
        output << endl;
    }
    output.close();
}


void Checking::outputTwo(double accuracy) {
    ofstream output;
    output.open(outputFile2);
    if (!output.is_open()) {
        cout << outputFile2 << " failed to open" << endl;
        exit(1);
    }
    output << setprecision(3) << accuracy << endl;
    for (int i=0; i< wrongID.size(); i++){
        bool correctSentiment= check[wrongID[i]];
        if (correctSentiment){
            output << "0,4," << wrongID[i] << endl;
        } else {
            output << "4,0," << wrongID[i] << endl;
        }
    }
    output.close();
}

void Checking::checkAccuracy() {
    for (const auto& it : check) {
        if (it.second != guess[it.first]){
            wrongID.push_back(it.first);
        }
    }
    double accuracy= (double)(guess.size()-wrongID.size()) / guess.size();
    outputTwo(accuracy);
}
