/**@file	/home/elias/Documents/C++/lab3/TagRemover.h
 * @author	elias
 * @version	800
 * @date
 * 	Created:	25th Feb 2020
 * 	Last Update:	25th Feb 2020
 */

#ifndef TAGREMOVER_H
#define TAGREMOVER_H

#include <string>

class TagRemover 
{
public:
  TagRemover(std::istream& stream);
  void print();
  std::string getStringResualt();
private:
  std::string text;
}; 

#endif  // TAGREMOVER_H
