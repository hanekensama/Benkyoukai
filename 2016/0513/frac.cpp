struct frac{
  int bunshi, bunbo;
  
  int gcd(int a, int b) {
    if(b == 0) return a;
    else gcd(b, a % b);
  }

  frac(int a, int b) {
    bunshi = a;
    bunbo = b;
  }
  void reduce() {
    bunshi /= gcd(bunshi, bunbo);
    bunbo /= gcd(bunshi, bunbo);
  }
  double val() const{
    return bunshi / bunbo;
  }
  frac operator+ (const frac& o) const {
    int n_bunshi = bunshi*o.bunbo + o.bunshi * bunbo;
    int n_bunbo = bunbo * o.bunbo;
    frac f(n_bunshi, n_bunbo);
    f.reduce();
    return f;
  };
  
  frac operator- (const frac& o) const {
    int n_bunshi = bunshi * o.bunbo - o.bunshi * bunbo;
    int n_bunbo = bunbo * o.bunbo;
    frac f(n_bunshi, n_bunbo);
    f.reduce();
    return f;
  };
  frac operator* (const frac& o) const {
    frac f(bunshi * o.bunshi, bunbo * o.bunbo);
    f.reduce();
    return f;
  };
  
  frac operator/ (const frac& o) const {
    frac f(bunshi * o.bunbo, bunbo * o.bunshi);
    f.reduce();
    return f;
  }

  bool operator< (const frac& o) const {
    return val() < o.val();
  }
  bool operator> (const frac& o) const {
    return val() > o.val();
  }
  bool operator<= (const frac& o) const {
    return !(*this>o);
  }
  bool operator>= (const frac& o) const {
    return !(*this<o);
  }
};
