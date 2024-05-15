#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Student {
    unsigned int studentID;
    string lastName;
    vector<int> grades;

public:
    Student() : studentID(0) {}
    Student(unsigned int id, const string &name, const vector<int> &gradeArray);
    Student(const Student &other);

    void setStudentID(unsigned int id);
    unsigned int getStudentID() const;
    void setLastName(const string &name);
    string getLastName() const;
    void setGrades(const vector<int> &gradeArray);
    vector<int> getGrades() const;

    double averageGrade() const;
    bool checkLastName() const;
};

Student::Student(unsigned int id, const string &name, const vector<int> &gradeArray)
    : studentID(id), lastName(name), grades(gradeArray) {}

Student::Student(const Student &other)
    : studentID(other.studentID), lastName(other.lastName), grades(other.grades) {}

void Student::setStudentID(unsigned int id) {
    studentID = id;
}

unsigned int Student::getStudentID() const {
    return studentID;
}

void Student::setLastName(const string &name) {
    lastName = name;
}

string Student::getLastName() const {
    return lastName;
}

void Student::setGrades(const vector<int> &gradeArray) {
    grades = gradeArray;
}

vector<int> Student::getGrades() const {
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

class Group {
    int groupIndex;
    vector<Student> students;

public:
    Group() : groupIndex(0) {}
    Group(int index) : groupIndex(index) {}

    void setGroupIndex(int index);
    int getGroupIndex() const;

    void addStudent(const Student &student);
    void sortByAverageGrade();
    void findLongLastNames() const;

    friend ostream &operator<<(ostream &out, const Group &group);
};

void Group::setGroupIndex(int index) {
    groupIndex = index;
}

int Group::getGroupIndex() const {
    return groupIndex;
}

void Group::addStudent(const Student &student) {
    students.push_back(student);
}

void Group::sortByAverageGrade() {
    sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        return a.averageGrade() > b.averageGrade();
    });
}

void Group::findLongLastNames() const {
    cout << "Students with last names longer than 7 letters:" << endl;
    for_each(students.begin(), students.end(), [](const Student &student) {
        if (student.checkLastName()) {
            cout << "Student ID: " << student.getStudentID() << ", Last Name: " << student.getLastName() << ", Grades:";
            for (int grade : student.getGrades()) {
                cout << " " << grade;
            }
            cout << endl;
        }
    });
}

ostream &operator<<(ostream &out, const Group &group) {
    out << "Group: " << group.groupIndex << endl;
    out << "Students:" << endl;
    for (const auto &student : group.students) {
        out << "Student ID: " << student.getStudentID() << ", Last Name: " << student.getLastName() << ", Grades:";
        for (int grade : student.getGrades()) {
            out << " " << grade;
        }
        out << endl;
    }
    return out;
}

class CompareStudents {
public:
    bool operator()(const Student &a, const Student &b) const {
        return a.averageGrade() < b.averageGrade();
    }
};

int main() {
    vector<int> grades1 = {80, 75, 90, 85, 88};
    vector<int> grades2 = {70, 90, 97, 80, 78};
    vector<int> grades3 = {85, 90, 88, 92, 85};
    vector<int> grades4 = {75, 80, 82, 78, 85};

    Student st1(1, "Smith", grades1);
    Student st2(2, "Oleksandrovysch", grades2);
    Student st3(3, "Robbie", grades3);
    Student st4(4, "Vebderwoodsen", grades4);

    Group group(1);
    group.addStudent(st1);
    group.addStudent(st2);
    group.addStudent(st3);
    group.addStudent(st4);

    cout << "Original Group:" << endl;
    cout << group << endl;

    group.sortByAverageGrade();
    cout << "Sorted by average grade:" << endl;
    cout << group << endl;

    group.findLongLastNames();

    priority_queue<Student, vector<Student>, CompareStudents> pq;
    pq.push(st1);
    pq.push(st2);
    pq.push(st3);
    pq.push(st4);

    cout << "Students sorted by average score (descending):" << endl;
    while (!pq.empty()) {
        const Student &student = pq.top();
        cout << "Student ID: " << student.getStudentID() << ", Last Name: " << student.getLastName() << ", Grades:";
        for (int grade : student.getGrades()) {
            cout << " " << grade;
        }
        cout << endl;
        pq.pop();
    }

    return 0;
}
