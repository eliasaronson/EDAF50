#include <iostream>
#include "primeFinder.h"
#include <string>
#include <vector>

using std::string;


PrimeFinder::PrimeFinder(int min, int max) {
    string s(max, 'P');
    s[0] = 'C';
    s[1] = 'C';
    for (int i = 2; i < max; i++) {
        for (int j = 2; j*i < max; j++) {
            if(i*j < max){
              s[i*j] = 'C';
            }
        }
    }
    //primeV.push_back(min);
#if 1
    while(s.find("P") != string::npos) {
        int p = s.find("P");
        if(p > min) {
            primeV.push_back(p);
            s[p] = 'D';
        }
    }

#endif
}

std::vector<int> PrimeFinder::getVector(){
  return primeV;
}

 void PrimeFinder::print(){
  for(auto&& x : primeV){
    std::cout << x << ' ';
  }
}
