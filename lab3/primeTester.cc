#include "primeFinder.h"
#include <iostream>
#include <vector>

using std::vector;

int main(){
  std::cout << "Test initiated \n";
  vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}; 
  PrimeFinder pf(1, 100);
  if(pf.getVector() == primes){
    std::cout << "Test primes 1 to 100: Succeeded \n";
  }else{
    std::cout << "Test primes 1 to 100: Failed \n";
    std::cout << "Resualt: \n";
    pf.print();
  }
}
