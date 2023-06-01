#include "ForwardList.h"

namespace SMART_MATRIX {

  template <typename T>
  size_t ForwardList<T>::GetSize() {
    return size_;
  }

  template <typename T>
  int ForwardList<T>::PushBack(T inp) {
    try {
      ForwardNode<T>* tmp = new ForwardNode<T>;
      tmp->data = inp;
      tmp->next = nullptr;
      if (size_ == 0) {
        first_ = tmp;
        last_ = tmp;
      }
      else {
        if (last_ == nullptr) {
          throw std::runtime_error("Error! In ForwardList::PushBack!");
        }
        last_->next = tmp;
        last_ = last_->next;
      }
      //std::cout << "first = " << first_->data << ", last = " << last_->data << "\n";
      size_++;
      return 0;
    }
    catch (const std::bad_alloc& e) {
      std::cerr << e.what() << "\n";
      return 1;
    }
  }

  template <typename T>
  void ForwardList<T>::Print() {
    if (size_ == 0) {
      std::cout << "No elements in the list!\n";
      return;
    }
    ForwardNode<T>* tmp = first_;
    if (tmp == nullptr) {
      throw std::runtime_error("Error! In ForwardList::Print!");
    }
    while (tmp->next != nullptr) {
      std::cout << tmp->data << " ";
      tmp = tmp->next;
    }
    std::cout << tmp->data << "\n";
  }

  template <typename T>
  int ForwardList<T>::Pop(size_t idx) {
    if (idx >= size_) {
      std::cout << "The list doesn't contain an element with that index!\n";
      return 1;
    }
    ForwardNode<T>* tmp = first_;
    if (tmp == nullptr) {
      throw std::runtime_error("Error! In ForwardList::Pop!");
    }
    if (idx == 0) {    // removing the first node of the list
      tmp = first_->next;
      delete first_;
      first_ = tmp;
      return 0;
    }
    for (size_t i = 0; i < idx - 1; i++) {
      if (tmp->next == nullptr) {
        throw std::runtime_error("Error! In ForwardList::Pop!");
      }
      tmp = tmp->next;
    }
    if (tmp == nullptr) {
      throw std::runtime_error("Error! In ForwardList::Pop!");
    }
    ForwardNode<T>* toDelete = tmp->next;
    tmp->next = tmp->next->next;
    delete toDelete;
    size_--;
    return 0;
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
