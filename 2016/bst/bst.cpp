#include <iostream>
#include <stack>
#include <string>
#include "node.hpp"

namespace bst{
  template <class T>
  Node<T> *insert(Node<T> *root, T val) {
    if (root == nullptr) return new Node<T>(val);
    else if (val < root->value)
      root->left = insert(root->left, val);
    else if (val > root->value)
      root->right = insert(root->right, val);
    return root;
  }

  template <class T>
  T search_max(Node<T> *root) {
    while (root->right != nullptr) root = root->right;
    return root->value;
  }
  
  template <class T>
  Node<T> *delete_max(Node<T> *root) {
    if (root->right == nullptr) {
      Node<T> *temp = root->left;
      delete(root);
      return temp;
    }
    root->right = delete_max(root->right);
    return root;
  }

  template<class T>		
  Node<T> *remove(Node<T> *root, T val) {
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
      root->left = delete_max(root->left);
    }
    else if (val < root->value) root->left = remove(root->left, val);
    else root->right = remove(root->right, val);
    return root;
  }

  template <class T>
  std::string ToString(Node<T> *node, int depth) {
    std::string space;
    for (int i = 0; i < depth; i++) space += "  ";
    return space + std::to_string(node->value);
  }
  
  template <class T>
  void Disp(Node<T> *root, int depth) {
    if (root->right != nullptr) Disp(root->right, depth + 1);
    std::cout << ToString(root, depth) << std::endl;    
    if (root->left != nullptr) Disp(root->left, depth + 1);
  }

  template<class T>
  void Disp(Node<T> *root) {
    Disp(root, 0);
  }
}

int main() {
  Node<int> *tree = new Node<int>(50);
  bst::insert(tree, 25);
  bst::insert(tree, 15);
  bst::insert(tree, 40);
  bst::insert(tree, 75);
  bst::insert(tree, 60);
  bst::insert(tree, 90);
  bst::insert(tree, 10);
  bst::insert(tree, 20);
  bst::insert(tree, 30);
  bst::insert(tree, 45);
  bst::insert(tree, 55);
  bst::insert(tree, 70);
  bst::insert(tree, 80);
  bst::insert(tree, 100);
  bst::Disp(tree);
 
  std::cout << "\n-----------------------------\n" << std::endl;
  bst::remove(tree, 15);
  bst::Disp(tree);
  bst::remove(tree, 75);  
  std::cout << "\n-----------------------------\n" << std::endl;
  bst::Disp(tree);
  
  return 0;
}
