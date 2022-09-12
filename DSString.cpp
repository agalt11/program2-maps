#include "DSString.h"

DSString::DSString() {
    data = new char[1];
    data[0] = '\0';
}

DSString::DSString(const char *d) {
    if (d == nullptr) {
        data = new char[1];
        data[0] = '\0';
    } else {
        data= new char[strlen(d) + 1];
        strcpy(data, d);
        data[strlen(d)] = '\0';
    }
}
//copy constructor
DSString::DSString(const DSString &d) {
    if (d == nullptr) {
        data = new char[1];
        data[0] = '\0';
    } else {
        data= new char[strlen(d.data) + 1];
        strcpy(data, d.data);
        data[strlen(d.data)] = '\0';
    }
}

DSString::~DSString() {
    delete[] data;
}

DSString &DSString::operator=(const DSString &d) {
    delete[] data;
    data= new char[strlen(d.data) + 1];
    strcpy(data, d.data);
    data[strlen(d.data)] = '\0';
    return *this;
}

DSString DSString::operator+(const DSString &rhs) const {
    char* temp = new char[strlen(data) + strlen(rhs.data) + 1];
    strcpy(temp, data);
    strcat(temp, rhs.data);
    temp[strlen(data) + strlen(rhs.data)] = '\0';
    DSString str = temp;
    return str;
}

bool DSString::operator==(const DSString &rhs) const {
    return strcmp(data, rhs.data) == 0;
}

bool DSString::operator<(const DSString &rhs) const {
    return strcmp(data, rhs.data) < 0;
}

DSString DSString::substring(size_t start, size_t numChars) const {
    if (start + numChars > strlen(data)) {
        std::cout << "out of bounds" << std::endl;
        exit(1);
    }
    char* temp = new char[numChars + 1];
    strncpy(temp, data + start, numChars);
    DSString str = temp;
    return str;
}

const char *DSString::c_str() const {
    return data;
}

int DSString::length() {
    return strlen(data);
}

std::ostream &operator<<(std::ostream &out, const DSString &str) {
    out << str.data;
    return out;
}

void DSString::toLower() {
    for (int i = 0; i < strlen(data); i++) {
        data[i] = tolower(data[i]);
    }
}

char DSString::operator[](const int i) {
    return data[i];
}

