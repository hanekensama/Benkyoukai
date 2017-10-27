#include <iostream>
#include <string>
#include <map>

using namespace std;

/**
 * @brief データ数に関して、ユーザの入力を受け付ける
 * @return 入力されたデータ数
 */
auto getSize() -> unsigned int;

/**
 * @brief 名前とGPに関して、ユーザの入力を受け付ける
 * @param [in] size データの数
 * @return 入力されたデータを名前をキーとしてまとめた連想配列
 */
auto getStudentsGP(unsigned int size) -> map<string, double>;

/**
 * @brief 学生の名前とGPを出力する
 * @param [in] studentsGP 名前をキー、GPを値とする連想配列
 */
auto printStudentsGP(const map<string, double>& studentsGP) -> void;


auto main() -> int {
  auto size = getSize();
  auto studentsGP = getStudentsGP(size);

  printStudentsGP(studentsGP);

  return 0;
};

auto getSize() -> unsigned int {
  unsigned int size;
  
  cout << "Please input the number:" << endl;
  cin >> size;
  
  return size;
}

auto getStudentsGP(unsigned int size) -> map<string, double> {
  map<string, double> studentsGP;
  string name;
  double gp;

  cout << "Please input student information:" << endl;
  for (unsigned int i = 0; i < size; ++i) {
    cin >> name >> gp;
    studentsGP[name] = gp;
  }

  return studentsGP;
}

auto printStudentsGP(const map<string, double>& studentsGP) -> void {
  cout << "The answer is:" << endl;
  
  for (auto student : studentsGP) {
    cout << student.first << " " << student.second << endl;
  }
}
