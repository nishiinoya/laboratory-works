#define GRADE_COUNT 5
#include <cstring>
#include <iostream>

const int MAX_STUDENTS = 50;
class Student;

class Group {
    int groupIndex;
    Student *students[MAX_STUDENTS];
    int studentCount;

public:
    Group() : groupIndex(0), studentCount(0) {}
    Group(int index) : groupIndex(index), studentCount(0) {}
    Group(const Group &other);

    void setGroupIndex(int index);
    int getGroupIndex() const;

    void addStudent(Student *student);
    void sortByAverageGrade();
    void findLongLastNames() const;

    Student *operator[](int index) const;

    Group &operator=(const Group &other);
    friend std::ostream &operator<<(std::ostream &out, const Group &group);
};

class Student {
    unsigned int studentID;
    char *lastName;
    int *grades;
    Group *group;

public:
    Student() : studentID(0), lastName(nullptr), grades(nullptr), group(nullptr) {}
    Student(unsigned int id, const char *name, const int *gradeArray, Group *grp);
    Student(const Student &other);
    ~Student();

    void setStudentID(unsigned int id);
    unsigned int getStudentID() const;

    void setLastName(const char *name);
    const char *getLastName() const;

    void setGrades(const int *gradeArray);
    const int *getGrades() const;

    void setGroup(Group *grp);
    Group *getGroup() const;

    Student &operator=(const Student &other);
    friend std::ostream &operator<<(std::ostream &out, const Student &student);
};

Student::Student(unsigned int id, const char *name, const int *gradeArray, Group *grp)
    : studentID(id), group(grp) {
    lastName = new char[strlen(name) + 1];
    strcpy(lastName, name);
    grades = new int[GRADE_COUNT];
    for (int i = 0; i < GRADE_COUNT; ++i) {
        grades[i] = gradeArray[i];
    }
}

Student::Student(const Student &other) {
    studentID = other.studentID;
    lastName = new char[strlen(other.lastName) + 1];
    strcpy(lastName, other.lastName);
    grades = new int[GRADE_COUNT];
    for (int i = 0; i < GRADE_COUNT; ++i) {
        grades[i] = other.grades[i];
    }
    group = other.group;
}

Student::~Student() {
    delete[] lastName;
    delete[] grades;
}

void Student::setStudentID(unsigned int id) {
    studentID = id;
}

unsigned int Student::getStudentID() const {
    return studentID;
}

void Student::setLastName(const char *name) {
    delete[] lastName;
    lastName = new char[strlen(name) + 1];
    strcpy(lastName, name);
}

const char *Student::getLastName() const {
    return lastName;
}

void Student::setGrades(const int *gradeArray) {
    delete[] grades;
    grades = new int[GRADE_COUNT];
    for (int i = 0; i < GRADE_COUNT; ++i) {
        grades[i] = gradeArray[i];
    }
}

const int *Student::getGrades() const {
    return grades;
}

void Student::setGroup(Group *grp) {
    group = grp;
}

Group *Student::getGroup() const {
    return group;
}

Student &Student::operator=(const Student &other) {
    if (this != &other) {
        studentID = other.studentID;
        delete[] lastName;
        lastName = new char[strlen(other.lastName) + 1];
        strcpy(lastName, other.lastName);
        delete[] grades;
        grades = new int[GRADE_COUNT];
        for (int i = 0; i < GRADE_COUNT; ++i) {
            grades[i] = other.grades[i];
        }
        group = other.group;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Student &student) {
    out << "Student ID: " << student.studentID << ", Last Name: " << student.lastName << ", Grades: ";
    for (int i = 0; i < GRADE_COUNT; ++i) {
        out << student.grades[i] << " ";
    }
    return out;
}

Group::Group(const Group &other) {
    groupIndex = other.groupIndex;
    studentCount = other.studentCount;
    for (int i = 0; i < studentCount; ++i) {
        students[i] = new Student(*(other.students[i]));
    }
}

void Group::setGroupIndex(int index) {
    groupIndex = index;
}

int Group::getGroupIndex() const {
    return groupIndex;
}

void Group::addStudent(Student *student) {
    if (studentCount < MAX_STUDENTS) {
        students[studentCount++] = student;
    }
}

void Group::sortByAverageGrade() {
    // Bubble sort
    for (int i = 0; i < studentCount - 1; ++i) {
        for (int j = 0; j < studentCount - i - 1; ++j) {
            double sum_a = 0, sum_b = 0;
            const int *grades_a = students[j]->getGrades();
            const int *grades_b = students[j + 1]->getGrades();
            for (int k = 0; k < GRADE_COUNT; ++k) {
                sum_a += grades_a[k];
                sum_b += grades_b[k];
            }
            double avg_a = sum_a / GRADE_COUNT;
            double avg_b = sum_b / GRADE_COUNT;

            if (avg_a > avg_b) {
                Student *temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void Group::findLongLastNames() const {
    std::cout << "Students with last names longer than 7 letters:" << std::endl;
    for (int i = 0; i < studentCount; ++i) {
        if (strlen(students[i]->getLastName()) > 7) {
            std::cout << *students[i] << std::endl;
        }
    }
}

Student *Group::operator[](int index) const {
    if (index >= 0 && index < studentCount) {
        return students[index];
    }
    return nullptr;
}

Group &Group::operator=(const Group &other) {
    if (this != &other) {
        groupIndex = other.groupIndex;
        studentCount = other.studentCount;
        for (int i = 0; i < studentCount; ++i) {
            delete students[i];
            students[i] = new Student(*(other.students[i]));
        }
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Group &group) {
    out << "Group: " << group.groupIndex << std::endl;
    out << "Students:" << std::endl;
    for (int i = 0; i < group.studentCount; ++i) {
        out << *group.students[i] << std::endl;
    }
    return out;
}

int main() {
    Student st1(1, "Smith", new int[GRADE_COUNT]{80, 75, 90, 85, 88}, nullptr);
    Student st2(2, "Oleksandrovysch", new int[GRADE_COUNT]{70, 90, 97, 80, 78}, nullptr);
    Student st3(3, "Robbie", new int[GRADE_COUNT]{85, 90, 88, 92, 85}, nullptr);
    Student st4(4, "Vebderwoodsen", new int[GRADE_COUNT]{75, 80, 82, 78, 85}, nullptr);

    Group group(1);
    group.addStudent(&st1);
    group.addStudent(&st2);
    group.addStudent(&st3);
    group.addStudent(&st4);

    std::cout << "Original Group:" << std::endl;
    std::cout << group << std::endl;

    group.sortByAverageGrade();
    std::cout << "Sorted by average grade:" << std::endl;
    std::cout << group << std::endl;

    group.findLongLastNames();

    return 0;
}
