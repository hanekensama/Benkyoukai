#include <iostream>
#include <cstdlib>

using namespace std;

class IntNode {
private:
  int value_;
  IntNode* next_;
public:
  IntNode(int value) {    // コンストラクタ
    this->value_ = value;  // 自分自身はthisで指定
    this->next_ = nullptr;
  }

  ~IntNode() {            // デストラクタ
  }
  
  int getValue() {
    return this->value_;
  }
  
  IntNode* getNext() {
    return this->next_;
  }
  
  void Connect(IntNode* next_node) {
    this->next_ = next_node;
  }
};

class IntStack {
private:
  IntNode* top_;
  unsigned int size_;
  void freeAll();
public:
  IntStack();
  ~IntStack();
  void push(int value);
  int pop();
  unsigned int size();
};

IntStack::IntStack() { // クラス宣言の外部で実装も可能
  top_ = nullptr;       // 変数を一意に識別できる場合はthisがなくても良い
  size_ = 0;
}

IntStack::~IntStack() {
  freeAll(); // メモリ解放などはデストラクタの中で行う
}

void IntStack::push(int value) {
  IntNode* new_node = new IntNode(value); // new ではオブジェクトのポインタが得られる
  if (top_ != nullptr) new_node->Connect(top_);

  top_ = new_node;
  size_++;
}

int IntStack::pop() {
  if (top_ == nullptr) return 0;
 
  IntNode* top_node = top_;
  int value = top_node->getValue();
  top_ = top_node->getNext();

  delete top_node; // newしたオブジェクトはdeleteで破棄
  size_--;

  return value;
}

unsigned int IntStack::size() {
  return size_;
}

void IntStack::freeAll() {
  IntNode *current_node = top_, *next_node;
  while(current_node != nullptr) {
    next_node = current_node->getNext();
    delete current_node;
    current_node = next_node;
  }
}

int main() {
  IntStack stack;

  stack.push(1);
  cout << stack.pop() << endl;
  cout << stack.pop() << endl;

  stack.push(2);
  stack.push(3);
  stack.push(4);
  cout << stack.pop() << endl;
  cout << stack.pop() << endl;
  cout << stack.pop() << endl;

  return 0;
}
