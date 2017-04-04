#include <iostream>
#include <cstdio>

class Vector2D {
private:
  int x_;
  int y_;

public:
  Vector2D(int x, int y);
  int getX();
  int getY();
  Vector2D operator+ (Vector2D other);
  Vector2D operator- (Vector2D other);
  Vector2D operator* (int other);
  Vector2D operator/ (int other);
  bool operator== (Vector2D other);
  bool operator!= (Vector2D other);
  bool operator< (Vector2D other);
  bool operator> (Vector2D other);
  bool operator<= (Vector2D other);
  bool operator>= (Vector2D other);
  Vector2D operator++();
  Vector2D operator++(int n);
  Vector2D operator--();
  Vector2D operator--(int n);
};

std::ostream& operator<<(std::ostream& os, Vector2D v); // クラス外部に作成する

Vector2D::Vector2D(int x, int y) {
  x_ = x;
  y_ = y;
}

int Vector2D::getX() {
  return x_;
}

int Vector2D::getY() {
  return y_;
}

Vector2D Vector2D::operator+(Vector2D other) {
  return Vector2D(this->x_ + other.x_, this->y_ + other.y_);
}

Vector2D Vector2D::operator-(Vector2D other) {
  return Vector2D(this->x_ - other.x_, this->y_ - other.y_);
}

Vector2D Vector2D::operator*(int other) {
  return Vector2D(this->x_ * other, this->y_ * other);
}

Vector2D Vector2D::operator/(int other) {
  return Vector2D(this->x_ / other, this->y_ / other);
}

bool Vector2D::operator== (Vector2D other) {
  return (this->x_ == other.x_ && this->y_ == other.y_);
}

bool Vector2D::operator!= (Vector2D other) {
  return !(*this == other);
}

bool Vector2D::operator< (Vector2D other) {
  if (this->x_ < other.x_) return true;
  else if (this->x_ == other.x_ &&
	   this->y_ < other.y_) return true;
  else return false;
}

bool Vector2D::operator> (Vector2D other) {
  if (this->x_ > other.x_) return true;
  else if (this->x_ == other.x_ &&
	   this->y_ > other.y_) return true;
  else return false;
}

bool Vector2D::operator<= (Vector2D other) {
  return !(*this > other);
}

bool Vector2D::operator>= (Vector2D other) {
  return !(*this < other);
}

Vector2D Vector2D::operator++() { // 前置演算子
  ++x_;
  ++y_;
  return *this;
}

Vector2D Vector2D::operator++(int n) { // 後置演算子
  x_++;
  y_++;
  return *this;
}

Vector2D Vector2D::operator--() {
  --x_;
  --y_;
  return *this;
}

Vector2D Vector2D::operator--(int n) {
  x_--;
  y_--;
  return *this;
}

std::ostream& operator<<(std::ostream& os, Vector2D v) {
  char str[32];
  sprintf(str, "(%d, %d)", v.getX(), v.getY());
  os << str;
  return os;
}

int main() {
  Vector2D a(1,2), b(2,3);

  std::cout << "a: " << a << std::endl;
  std::cout << "b: " << b << std::endl << std::endl;
  
  std::cout << "a+b: " << (a + b) << std::endl;
  std::cout << "a-b: " << (a - b) << std::endl;
  std::cout << "a*2: " << (a * 2) << std::endl;
  std::cout << "a/2: " << (a / 2) << std::endl << std::endl;

  std::cout << "a==b: " << (a == b) << std::endl;
  std::cout << "a!=b: " << (a != b) << std::endl;
  std::cout << "a<b:" << (a < b) << std::endl;
  std::cout << "a>b:" << (a > b) << std::endl;
  std::cout << "a<=b:" << (a <= b) << std::endl;
  std::cout << "a>=b:" << (a >= b) << std::endl << std::endl;

  std::cout << "++a: " << (++a) << std::endl;
  std::cout << "a++: " << (a++) << std::endl;
  std::cout << "--a: " << (--a) << std::endl;
  std::cout << "a--: " << (a--) << std::endl;

  return 0;
}
