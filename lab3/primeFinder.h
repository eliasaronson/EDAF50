#ifndef PRIMEFINDER_H
#define PRIMEFINDER_H

#include <string>
#include <vector>

class PrimeFinder
{
public:
  PrimeFinder(int min, int max);
  void print();
  std::vector<int> getVector();
private:
  std::vector<int> primeV;
};

#endif  // TAGREMOVER_H

