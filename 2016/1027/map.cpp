#include <iostream>
#include <map>
#include <string>

int main() {
  std::map<std::string, int> ages;
  ages["taro"] = 12;
  ages["hanako"] = 15;
  std::cout << ages["taro"] << std::endl
	    << ages["nanko"] << std::endl;

  return 0;
}
