module StudentModule;

import std;

class Group: 

export class Student {
    unsigned int id;
    std::string surname;
    std::vector<int> grades;
    Group *group;

public:
    // Constructors
    Student(unsigned int id, const std::string &surname, const std::vector<int> &grades, Group *group);
    Student(const Student &other);
    Student() : id(0), surname(""), grades(std::vector<int>()), group(nullptr) {}

    // Setters
    void setId(unsigned int id);
    void setSurname(const std::string &surname);
    void setGrades(const std::vector<int> &grades);
    void setGroup(Group *group);

    // Getters
    unsigned int getId() const;
    const std::string &getSurname() const;
    const std::vector<int> &getGrades() const;
    Group *getGroup() const;
    int getAverageGrade() const;


    // Friend functions
    friend std::ostream &operator<<(std::ostream &os, const Student &student);
    friend bool operator<(const Student &s1, const Student &s2);
};
