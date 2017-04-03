/* student2.cpp */

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Person{
protected:
  string name;
  float height;

public:
  Person(string name, float height){
    this -> name = name;
    this -> height = height;
  }

  string getName(){
    return this -> name;
  }

  float getHeight(){
    return this -> height;
  }

  void setHeight(float height){
    if(height < 120.0)
      this -> height = 120.0;

    else if(height > 200.0)
      this -> height = 200.0;

    else
      this -> height = height;
  }

  virtual void printInformation(){
    cout << this-> name << ' ' << this -> height << endl;
  }
};

class Student: public Person{
private:
  int grade;

public:
  Student(string name, float height, int grade): Person(name, height){
    this -> grade = grade;
  }

  int getGrade(){
    return this -> grade;
  }

  void printInformation(){
    cout << this-> name << ' ' << this -> height << ' ' << this -> grade << endl;
  }
};

class Teacher: public Person
{
private:
  int income;

public:
  Teacher(string name, float height, int income): Person(name, height){
    this -> income = income;
  }

  int getIncome(){
    return income;
  }

  void setIncome(int income){
    if(income < 200)
      this -> income = 200;

    else if(income > 1000)
      this -> income = 1000;

    else
      this -> income = income;
  }

  void printInformation(){
    cout << this-> name << ' ' << this -> height << ' ' << this -> income << endl;
  }
};

int main() {
  int number_of_people;
  cout << "Please input the number of people:" << endl;
  cin >> number_of_people;

  cout << "Please input people information:" << endl;
  vector<Person*> people(number_of_people);
  for(int i = 0; i < number_of_people; ++i){
    string name;
    float height;
    int grade_or_income;

    cin >> name >> height >> grade_or_income;
    if(grade_or_income < 10)
      people[i] = new Student(name, height, grade_or_income);
    else{
      people[i] = new Teacher(name, height, grade_or_income);
      ((Teacher*)people[i])->setIncome(grade_or_income);
    }
    people[i] -> setHeight(height);
  }

  for (const auto& p : people) {
    p->printInformation();
  }

  return 0;
}
