#ifndef FORWARDLIST_H
#define FORWARDLIST_H

#include <iostream>
#include <string>
#include <stddef.h>
#include <stdexcept>
#include <memory>

namespace SMART_MATRIX {

  template <typename T>
  class ForwardList {
  private:
    template <typename T1>
    struct Node {
      const T1 data;
      std::unique_ptr<Node<T1>> next;
      template <typename T2>
      explicit Node(T2 _data) : data{_data}, next{nullptr} {}
    };
    std::unique_ptr<Node<T>> first_;
    Node<T>* last_;
    size_t size_;
  public:
    size_t GetSize() const;
    int PushBack(T inp);
    int Pop(size_t idx);
    template <typename T1>
    friend std::ostream& operator<<(std::ostream& out, const ForwardList<T1>& fl);

    ForwardList();
    ~ForwardList();

    ForwardList(const ForwardList& other) = delete;
    ForwardList(ForwardList&& tmp) = delete;
    ForwardList& operator=(const ForwardList& other) = delete;
    ForwardList& operator=(ForwardList&& tmp) = delete;
  };

} // namespace

#endif // FORWARDLIST_H
