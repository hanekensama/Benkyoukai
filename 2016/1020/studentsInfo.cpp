#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

typedef struct student {
  std::string name;
  int grade;
  float height;
}student_t;

bool CompareHeight(const student_t& lhs, const student_t& rhs) {
  return lhs.height < rhs.height;
}

int GetNumStudents() {
  int input;
  std::cout << "Please input the number of students:" << std::endl;
  std::cin >> input;
  return input;
}

student_t GetStudent() {
  student_t student;
  std::cout << "Please input student information:" << std::endl;
  std::cin >> student.name >> student.grade >> student.height;
  return student;
}

int main() {
  int num_students = GetNumStudents();
  std::vector<student_t> students;
  for (int i = 0; i < num_students; i++) {
    students.push_back(GetStudent());
  }
  std::sort(students.begin(), students.end(), CompareHeight);

  std::cout << students.back().height << std::endl;

  return 0;
}
