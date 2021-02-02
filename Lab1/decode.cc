#include <iostream>
#include <fstream>
#include "coding.h"

 int main() {
  std::cout << "Enter file name:" << '\n';
  std::string filename;
  getline(std::cin, filename);




  std::ifstream inFile;
  inFile.open(filename);

  if (!inFile) {
        std::cout << "Unable to open file";
        exit(1); // terminate with error
  }
  //std::string text( (std::istreambuf_iterator<char>(inFile) ),
  //                     (std::istreambuf_iterator<char>()    ) );

  //unsigned char out[text.length];
  //std::vector<unsigned char> out(std::string const& str)
  std::string output;
  char c;
  while (inFile.get(c)) {
    //std::string sName(reinterpret_cast<char>(static_cast<char>(encode(c))));
    char sName = static_cast<char>(decode(c));
    output = output + sName;
  }
  inFile.close();


  std::ofstream out("output_decoded.txt");
  out << output;
  out.close();
  std::cout << output << '\n';


  return 0;
}
