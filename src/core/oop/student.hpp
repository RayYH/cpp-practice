#ifndef CPP_PRACTICE_SRC_CORE_OOP_STUDENT_HPP_
#define CPP_PRACTICE_SRC_CORE_OOP_STUDENT_HPP_

class Student {
 public:
  double marks1_, marks2_;
  Student(double m);
  Student();
  double CalculateAverage();
};

double CalculateAverage(Student student1, Student student2);

Student CreateStudent();

#endif //CPP_PRACTICE_SRC_CORE_OOP_STUDENT_HPP_
