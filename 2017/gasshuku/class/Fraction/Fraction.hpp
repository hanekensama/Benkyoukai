#ifndef __FRACTION_HPP__
#define __FRACTION_HPP__

#include <iostream>
#include <cstdio>

class Fraction {
private:
  int denom_, numer_;
  void reduce();
  inline int GCD(int a, int b) const;
public:
  Fraction(int numer, int denom=1);
  Fraction operator+();
  Fraction operator-();
  Fraction operator+(const Fraction& other) const;
  Fraction operator-(const Fraction& other) const;
  Fraction operator*(const Fraction& other) const;
  Fraction operator/(const Fraction& other) const;
  bool operator==(const Fraction& other) const;
  bool operator!=(const Fraction& other) const;
  bool operator<(const Fraction& other) const;
  bool operator>(const Fraction& other) const;
  bool operator<=(const Fraction& other) const;
  bool operator>=(const Fraction& other) const;
  operator double() const;
  friend std::ostream& operator<<(std::ostream& os, Fraction num);
};

std::ostream& operator<<(std::ostream& os, Fraction num);

#endif // __FRACTION_HPP__
