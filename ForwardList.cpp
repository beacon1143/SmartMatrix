#include "ForwardList.h"

namespace SMART_MATRIX {

  template <typename T>
  size_t ForwardList<T>::GetSize() const {
    return size_;
  }

  template <typename T>
  int ForwardList<T>::PushBack(const T inp) {
    try {
      if (size_ == 0) {
        first_ = std::make_unique<Node<T>>(inp);
        last_ = first_.get();
      }
      else {
        if (last_ == nullptr) {
          throw std::runtime_error("Error! In ForwardList::PushBack!");
        }
        last_->next = std::make_unique<Node<T>>(inp);
        last_ = last_->next.get();
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
  int ForwardList<T>::Pop(const size_t idx) {
    if (idx >= size_) {
      //std::cout << "The list doesn't contain an element with that index!\n";
      return 1;
    }
    if (idx == 0) {    // removing the first node of the list
      auto tmp = std::move(first_);
      first_ = std::move(tmp->next);
      size_--;
      return 0;
    }
    auto tmp = first_.get();
    if (tmp == nullptr) {
      throw std::runtime_error("Error! In ForwardList::Pop!");
    }
    for (size_t i = 0; i < idx - 1; i++) {
      if (tmp->next == nullptr) {
        throw std::runtime_error("Error! In ForwardList::Pop!");
      }
      tmp = tmp->next.get();
    }
    if (tmp == nullptr) {
      throw std::runtime_error("Error! In ForwardList::Pop!");
    }
    auto toDelete = std::move(tmp->next);
    tmp->next = std::move(toDelete->next);
    size_--;
    return 0;
  }

  template <typename T>
  std::ostream& operator<<(std::ostream& out, const ForwardList<T>& fl) {
    if (fl.size_ == 0) {
      out << "No elements in the list!\n";
      return out;
    }
    auto tmp = fl.first_.get();
    if (tmp == nullptr) {
      throw std::runtime_error("Error! In ForwardList::operator!");
    }
    while (tmp->next != nullptr) {
      out << tmp->data << " ";
      tmp = tmp->next.get();
    }
    out << tmp->data << "\n";
    return out;
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
    if (first_ == nullptr) {
      return;
    }
    while (first_ != nullptr) {
      //std::cout << "In the loop...\n";
      first_ = std::move(first_->next);
    }
    last_ = nullptr;
  }

} // namespace
