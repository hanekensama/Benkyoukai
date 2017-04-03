#ifndef NODE_HPP
#define NODE_HPP

template <class T>
struct Node {
  T value;
  Node* left;
  Node* right;
  explicit Node(const T& value);
};

template <class T>
Node<T>::Node(const T& value) : value(value), left(NULL), right(NULL) {
}

// Node<int>* node = new Node<int>(3);

#endif   // NODE_HPP
