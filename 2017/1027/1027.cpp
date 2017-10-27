#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

auto getSize() -> unsigned int;
auto getVector(unsigned int size) -> vector<int>;
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
