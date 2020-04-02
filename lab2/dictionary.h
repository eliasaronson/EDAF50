#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "word.h"
#include <unordered_set>
#include <string>
#include <vector>

class Dictionary {
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
  std::vector<std::string> add_trigram_suggestions(const std::string& word) const;
private:
std::unordered_set<std::string> words;
std::vector<Word> wordM[25];
};

#endif
