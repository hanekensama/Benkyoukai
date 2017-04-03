#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
  float MIN_HEIGHT;
  float MAX_HEIGHT;
  string name;
  float height;
  int grade;
public:
  Student(string name, float height, int grade)
    : name(name), grade(grade) {
    MIN_HEIGHT = 120.0;
    MAX_HEIGHT = 200.0;
    setHeight(height);
  }
  string getName() { return name; }
  float getHeight() { return height; }
  void setHeight(float height) {
    if (height < MIN_HEIGHT) this->height = MIN_HEIGHT;
    else if(height > MAX_HEIGHT) this->height = MAX_HEIGHT;
    else this->height = height;
  }
  int getGrade() {return grade;}
};

int main() {
  vector<Student> students;
  string name;
  float height;
  int grade;
  while(true) {
    cin >> name >> grade >> height;
    if (grade == 0) break;
    else students.push_back(Student(name, height, grade));
  }
  for(auto s: students) {
    cout << s.getName() << ":"
	 << s.getHeight() << ":"
	 << s.getGrade() << endl;
  }
  return 0;
  new Student();
}
