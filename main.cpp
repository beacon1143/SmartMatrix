#include <iostream>
#include "ForwardList.h"
#include "ForwardList.cpp"
#include "SmartMatrix.h"
#include "SmartMatrix.cpp"

using namespace SMART_MATRIX;

int main() {
  try {
    SmartMatrix<int> sm(5);
    sm.PushBackToRow(0, 1);
    sm.PushBackToRow(0, 2);
    sm.PushBackToRow(0, 3);
    sm.PushBackToRow(1, 4);
    sm.PushBackToRow(2, 5);
    sm.PushBackToRow(2, 6);
    sm.PushBackToRow(3, 7);
    sm.PushBackToRow(4, 8);
    sm.PushBackToRow(4, 9);
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
