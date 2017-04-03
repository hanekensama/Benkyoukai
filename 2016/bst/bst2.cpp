#include <iostream>
#include <string>
#include "bst.hpp"

int main() {
  bst<int> tree;
  tree.insert(5);
  tree.insert(2);
  tree.insert(6);
  tree.insert(3);
  tree.insert(4);
  tree.insert(1);
  tree.insert(7);
  tree.insert(8);
  tree.insert(5);
  tree.disp();
  std::cout << "--------------" << std::endl;
  tree.remove(5);
  tree.disp();
  std::cout << "--------------" << std::endl;

  bst<std::string> stree;
  stree.insert("aa");
  stree.insert("xyz");
  stree.insert("abc");
  stree.insert("a");
  stree.disp();
  return 0;
}
