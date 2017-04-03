#ifndef BST_HPP
#define BST_HPP
#include <string>
#include <iostream>

template <class T>
struct Node {
  T value;
  Node* left;
  Node* right;
  explicit Node(const T& value);
};

template <class T>
Node<T>::Node(const T& value) : value(value), left(nullptr), right(nullptr) {
}

template <class T>
class bst {
private:
  Node<T> *root;
  T search_max(Node<T> *root);
  Node<T> *remove_max(Node<T> *root);
  Node<T> *remove_node(Node<T> *root, T val);
  void disp(Node<T> *root, int depth);
public:
  bst();
  Node<T> *insert(T val);
  Node<T> *remove(T val);
  Node<T> *search(T val);
  void disp();
};

template <class T>
T bst<T>::search_max(Node<T> *root) {
  while(root->right != nullptr) root = root->right;
  return root->value;
}

template <class T>
Node<T> *bst<T>::remove_max(Node<T> *root) {
  if (root->right == nullptr) {
    Node<T> *temp = root->left;
    delete(root);
    return temp;
  }
  root->right = remove_max(root->right);
  return root;
}

template <class T>
Node<T> *bst<T>::remove_node(Node<T> *root, T val) {
  if (root == nullptr) return nullptr;
  if (val == root->value) {
    if (root->left == nullptr) {
      Node<T> *temp = root->right;
      delete(root);
      return temp;
      }
      if (root->right == nullptr) {
	Node<T> *temp = root->left;
	delete(root);
	return temp;
      }
      root->value = search_max(root->left);
      root->left = remove_max(root->left);
    }
    else if (val < root->value) root->left = remove_node(root->left, val);
    else root->right = remove_node(root->right, val);
    return root;
}

template <class T>
void bst<T>::disp(Node<T>* root, int depth) {
  if (root->right != nullptr) disp(root->right, depth + 1);
  for (int i = 0; i < depth; i++) std::cout << "  ";
  std::cout << root->value << std::endl;
  if (root->left != nullptr) disp(root->left, depth + 1);
}

template <class T>
bst<T>::bst() {
  root = nullptr;
}

template <class T>
Node<T> *bst<T>::insert(T val) {
  if (root == nullptr) return root = new Node<T>(val);
  Node<T> *current = root;
  while(true) {
    if (val < current->value) {
      if (current->left == nullptr) return current->left = new Node<T>(val);
      else current = current->left;
    }
    else if (val > current->value) {
      if (current->right == nullptr) return current->right = new Node<T>(val);
      else current = current->right;
    }
    else return current;
  }
}

template <class T>
Node<T> *bst<T>::remove(T val) {
  return remove_node(root, val);
}

template <class T>
Node<T> *bst<T>::search(T val) {
  Node<T> *current = root;
  while(true) {
    if(current == nullptr || val == current->value) return current;
    else if (val < current->val) current = current->left;
    else current = current->right;
  }
}

template <class T>
void bst<T>::disp() {
  return disp(root, 0);
}

#endif  // BST_HPP
