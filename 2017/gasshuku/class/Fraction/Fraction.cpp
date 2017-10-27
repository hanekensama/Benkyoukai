#include "Fraction.hpp"

Fraction::Fraction(int numer, int denom) {
  numer_ = numer;
  denom_ = denom;
  reduce();
}

Fraction Fraction::operator-() {
  this->numer_ = -(this->numer_);
  reduce();
  return *this;
}

Fraction Fraction::operator+() {
  reduce();
  return *this;
}

Fraction Fraction::operator+(const Fraction& other) const {
  auto denom = this->denom_ * other.denom_;
  auto numer = this->numer_* other.denom_ + this->denom_ * other.numer_;
  
  return Fraction(numer, denom);
}

Fraction Fraction::operator-(const Fraction& other) const {
  auto denom = this->denom_ * other.denom_;
  auto numer = this->numer_* other.denom_ - this->denom_ * other.numer_;
  
  return Fraction(numer, denom);
}

Fraction Fraction::operator*(const Fraction& other) const {
  auto denom = this->denom_ * other.denom_;
  auto numer = this->numer_ * other.numer_;

  return Fraction(numer, denom);
}

Fraction Fraction::operator/(const Fraction& other) const {
  auto denom = this->denom_ * other.numer_;
  auto numer = this->numer_ * other.denom_;

  return Fraction(numer, denom);
}

bool Fraction::operator==(const Fraction& other) const {
  return (this->denom_ == other.denom_ && this->numer_ == other.numer_);
}

bool Fraction::operator!=(const Fraction& other) const {
  return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const {
  return (double)*this < (double)other;
}

bool Fraction::operator>(const Fraction& other) const {
  return (double)*this > (double)other;
}

bool Fraction::operator<=(const Fraction& other) const {
  return (*this == other || *this < other);
}

bool Fraction::operator>=(const Fraction& other) const {
  return (*this == other || *this > other);
}

Fraction::operator double() const {
  return (double)numer_ / denom_;
}

void Fraction::reduce() {
  auto gcd = GCD(denom_, numer_);
  denom_ /= gcd;
  numer_ /= gcd;
}

inline int Fraction::GCD(int a, int b) const {
  int r;
  while((r = a % b) != 0) {
    a = b;
    b = r;
  }
  return b;
}

std::ostream& operator<<(std::ostream& os, Fraction num) {
  char str[64];
  sprintf(str, "%d/%d", num.numer_, num.denom_);
  os << str;
  return os;
}
