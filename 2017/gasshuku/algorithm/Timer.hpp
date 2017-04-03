#ifndef __TIMER_HPP__
#define __TIMER_HPP__

#include <chrono>
#include <string>

class Timer {
  std::chrono::steady_clock::time_point start_;
  
public:
  Timer();
  auto restart() -> void;
  auto elapsed() -> unsigned long;
};

inline void printTime(Timer timer);


Timer::Timer() {
  restart();
}

auto Timer::restart() -> void {
  start_ = std::chrono::steady_clock::now();
}

auto Timer::elapsed() -> unsigned long {
  auto now = std::chrono::steady_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(now - start_);

  return static_cast<unsigned int>(elapsed.count());
}

#endif
