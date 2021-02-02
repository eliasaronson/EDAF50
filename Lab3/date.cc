#include <iostream>
#include <ctime>  // time and localtime
#include "date.h"
#include <iomanip> // for setw and setfill

using std::ostream;
using std::istream;
using std::cout;
using std::setw;
using std::setfill;
using std::string;
using std::to_string; 

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
    time_t timer = time(0); // time in seconds since 1970-01-01
    tm* locTime = localtime(&timer); // broken-down time
    year = 1900 + locTime->tm_year;
    month = 1 + locTime->tm_mon;
    day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
}

ostream & operator << (ostream &out, const Date &c) {
    out << setw(4) << setfill('0') << c.year << "-";
    out << setw(2) << setfill('0') << c.month << "-";
    out << setw(2) << setfill('0') << c.day;

    //out << c.year << "-" << c.month << "-" << c.day << std::endl;
    return out;
}

istream & operator >> (istream &in,  Date &c) {
    int y;
    int m;
    int d;

    in >> y;

    char x;
    in >> x;
    if(!in && (x != '-')) {
        in.setstate(std::ios_base::failbit);
    }

    in >> m;
    in >> x;

    if(!in && (x != '-')) {
        in.setstate(std::ios_base::failbit);
    }

    in  >> d;

    if(!in && (x != '-')) {
        in.setstate(std::ios_base::failbit);
    }
    if(m > 12) {
        in.setstate(std::ios_base::failbit);
    }
    if(d > Date::daysPerMonth[m-1]) {
        in.setstate(std::ios_base::failbit);
    }
    c.year = y;
    c.month = m;
    c.day = d;
    return in;
}

int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

void Date::next() {
    if(day + 1 < daysPerMonth[month-1]) {
        day++;
    } else if(month + 1 < 12) {
        month++;
        day = 1;
    } else {
        year++;
        month = 1;
        day = 1;
    }
}
#if 0
string Date::toString(const Date &d){
  string y = to_string(d.year); 
  string m = to_string(d.month); 
  string day = to_string(d.day);
  string ret = y + "-" + m + "-" + day; 
  return ret; 
}
#endif


#if 0
template <class T>

string Date::toString(T a){
  string ret;
  try{
    ret = std::to_string(a);
  }catch(std::invalid_argument& e){
    try{
      std::ostringstream os << a;
      ret = os.str();
    }catch(std::invalid_argument& e){
      std::cout << "No string representation found";
    }
  }
  return ret;
}
#endif
