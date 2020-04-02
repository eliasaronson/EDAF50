#include <string>
#include <vector>
#include <utility>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <bits/stdc++.h>

using std::string;
using std::vector;



bool comF (Word a, Word b) {
    return a.get_word().length()<b.get_word().length();
}



Dictionary::Dictionary()
{
    std::ifstream input("words.txt");
    std::string line;
    std::vector<Word> wordsV;

    while(std::getline(input, line)) {
        std::stringstream stream(line);
        int num = 0;
        std::vector<std::string> trigV;
        std::string impW;
        int impNum;

        std::string w;
        while (stream >> w) {
            if(num == 0){
                words.insert(w);
                impW = w;
            }else if(num == 1){
              impNum = std::stoi(w);
            }
            else if(num > 1) {
                trigV.push_back(w);
            }
            num++;
        }
        if(impW.length() > 2){
            Word imp(impW, trigV, impNum);
            wordM[impW.length()].push_back(imp);
        }
            trigV.clear();
    }
    input.close();

}

bool Dictionary::contains(const string& word) const {
    return (words.find(word) != words.end());
}

std::vector<std::string> getTrigs(std::string word) {
    std::vector<std::string> ret;
    int nums = word.length()-2;
    for (int i = 0; i < nums; i++) {
        std::string trigOut = "";
        trigOut += word.at(i);
        trigOut += word.at(i+1);
        trigOut += word.at(i+2);
        ret.push_back(trigOut);
    }
    return ret;
}

vector<std::string> Dictionary::add_trigram_suggestions(const string& word)const {
    std::vector<std::string> ret;
    unsigned int length = word.length();
    if(length < 4) {
        std::cout << "To short word";
        return ret;
    } else {
        for(int i=0; i < 3; i++) {
            for(auto w : wordM[length - 1 + i]) {
                if(w.get_matches(getTrigs(word)) > 1) {
                    ret.push_back(w.get_word());
                }
            }

        }


        return ret;
    }
}

//bool comp (const std::pair<int,std::string> &a, const std::pair<int, std::string> &b) {
//    return a.first<b.first;
//}

bool compP(const std::pair<int,string> &a,
           const std::pair<int,string> &b)
{
    return (a.first > b.first);
}


vector<std::pair<int, std::string>> rank_suggestions(const std::string& word, const std::vector<std::string> suggest) {
    vector<std::pair<int, std::string>> ret;
    for (unsigned int x = 0; x < suggest.size(); x++) {
        int cost[26][26];
        cost[0][0] = 0;
        
        int l1 = word.length();
        int l2 = suggest[x].length();
        int val;

        for(int i = 0; i <= l1; i++){
          cost[0][i]= i;
        }
        
        for(int j = 0; j <= l1; j++){
          cost[j][0]= j;
        }

        for (int i = 1; i <= l1; i++) {
            for(int j = 1; j <= l2; j++) {
                if (word.at(i-1) == suggest[x].at(j-1)) {
                    val = 0;
                } else {
                    val = 1;
                }
                int delOrIns = std::min(cost[i-1][j] + 1, cost[i][j-1] + 1);
                cost[i][j] = std::min(cost[i-1][j-1] + val, delOrIns); 
            }
        }
        std::pair<int, std::string> retP(cost[l2][l1], suggest[x]);
        ret.insert(ret.begin(), retP);
    }
    std::sort(ret.begin(), ret.end(), compP);
    return ret;
}

void trim_suggesntions_to_five(std::vector<std::pair<int, std::string>>& suggests) {

    if (suggests.size() > 5) {
      suggests.resize(5);
    }
}


vector<string> Dictionary::get_suggestions(const string& word) const {
    auto suggestions = rank_suggestions(word, add_trigram_suggestions(word));
    trim_suggesntions_to_five(suggestions);
    std::vector<std::string> ret;
    for(const auto& p: suggestions){
       ret.push_back(p.second); 
    }
    return ret;
}

