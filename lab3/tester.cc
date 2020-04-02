#include <iostream>
#include "TagRemover.h"
#include <fstream>
#include <iostream>

using std::string;

int main(){

  //Test single line example
  std::ifstream input("simpleLineHTMLTest.html");
  
  std::string testStringNoTags = "This is a paragraph.";
  std::cout << "*****************************" << std::endl;

  TagRemover tg(input);
  string res = tg.getStringResualt();
  if(res.compare(testStringNoTags) == 0){
    std::cout << "Single-line test: Success. \n";
  }else {
    std::cout << "Single line test: Fail. \n";
    std::cout << "Resualt: \n";
    std::cout << res << std::endl;
    std::cout << "Should be:" << std::endl;
    std::cout << testStringNoTags << std::endl;
  }
  input.close();
  std::cout << "*****************************" << std::endl;


  //Test more complex multiline example
  std::ifstream input1("test.html");

  TagRemover tg1(input1);
  string res1 = tg1.getStringResualt();

  string correct = "This is a line without a tag\nThis is  a line with one tag\nAnd this  line has two tags \nA line with a starting tag \n\n which finished on this line \nSpecial chars: &lt;&gt;&nbsp;&amp;";

  if(res1.compare(correct) == 0){
    std::cout << "Multi-line test: Success. \n";
  }else {
    std::cout << "Multi line test: Fail. \n";
    std::cout << "Resualt: \n";
    std::cout << res1 << std::endl;
    std::cout << "Should be:" << std::endl;
    std::cout << correct << std::endl;
  }
  input.close();
  std::cout << "*****************************" << std::endl;

  

/* /
  //Primenumber finder tester
  std::vector<int> testPrimes{};
  PrimeFinder pf(3, 35);

  if (pf.getVector().empty()) {
    std::cout << "No primes found";
  } else if (pf.getVector == testPrimes){
    std::cout << "Corrent primes found";
  }
  else{
    std::cout << "Wrong primes";
 }




  //Date tester
  
  
  
  */
}
