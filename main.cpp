#include <iostream>
#include <algorithm>
#include "model.h"
#include "DSString.h"
#include "DSVector.h"

using namespace std;

int main(int argc, char** argv){
   for (int i = 0; i < argc; i++) {cout << argv[i] << endl;
  }

   // cout << "Test\n" << endl;

    model m(argv);
    m.Train();
    m.Test();
    m.Check();

//    DSString myString = "Hello, World!";
//    cout << myString << endl;
//
//    // this uses the one argument constructor in DSString and then the inherited operator=
//    myString = "Good bye!";
//    cout << myString << endl;
//
//    cout << "substr: " << myString.substring(5, 3) << endl;
//
//    DSString a = "test";
//    DSString b = a;
//
//    cout << boolalpha;
//    cout << (a == b) << endl;
//
//    // use initialization list (see DSVector.h)
//    DSVector<DSString> strings = {
//        DSString("bbb"),
//        DSString("aaa"),
//        DSString("ddd"),
//        DSString("eee"),
//        DSString("ccc")};
//
//    // find strings
//    for (const auto &s : strings)
//        cout
//            << s << "\n";
//
//
//    // sorting
//    sort(strings.begin(), strings.end());
//
//    for (const auto &s : strings)
//        cout
//            << s << "\n";
//
//    // now we can do more efficient search
//    cout << "found ddd: " << binary_search(strings.begin(), strings.end(), DSString("ddd")) << endl;
//    cout << "found zzz: " << binary_search(strings.begin(), strings.end(), DSString("zzz")) << endl;


    return 0;
};

//    DSString myString = "Hello, World!";
//    cout << myString << endl;
//
//    // this uses the one argument constructor in DSString and then the inherited operator=
//    myString = "Good bye!";
//    cout << myString << endl;
//
//    cout << "substr: " << myString.substring(5, 3) << endl;
//
//    DSString a = "test";
//    DSString b = a;
//
//    cout << boolalpha;
//    cout << (a == b) << endl;
//
//    // use initialization list (see DSVector.h)
//    DSVector<DSString> strings = {
//        DSString("bbb"),
//        DSString("aaa"),
//        DSString("ddd"),
//        DSString("eee"),
//        DSString("ccc")};
//
//    // find strings
//    for (const auto &s : strings)
//        cout
//            << s << "\n";
//
//
//    // sorting
//    sort(strings.begin(), strings.end());
//
//    for (const auto &s : strings)
//        cout
//            << s << "\n";
//
//    // now we can do more efficient search
//    cout << "found ddd: " << binary_search(strings.begin(), strings.end(), DSString("ddd")) << endl;
//    cout << "found zzz: " << binary_search(strings.begin(), strings.end(), DSString("zzz")) << endl;