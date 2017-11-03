#include <iostream>
#include <string>

/**
 * @brief 3次元ベクトルを表現するクラス
 */
class three_d {
private:
  int x, y, z;

public:
  /**
   * @brief デフォルトコンストラクタ
   */
  three_d ();

  /**
   * @brief コンストラクタ
   * @param [in] i x座標の値
   * @param [in] j y座標の値
   * @param [in] k z座標の値
   */
  three_d (int i, int j, int k);

  /**
   * @brief 各座標の値を取得する
   * @param [out] i x座標を格納する変数
   * @param [out] j y座標を格納する変数
   * @param [out] k z座標を格納する変数
   */
  void get(int &i, int& j, int& k) const;

  /**
   * @brief 3次元ベクトルの加算
   * @param [in] rhs 右辺値
   * @return 3次元ベクトルの和
   */
  three_d operator+(const three_d& other) const;

  /**
   * @brief 3次元ベクトルの減算
   * @param [in] rhs 右辺値
   * @return 3次元ベクトルの差
   */
  three_d operator-(const three_d& other) const;

  /**
   * @brief 前置インクリメント
   * @detail 各座標の値を全て1ずつ増やす
   * @return 自分自身
   */
  three_d& operator++();

  /**
   * @brief 後置インクリメント
   * @detail 各座標の値を全て1ずつ増やす
   * @return 自分自身
   */
  three_d operator++(int notused);

  /**
   * @brief 前置デクリメント
   * @detail 各座標の値を全て1ずつ減らす
   * @return 自分自身
   */
  three_d& operator--();

  /**
   * @brief 後置デクリメント
   * @detail 各座標の値を全て1ずつ減らす
   * @return 自分自身
   */
  three_d operator--(int notused);

  /**
   * @brief ベクトルの状態を表す文字列を返す
   * @return ベクトルの状態を表す文字列
   */
  std::string toString() const;
};

std::ostream& operator<<(std::ostream& os, const three_d& obj);


three_d::three_d() :x(0), y(0), z(0) {};

three_d::three_d(int i, int j, int k) :x(i), y(j), z(k) {};

void three_d::get(int& i, int& j, int& k) const {
  i = x;
  j = y;
  k = z;
}

three_d three_d::operator+(const three_d& other) const {
  auto sum_x = x + other.x;
  auto sum_y = y + other.y;
  auto sum_z = z + other.z;

  return (three_d(sum_x, sum_y, sum_z));
}

three_d three_d::operator-(const three_d& other) const {
  auto differ_x = x - other.x;
  auto differ_y = y - other.y;
  auto differ_z = z - other.z;

  return (three_d(differ_x, differ_y, differ_z));
}

three_d& three_d::operator++() {
  x++;
  y++;
  z++;

  return *this;
}

three_d three_d::operator++(int notused) {
  auto copy = *this;
  x++;
  y++;
  z++;

  return copy;
}

three_d& three_d::operator--() {
  x--;
  y--;
  z--;

  return *this;
}

three_d three_d::operator--(int notused) {
  auto copy = *this;
  
  x--;
  y--;
  z--;

  return copy;
}

std::string three_d::toString() const {
  std::string str ="("
    + std::to_string(x) + ", "
    + std::to_string(y) + ", "
    + std::to_string(z) + ")";

  return str;
}

std::ostream& operator<<(std::ostream& os, const three_d& obj) {
  os << obj.toString();
  return os;
}
