#include <string>
#include <vector>
#include "word.h"

using std::vector;
using std::string;


Word::Word(const string& w, const vector<string>& t, const int n) {
  trigs = t;
  word = w;
  numT = n;
}

unsigned int Word::numberOfTrigs(){
  return numT;
}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
    int hits = 0;
    size_t i1 = 0;
    size_t i2 = 0;
 
    while(i1 < trigs.size() && i2 < t.size()) {
        if(trigs.at(i1) == t.at(i2)) {
            hits++;
            i1++;
            i2++;
        } else if(trigs[i1] < t[i2]){
            i1++;
        } else {
            i2++;
        }
    }
    return hits;
}
