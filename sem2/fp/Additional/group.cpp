module groupModule;

import std;

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
    std::sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        return a.averageGrade() > b.averageGrade();
    });
}

void Group::findLongLastNames() const {
    std::cout << "Students with last names longer than 7 letters:" << std::endl;
    for_each(students.begin(), students.end(), [](const Student &student) {
        if (student.checkLastName()) {
            std::cout << "Student ID: " << student.getStudentID() << ", Last Name: " << student.getLastName() << ", Grades:";
            for (int grade : student.getGrades()) {
                std::cout << " " << grade;
            }
            std::cout << std::endl;
        }
    });
}

std::ostream &operator<<(std::ostream &out, const Group &group) {
    out << "Group: " << group.groupIndex << std::endl;
    out << "Students:" << std::endl;
    for (const auto &student : group.students) {
        out << "Student ID: " << student.getStudentID() << ", Last Name: " << student.getLastName() << ", Grades:";
        for (int grade : student.getGrades()) {
            out << " " << grade;
        }
        out << std::endl;
    }
    return out;
}
