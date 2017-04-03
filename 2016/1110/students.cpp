#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Student {
private:
  float static constexpr MIN_HEIGHT = 0.0;
  float static constexpr MAX_HEIGHT = 300.0;
  std::string name;
  float height;
  int grade;
  
public:
  Student(std::string& const name, int const grade, float const height);
  auto getName() const -> std::string;
  auto getHeight() const -> float;
  auto setHeight(float const height) -> void;
  auto getGrade() const -> int;
  auto operator<(const Student& other) const -> bool;
};

auto inputNumOfStudents()-> int;
auto inputStudents(int const num, std::vector<Student>& students) -> void;

int main() {
  auto num_students = inputNumOfStudents();
  
  std::vector<Student> students(num_students);
  inputStudents(num_students, students);

  std::sort(students.begin(), students.end());

  for (auto& s: students) std::cout << s.getName() << std::endl;
  
  return 0;
}

Student::Student
(std::string& const name, int const grade, float const height)
  : name(name), grade(grade) {
  setHeight(height);
}

auto Student::getName() const -> std::string {
  return name;
}

auto Student::getHeight() const -> float {
  return height;
}

auto Student::setHeight(float height) -> void {
  if (height < MIN_HEIGHT) this->height = MIN_HEIGHT;
  else if(height > MAX_HEIGHT) this->height = MAX_HEIGHT;
  else this->height = height;
}

auto Student::getGrade() const -> int {
  return grade;
}

auto Student::operator<(const Student& other) const -> bool{
  if (grade != other.grade) return grade < other.grade;
  else return height < other.height;
}

auto getNumOfStudents() -> int {
  std::cout << "Please input the number of students:" << std::endl;
  int input;
  std::cin >> input;
  return input;
}

auto inputStudents(int num, std::vector<Student>& students) -> void {
  std::cout << "Please input student information:" << std::endl;

  std::string name;
  int grade;
  float height;
  for (int i = 0; i < num; i++) {
    std::cin >> name >> grade >> height;
    students.push_back(Student(name, grade, height));
  }
}
