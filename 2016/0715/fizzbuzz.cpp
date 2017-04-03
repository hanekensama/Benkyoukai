#include <iostream>
#include <string>
#include <functional>

std::function<std::string(void)> makeFizzBuzz(int a = 3, int b = 5) {
  int n = 0;
  return [=] () mutable {
    n++;
    std::string str = "";
    if (n % a == 0) str += "Fizz";
    if (n % b == 0) str += "Buzz";
    return (str != "") ? str : std::to_string(n); 
  };
}


int main() {
  auto fizzbuzz = makeFizzBuzz(4,6);
  for (int i = 1; i <= 15; i++) {
    std::cout << fizzbuzz() << ',';
  }
  std::cout << std::endl;
  return 0;
}
