/**
 * @file main.cpp
 * @brief 数当てゲームのメインの関数
 * @author hub <hub@ngc.is.ritsumei.ac.jp>
 * @date 2017.12.01
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <random>

const static int ANSWER_DIGIT = 4;
const static int TURN_MAX = 5;
/**
 * @brief 答えとなる4桁の数を表す配列を生成する関数
 * @return 答えとなる4桁の数を表す配列
 */
auto generateAnswer() -> std::vector<int>;

/**
 * @brief HitとBlowをチェックする関数
 * @param[in] input ユーザが答えた数字
 * @param[in] answer 答えとなる数を表す配列
 * @return hit数とblow数のペア
 */
auto countHitAndBlow(int input, const std::vector<int>& answer)
  -> std::pair<int, int>;

/**
 * @brief 答えとなる4桁の数を表す配列をint型に変換する関数
 * @param[in] answer 変換したい配列
 * @return 変換された数
 */
auto answer2int(const std::vector<int>& answer) -> int;

int main() {
  auto answer = generateAnswer();
  std::cerr << "The answer is " << answer2int(answer) << std::endl;

  for (int i = 0; i < TURN_MAX; ++i) {
    int input;
    std::cout << "[" << i << "] input number: ";
    std::cin >> input;

    auto hit_blow = countHitAndBlow(input, answer);
    std::cout << hit_blow.first << "Hit " << hit_blow.second << "Blow" << std::endl;
    if (hit_blow.first == ANSWER_DIGIT) {
      std::cout << "Yow Win!" << std::endl;
      return 0;
    }
  }
  std::cout << "You Lose. The answer is " << answer2int(answer) << std::endl;
  return 0;
}

auto generateAnswer() -> std::vector<int> {
  std::vector<int> answer(10, 0);
  std::random_device rand;

  answer[(rand() % 9) + 1] = 1;

  for (int i = 2; i <= ANSWER_DIGIT; ++i) {
    int random = rand() % 10;
    if (answer[random] == 0)
      answer[random] = i;
    else
      i--;
  }
  
  return answer;
}

auto countHitAndBlow(int input, const std::vector<int>& answer)
  -> std::pair<int, int> {
  int hit = 0, blow = 0;

  for (int i = ANSWER_DIGIT; i > 0; --i) {
    int check_num = input % 10;
    if (answer[check_num] == i)
      hit++;
    else if (answer[check_num] > 0)
      blow++;
    input /= 10;
  }

  return std::make_pair(hit, blow);
}

auto answer2int(const std::vector<int>& answer) -> int{
  int result = 0;

  for (int i = 1; i <= ANSWER_DIGIT; ++i) {
    result *= 10;
    for (int j = 0; j < 10; ++j) {
      if (answer[j] == i)
        result += j;
    }
  }

  return result;
}
