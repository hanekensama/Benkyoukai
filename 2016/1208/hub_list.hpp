#ifndef __HUB_LIST_HPP__
#define __HUB_LIST_HPP__
#include <cstdlib> // size_t
#include <iostream>

namespace hub {
  template<typename T>
  class List {
    
  public:
    explicit List(int size = 0, T value = T());
    ~List();
    List(List const& other); // Deep Copy
    List(List&& other); // Move constructor
    List& operator =(List const& other);
    bool operator ==(List const& other);
    bool operator !=(List const& other);
    void pushFront(T val);
    void pushBack(T val);
    T popFront();
    bool empty();
    size_t size();
    void disp();

  private:
    class ListNode {
    public:
      T val;
      ListNode *next;
      explicit ListNode(T val);
      ~ListNode();
      ListNode(ListNode const& other);
    };
    ListNode *first_;
    ListNode *last_;
    size_t size_;
    void deleteAll();
    void deepCopy(List const& other);
  };
};

template <typename T>
hub::List<T>::List(int size, T value)
  : first_(nullptr), last_(nullptr), size_(0) {
  for(int i = 0; i < size; i++) {
    pushBack(value);
  }
}

template <typename T>
hub::List<T>::~List() {
  deleteAll();
}

template <typename T>
hub::List<T>::List(List<T> const& other)
  : size_(other.size_) {
  deepCopy(other);
}

template<typename T>
hub::List<T>::List(List<T>&& other)
  : first_(other.first_), last_(other.last_), size_(other.size_) {
}

template <typename T>
hub::List<T>& hub::List<T>::operator=(List<T> const& other) {
  if (*this != other) {
    deleteAll();
    size_ = other.size_;
    deepCopy(other);
  }
  return *this;
}

template <typename T>
bool hub::List<T>::operator==(List<T> const& other) {
  return (first_ == other.first_);
}

template <typename T>
bool hub::List<T>::operator!=(List<T> const& other) {
  return (first_ != other.first_);
}

template <typename T>
void hub::List<T>::pushFront(T val) {
  auto new_node = new ListNode(val);

  new_node->next = first_; 
  first_ = new_node;
  
  if(this->empty()) last_ = new_node;

  size_++;
}

template <typename T>
void hub::List<T>::pushBack(T val) {
  auto new_node = new ListNode(val);
  
  if (!this->empty()) last_->next = new_node;
  else                first_ = new_node;
  
  last_ = new_node;
  
  size_++;
}

template <typename T>
T hub::List<T>::popFront() {
  if (this->empty()) return T();
  
  auto deleted_node = first_;
  auto val = deleted_node->val;
  
  first_ = first_->next;
  delete deleted_node;
  size_--;
  
  if (size_ == 0) last_ = nullptr;

  return val;
}

template <typename T>
bool hub::List<T>::empty() {
  return (this->size_ == 0);
}

template <typename T>
size_t hub::List<T>::size() {
  return this->size_;
}

template <typename T>
void hub::List<T>::disp() {
  auto current_node = first_;
  while(current_node != nullptr) {
    std::cout<< current_node->val << " ";
    current_node = current_node->next;
  }
  std::cout << std::endl;
}

template <typename T>
void hub::List<T>::deleteAll() {
  auto current_node = first_;
  while (current_node != nullptr) {
    auto next_node = current_node->next;
    delete current_node;
    current_node = next_node;
  }
  size_ = 0;
}

template <typename T>
void hub::List<T>::deepCopy(List<T> const& other) {
   auto current_node = this->first_;
   auto other_current_node = other.first_;
   while(other_current_node != nullptr) {
     current_node = new ListNode(*other_current_node->next);
     last_ = current_node;
     current_node = current_node->next;
     other_current_node = other_current_node->next;
   }
}

template <typename T>
hub::List<T>::ListNode::ListNode(T val)
  : val(val), next(nullptr) {
}

template <typename T>
hub::List<T>::ListNode::~ListNode() {
}

template <typename T>
hub::List<T>::ListNode::ListNode(ListNode const& other)
  : val(other.val), next(nullptr) {
}

#endif // __HUB_LIST_HPP__
