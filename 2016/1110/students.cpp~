#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Student {
private:
  static constexpr float MIN_HEIGHT = 0.0;
  static constexpr float MAX_HEIGHT = 300.0;
  std::string name;
  float height;
  int grade;
  
public:
  Student(std::string name, int grade, float height);
  std::string getName();
  float getHeight();
  void setHeight(float height);
  int getGrade();
  bool operator<(const Student& other) const;
};

int inputNumOfStudents();
void inputStudents(int num, std::vector<Student>& students);

int main() {
  int num_students = inputNumOfStudents();
  
  std::vector<Student> students(num_students);
  inputStudents(num_students, students);

  std::sort(students.begin(), students.end());

  for (auto& s: students) std::cout << s.getName() << std::endl;
  
  return 0;
}

Student::Student(std::string name, int grade, float height)
  : name(name), grade(grade) {
  setHeight(height);
}

std::string Student::getName() {
  return name;
}

float Student::getHeight() {
  return height;
}

void Student::setHeight(float height) {
  if (height < MIN_HEIGHT) this->height = MIN_HEIGHT;
  else if(height > MAX_HEIGHT) this->height = MAX_HEIGHT;
  else this->height = height;
}

int Student::getGrade() {
  return grade;
}

bool Student::operator<(const Student& other) const {
  if (grade != other.grade) return grade < other.grade;
  else return height < other.height;
}

int getNumOfStudents() {
  std::cout << "Please input the number of students:" << std::endl;
  int input;
  std::cin >> input;
  return input;
}

void inputStudents(int num, std::vector<Student>& students) {
  std::cout << "Please input student information:" << std::endl;

  std::string name;
  int grade;
  float height;
  for (int i = 0; i < num; i++) {
    std::cin >> name >> grade >> height;
    students.push_back(Student(name, grade, height));
  }
}
