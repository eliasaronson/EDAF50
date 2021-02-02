#include <iostream>
#include "date.h"
#include <string>
#include <sstream>

using std::ostream;
using std::istream;
using std::cout;
using std::string;
using std::to_string;
using std::cout;
using std::endl;


template <typename T>
string toString(const T& d) {
    std::ostringstream os;
    os << d;
    return os.str();
}

void toStringTest() {
    try {
        Date d(2013, 12, 31);
        double du = 1.234;
        std::string sd = toString(d);
        std::string st = toString(du);
    } catch (std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    Date d(2013, 12, 31);
    double du = 1.234;
    std::string sd = toString(d);
    std::string st = toString(du);

    if(sd == "2013-12-31" && st == "1.234") {
        std::cout << "toString test: Succsess" << std::endl;
    } else {
        std::cout << "toString test: Fail" << std::endl;
    }
}

template <typename T>
T string_cast(const string& a) {
    std::istringstream os(a);
    T ret;
    os >> ret;
    if(os.fail()) {
        throw std::invalid_argument("Error");
    }
    return ret;
}

void testStCast() {
    bool errCorr = false;
    try {
        int i = string_cast<int>("123");
        double d = string_cast<double>("12.34");
        Date date = string_cast<Date>("2015-01-10");
        if (i == 123 && d == 12.34 && date.getDay() == 10 && date.getMonth() == 1 && date.getYear() == 2015) {
          cout << "Coversion test: Succsess" << endl;
        }
        cout << "Testing string_cast:" << "\t";
        cout << i << "\t" << d << "\t" << date << endl;
    } catch (std::invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    try {
      int i = string_cast<int>("abc");
      int j = string_cast<int>("123abc");
      cout << "123abc gives: "<< j << endl; 
      cout << i << endl; 
    } catch (std::invalid_argument& e) {
        errCorr = true;
        cout << "Error found correctly: \t";
        cout << "Error: " << e.what() << endl;
    }
    if (!errCorr) {
      cout << "Error not found!";
    }
}
int main() {
    toStringTest();
    testStCast();
}
