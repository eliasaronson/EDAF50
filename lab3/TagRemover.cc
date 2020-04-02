#include <iostream>
#include "TagRemover.h"
#include <string>

using std::string;

string text;

TagRemover::TagRemover(std::istream& stream) {
    text = "";
    string line;
    bool conNextL = false;
    bool first = true;
    while(std::getline(stream, line)) { //Going through input
        if(conNextL) {
            if (line.find(">") == string::npos) {
                line = "";
            } else {
                line.erase(0, line.find(">") + 1);
                conNextL = false;
            }
        }
        while (line.find("<") != std::string::npos) { // Going through line
            //If tag continuued from last remove begining to end.

            auto startpos = line.find("<");
            auto endpos = line.find(">") + 1;
            //if no closing > found, remove til end of line and set conNext to
            //true.
            //Else remove tag.
            if (line.find(">") == std::string::npos) {
                line.erase(startpos, line.back());
                conNextL = true;
            } else {
                line.erase(startpos, endpos - startpos);
            }


        }
        if (first) {
            first = false;
            text += line;
        } else {
            text += "\n" + line;
        }
    }
}


void print() {
    string out = text;
    std::cout << out;
}


string TagRemover::getStringResualt() {
    return text;
}
