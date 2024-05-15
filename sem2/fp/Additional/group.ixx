export module groupModule;

import std;

class Student;

export class Group {
    int groupIndex;
    std::vector<Student> students;

public:
    Group();
    Group(int index);

    void setGroupIndex(int index);
    int getGroupIndex() const;

    void addStudent(const Student &student);
    void sortByAverageGrade();
    void findLongLastNames() const;

    friend std::ostream &operator<<(std::ostream &out, const Group &group);
}
