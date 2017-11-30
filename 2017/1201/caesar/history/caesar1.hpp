/**
 * @brief シーザー暗号の暗号化、復号に関わる関数群の定義
 * @author hub <hub@ngc.is.ritsumei.ac.jp>
 * @date 2017.11.23
 */

#pragma once
#include <string>

/**
 * @brief コマンドライン引数をチェックする関数
 * @param [in] argc コマンドライン引数の数
 * @param [in] argv コマンドライン引数の数
 * @return bool コマンドライン引数が正しいかどうか
 * @retval true コマンドライン引数が正しい
 * @retval false コマンドライン引数が正しくない
 */
bool hasCorrectArgments(int argc, char *argv[]);

/**
 * @brief 文字列を暗号化する関数
 * @param[in] raw 元の文字列
 * @param[in] key 鍵
 * @return std::string 暗号化された文字列
 */
std::string encrypt(std::string raw, int key);

/**
 * @brief 文字列を復号する関数
 * @param[in] encrypted 暗号化された文字列
 * @param[in] key 鍵
 * @return std::string 複合された文字列
 */
std::string decrypt(std::string encrypted, int key);

/**
 * @brief 文字列が全て数字かどうか調べる関数
 * @param[in] str チェックする文字列
 * @return bool 全て数字ならtrue, さもなくばfalse
*/
bool isAllDigit(const char* str);
