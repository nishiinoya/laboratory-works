#include <cstring>
#include <iostream>
using std::cout;
using std::strcpy;
class Human {
private:
    char name[30];
    int age;

public:
    Human(const char *name, int age) : age(age) {
        strcpy(this->name, name);
    }

    virtual void display() const {
        cout << "Name: " << name << ", Age: " << age;
    }

    virtual ~Human() {}
};

class Citizen : public Human {
private:
    char nationality[30];

public:
    Citizen(const char *name, int age, const char *nationality) : Human(name, age) {
        strcpy(this->nationality, nationality);
    }

    void display() const override {
        Human::display();
        cout << ", Nationality: " << nationality;
    }
};

class Student : public Citizen {
private:
    int studentID;

public:
    Student(const char *name, int age, const char *nationality, int studentID) : Citizen(name, age, nationality), studentID(studentID) {}

    void display() const override {
        Citizen::display();
       cout << ", Student ID: " << studentID;
    }
};

class Employee : public Citizen {
private:
    char department[30];

public:
    Employee(const char *name, int age, const char *nationality, const char *department) : Citizen(name, age, nationality) {
       strcpy(this->department, department);
    }

    void display() const override {
        Citizen::display();
        cout << ", Department: " << department;
    }
};

int main() {
    const int n = 4;
    Human *people[n] = {
        new Citizen("Vlad", 30, "Ukrainian"),
        new Student("Oleksandr", 20, "Ukrainian", 12345),
        new Employee("Marko", 35, "British", "Engineering"),
        new Student("Jaroslav", 22, "French", 67890)};

    for (int i = 0; i < n; ++i) {
        people[i]->display();
        cout << std::endl;
    }

    for (int i = 0; i < n; ++i) {
        delete people[i];
    }

    return 0;
}
