#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief データ数に関して、ユーザの入力を受け付ける
 * @return 入力されたデータ数
 */
auto getSize() -> unsigned int;

/**
 * @brief ユーザからの複数の整数の入力を受け付ける
 * @param [in] size データの数
 * @return 入力されたデータが格納されたvector
 */
auto getVector(unsigned int size) -> vector<int>;

/**
 * @brief vectorの中身を順に出力する
 * @param [in] v 出力したいvector
 */
auto printVector(const vector<int>& v) -> void;

auto main() -> int {
  auto size = getSize();
  auto numbers = getVector(size);

  sort(numbers.begin(), numbers.end());
  printVector(numbers);
  
  return 0;
}

auto getSize() -> unsigned int {
  unsigned int size;
  
  cout << "Please input the number: " << endl;
  cin >> size;
  
  return size;
}

auto getVector(unsigned int size) -> vector<int> {
  vector<int> numbers(size);
  
  cout << "Please input numbers: " << endl;
  for (unsigned int i = 0; i < size; ++i) {
    cin >> numbers[i];
  }

  return numbers;
}

auto printVector(const vector<int>& v) -> void {
  cout << "The answer is: " << endl;
  
  for (auto& i : v) {
    cout << i << " ";
  }

  cout << endl;
}
