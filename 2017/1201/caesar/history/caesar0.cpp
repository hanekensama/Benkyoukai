#include "caesar.hpp"

/**
 * @brief シーザー暗号の暗号化、復号に関わる関数群の実装
 * @author hub <hub@ngc.is.ritsumei.ac.jp>
 * @date 2017.11.23
 */

bool checkArgments(int argc, char *argv[]) {
  // if 引数の数が三つ（一つ目はコマンド名）
  //    if 二つ目の引数が'e'か'd'
  //       if 三つ目の引数が整数に変換可能
  //          trueを返す
  //       Endif
  //    Endif
  // Endif
  // falseを返す
}

std::string encrypt(std::string raw, int key) {
  // 結果を格納する空の文字列を用意する
  // for rawに含まれる全ての文字
  //   文字にkeyを加える
  //   文字を結果の文字列に追加する
  // Endfor
  // 結果の文字列を返す
}

// decryptはencryptの逆操作なので正負反転したkeyで暗号化しても同じ結果が得られる
std::string decrypt(std::string encrypted, int key) {
  // key の正負を反転する
  // 反転したkeyで暗号化した文字列を返す
}
