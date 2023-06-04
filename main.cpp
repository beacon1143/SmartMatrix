#include <iostream>
#include <fstream>
#include <sstream>
#include "ForwardList.h"
#include "ForwardList.cpp"
#include "SmartMatrix.h"
#include "SmartMatrix.cpp"

using namespace SMART_MATRIX;

int main() {
  try {
    using EL_TYPE = int;
    std::ifstream inp("data.dat");
    if (!inp.is_open()) {
      std::cerr << "Error! Cannot open file data.txt!\n";
      return 2;
    }
    std::string tmpString;
    std::getline(inp, tmpString);  // first line which contains nRows only
    size_t nRows = 0;
    try {
      nRows = std::stoul(tmpString);
    }
    catch (const std::invalid_argument& e) {
      std::cerr << "Error! First line in file data.txt should contain nRows only!\n" << e.what();
      return 3;
    }
    if (nRows == 0) {
      std::cerr << "Error! Wrong rows amount in file data.txt!\n";
      return 3;
    }
    SmartMatrix<EL_TYPE> sm(nRows);

    EL_TYPE tmpElem;
    for (size_t i = 0; i < nRows; i++) {
      std::getline(inp, tmpString);
      std::stringstream strStream;
      strStream << tmpString;
      while (strStream >> tmpElem) {
        sm.PushBackToRow(i, tmpElem);
      }
    }
    inp.close();

    //std::cout << sm;
    sm.DeleteRow(2);
    //std::cout << sm;
    sm.DeleteColumn(0);
    std::cout << sm;
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what();
    return 1;
  }
}
