#include <iostream>
#include "ForwardList.h"
#include "ForwardList.cpp"

using namespace SMART_MATRIX;

int main() {
  try {
    ForwardList<int> fl;
    fl.PushBack(1);
    fl.PushBack(2);
    fl.PushBack(3);
    fl.PushBack(4);
    fl.Pop(2);
    fl.Pop(1);
    fl.Print();
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what();
    return 1;
  }
}
