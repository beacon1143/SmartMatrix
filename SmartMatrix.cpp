#include "SmartMatrix.h"

namespace SMART_MATRIX {

  template <typename T>
  int SmartMatrix<T>::PushBackToRow(const size_t iRow, const T data) {
    if (iRow >= arr_.size()) {
      std::cout << "The matrix doesn't contain a row with that index\n";
      return 1;
    }
    arr_[iRow]->PushBack(data);
    return 0;
  }

  template <typename T>
  int SmartMatrix<T>::DeleteRow(const size_t iRow) {
    if (iRow >= arr_.size()) {
      std::cout << "The matrix doesn't contain a row with that index\n";
      return 1;
    }
    for (size_t i = iRow; i < arr_.size() - 1; i++) {
      arr_[i] = arr_[i + 1];
    }
    arr_.resize(arr_.size() - 1);
    return 0;
  }

  template <typename T>
  int SmartMatrix<T>::DeleteColumn(const size_t iColumn) {
    for (auto list_ptr : arr_) {
      list_ptr->Pop(iColumn);
    }
    if (iColumn == 0) {  // maybe need to remove some rows
      size_t j = 0;  // second index for linear complexity
      for (auto list_ptr : arr_) {
        if (list_ptr->GetSize() == 0) {
          continue;
        }
        arr_[j] = list_ptr;
        j++;
      }
      arr_.resize(j);
    }
    return 0;
  }

  template <typename T>
  std::ostream& operator<<(std::ostream& out, const SmartMatrix<T>& sm) {
    for (auto list_ptr : sm.arr_) {
      out << *list_ptr;
    }
    return out;
  }


  template <typename T>
  SmartMatrix<T>::SmartMatrix(const size_t size) {
    arr_.resize(size);
    for (auto& list_ptr : arr_) {
      list_ptr = std::make_shared<ForwardList<T>>();
    }
  }

  template <typename T>
  SmartMatrix<T>::~SmartMatrix() {
    arr_.clear();
  }

} // namespace
