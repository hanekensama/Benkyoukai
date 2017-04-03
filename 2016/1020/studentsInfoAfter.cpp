#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

typedef struct student {
  std::string name;
  float height;
}student_t;

int inputNum(std::string prompt) {
  std::cout << prompt;
  int input;
  cin >> input;
  return input;
}

int inputInfo(student_t* student) {
  std::string name;
  int grade;
  float height;
  std::cin >> name >> grade >> height;
  
  return grade;
}

void inputStudents(std::vector<student_t> &v, int num) {
  std::cout << "Please input student information:" << std::endl;
  
  for (int i = 0; i < num; i++) v.push_back(inputStudent());
}

bool compareHeight(const student_t& lhs, const student_t& rhs) {
  return lhs.height < rhs.height;
}

int main() {
  int num_students = inputNum("Please input the number of students:\n");

  std::vector<student_t> students[3];
  inputStudents(students, num_students);

  int grade = inputNum("Please input the school year:\n");

  float median = getMedian(students[grade]);
  std::cout << median << std::endl;

  return 0;
}
