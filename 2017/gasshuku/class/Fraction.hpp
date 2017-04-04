class Fraction {
private:
  int denom_, numer_;
  void reduce();
  inline int Euclid(int a, int b) const;
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
  float operator float() const;
};

Fraction::Fraction(int numer, int denom=1) {
  numer_ = numer;
  denom_ = denom;
  reduce();
}

Fraction Fraction::operator-() {
  this.numer_ = -(this.numer_);
  reduce();
  return *this;
}

Fraction Fraction::operator+() {
  reduce();
  return *this;
}

Fraction Fraction::operator+(const Fraction& other) {
  auto gcd = Euclid(this->denom_, other.denom_);
  auto denom = gcd * this->denom_;
  auto numer = gcd * this->numer_ + gcd * other.numer_;
  
  return Fraction(denom, numer);
}

Fraction operator-(const Fraction& other) {
  return *this + -(other);
}

Fraction operator*(const Fraction& other) {
  auto denom = this->denom_ * other.denom_;
  auto numer = this->numer_ * other.numer_;

  return Fraction(denom, numer);
}

Fraction operator/(const Fraction& other) {
  auto denom = this->denom_ * other.numer_;
  auto numer = this->numer_ * other.denom_;

  return Fraction(denom, numer);
}

bool operator==(const Fraction& other) {
  return (this->denom_ == other.denom_ && this->numer_ == other.numer_);
}

bool operator!=(const Fraction& other) const {
  return !(*this == other);
}

bool operator<(const Fraction& other) const {
  return (float)*this < (float)other;
}

bool operator>(const Fraction& other) const {
  return (float)*this > (float)other;
}

bool operator<=(const Fraction& other) const {
  return (*this == other || *this < other);
}

bool operator>=(const Fraction& other) const {
  return (*this == other || *this > other);
}

float operator float() const {
  return (float)numer_ / denom_;
}

void reduce() {
  auto gcd = Euclid(denom_, numer_);
  denom_ /= gcd;
  numer_ /= gcd;
}

inline int Euclid(int a, int b) const {
  while((auto r = a % b) != 0) {
    a = b;
    b = r;
  }
  return b;
}
