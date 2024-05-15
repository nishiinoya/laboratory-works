module studentModule;

import std;

Student::Student() : studentID(0) {}

Student::Student(unsigned int id, const std::string &name, const std::vector<int> &gradeArray)
    : studentID(id), lastName(name), grades(gradeArray) {}

Student::Student(const Student &other)
    : studentID(other.studentID), lastName(other.lastName), grades(other.grades) {}

void Student::setStudentID(unsigned int id) {
    studentID = id;
}

unsigned int Student::getStudentID() const {
    return studentID;
}

void Student::setLastName(const std::string &name) {
    lastName = name;
}

std::string Student::getLastName() const {
    return lastName;
}

void Student::setGrades(const std::vector<int> &gradeArray) {
    grades = gradeArray;
}

std::vector<int> Student::getGrades() const {
    return grades;
}

double Student::averageGrade() const {
    double sum = 0.0;
    for (int grade : grades) {
        sum += grade;
    }
    return sum / grades.size();
}

bool Student::checkLastName() const {
    return lastName.length() > 7;
}
