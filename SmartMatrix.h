#ifndef SMARTMATRIX_H
#define SMARTMATRIX_H

#include <vector>
#include <memory>
#include "ForwardList.h"

namespace SMART_MATRIX {

  template <typename T>
  class SmartMatrix {
  private:
    std::vector<std::shared_ptr<ForwardList<T>>> arr_;
  public:
    int PushBackToRow(size_t iRow, T data);
    int DeleteRow(size_t iRow);
    int DeleteColumn(size_t iColumn);
    void Print() const;

    SmartMatrix(size_t size);
    ~SmartMatrix();

    SmartMatrix(const SmartMatrix& other) = delete;
    SmartMatrix(SmartMatrix&& tmp) = delete;
    SmartMatrix& operator=(const SmartMatrix& other) = delete;
    SmartMatrix& operator=(SmartMatrix&& tmp) = delete;
  };
} // namespace

#endif // SMARTMATRIX_H
