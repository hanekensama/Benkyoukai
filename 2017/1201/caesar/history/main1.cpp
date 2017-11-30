/**
 * @brief シーザー暗号方式で文字列の暗号化、復号を行う
 * @author hub <hub@ngc.is.ritsumei.ac.jp>
 * @date 2017.11.23
 * @details コマンドライン引数に応じて暗号化と復号を切り替える
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include "caesar.hpp"

int main(int argc, char *argv[]) {
  if (hasCorrectArgments(argc, argv)) {
    // 文字列をユーザに入力させて取得する
    std::string input;
    std::cout << "input string: ";
    std::cin >> input;

    char mode = argv[1][0];
    int key = atoi(argv[2]);
    std::string output;
    if (mode == 'e')      // 暗号化モード
      output = encrypt(input, key);

    else if (mode == 'd') // 復号モード
      output = decrypt(input, key);

    std::cout << output << std::endl;
  }
  return 0;
}
