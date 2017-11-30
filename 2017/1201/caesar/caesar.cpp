#include <cctype>
#include "caesar.hpp"

/**
 * @brief シーザー暗号の暗号化、復号に関わる関数群の実装
 * @author hub <hub@ngc.is.ritsumei.ac.jp>
 * @date 2017.11.23
 */

bool hasCorrectArgments(int argc, char *argv[]) {
  if (argc == 3) { // １つめはコマンド名なので引数は三つ必要
    char mode = argv[1][0];
    if (mode == 'e' || mode == 'd') {
      char *key = argv[2];
      if (isAllDigit(key)) {
        return true;
      }
    }
  }
  return false;
}


std::string encrypt(std::string raw, int key) {
  std::string encrypted;

  for (auto c : raw) {
    encrypted.push_back(c + key);
  }

  return encrypted;
}


// decryptはencryptの逆操作なので正負反転したkeyで暗号化しても同じ結果が得られる
std::string decrypt(std::string encrypted, int key) {
  return encrypt(encrypted, - key);
}


bool isAllDigit(const char* str) {
  char c = str[0];
  int i = 0;
  
  while(c != '\n' && c != '\0' ) {
    if (!isdigit(c)) return false;
    c = str[i++];
  }
  return true;
}
