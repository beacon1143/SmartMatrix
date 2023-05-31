#include "ForwardList.h"

namespace SMART_MATRIX {

  template <typename T>
  size_t ForwardList<T>::GetSize() {
    return size_;
  }

  template <typename T>
  void ForwardList<T>::PushBack(T inp) {
    ForwardNode<T>* tmp = new ForwardNode<T>;
    tmp->data = inp;
    tmp->next = nullptr;
    if (size_ == 0) {
      first_ = tmp;
      last_ = tmp;
    }
    else {
      last_->next = tmp;
      last_ = last_->next;
    }
    //std::cout << "first = " << first_->data << ", last = " << last_->data << "\n";
    size_++;
  }

  template <typename T>
  void ForwardList<T>::Print() {
    ForwardNode<T>* tmp = first_;
    while (tmp->next != nullptr) {
      std::cout << tmp->data << "\n";
      tmp = tmp->next;
    }
    std::cout << tmp->data << "\n";
  }

  template <typename T>
  T ForwardList<T>::Pop(size_t idx) {
    ForwardNode<T>* tmp = first_;
    T retValue;
    if (idx == 0) {
      retValue = first_->data;
      tmp = first_->next;
      delete first_;
      first_ = tmp;
      return retValue;
    }
    for (size_t i = 0; i < idx - 1; i++) {
      tmp = tmp->next;
    }
    ForwardNode<T>* toDelete = tmp->next;
    retValue = toDelete->data;
    tmp->next = tmp->next->next;
    delete toDelete;
    size_--;
    return retValue;
  }


  template <typename T>
  ForwardList<T>::ForwardList() {
    first_ = nullptr;
    last_ = nullptr;
    size_ = 0;
  }

  template <typename T>
  ForwardList<T>::~ForwardList() {
    //std::cout << "In the destructor...\n";
    ForwardNode<T>* tmp = nullptr;
    while (first_->next != nullptr) {
      //std::cout << "In the loop...\n";
      tmp = first_->next;
      //std::cout << "tmp = " << tmp->data << "\n";
      delete first_;
      first_ = tmp;
    }
    delete first_;
    first_ = nullptr;
    last_ = nullptr;
  }

} // namespace
