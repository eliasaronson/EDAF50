#include <iostream>
#include "word.h"
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <istream>
#include<algorithm>
#include <iterator>

bool comp (std::string a, std::string b) {return a<b;} 

std::string trigrams(std::string s){ 
  std::string ret;
  if (s.length() < 3) {
   ret = "0"; 
  }else{
    std::for_each(s.begin(), s.end(), [](char & c){
  	c = ::tolower(c);
    });
    int numTrig = s.length() - 2;
    ret = std::to_string(numTrig);

    std::vector<std::string> trigs;

    for (int i = 0; i < numTrig; i++) {
      std::string trigOut;
      trigOut += s[i]; 
      trigOut += s[i+1];
      trigOut += s[i+2];
      trigs.push_back(trigOut);
    }
   
    std::sort(trigs.begin(), trigs.end(), comp);

    for(unsigned int i = 0; i < trigs.size(); i++){
      ret = ret + " " + trigs[i];
    }
  }
  return ret; 
}


void read(){
  std::vector<std::string> words;
  std::ifstream input("wordlist");
  std::string line;

  while(std::getline(input, line)){
    std::for_each(line.begin(), line.end(), [](char & c){
  	c = ::tolower(c);
    });
    line = line + " " + trigrams(line);
    words.push_back(line);
  }
  for(int i = 0; i < 100; i++){
    std::cout<<words[i]<<"\t";
  }
  std::ofstream output_file("words.txt");
  std::ostream_iterator<std::string> output_iterator(output_file, "\n");
  std::copy(words.begin(), words.end(), output_iterator);
}







 int main(){
    read();
}


