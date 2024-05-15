#include <iostream>
#include <cstring>

struct Student {
    unsigned int number;
    char name[30];
    int notes[5];
};

void print_student(const Student* st) {
    std::cout << "Number: " << st->number << ", Name: " << st->name << ", Grades: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << st->notes[i] << " ";
    }
    std::cout << std::endl;
}


//buble sort
void sort_grade(Student **arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            int sum_a = 0, sum_b = 0;
            for (int k = 0; k < 5; ++k) {
                sum_a += arr[j]->notes[k];
                sum_b += arr[j + 1]->notes[k];
            }
            if (sum_a > sum_b) {
                Student *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void print_students(Student **st, int len);
void condition(Student **arr, int size) {
    std::cout << "Students with name larger than 7 letters:" << std::endl;
    for (int i = 0; i < size; ++i) {
        if (strlen(arr[i]->name) > 7) {
            print_student(arr[i]);
        }
    }
}

int main() {
    const int n = 4;
    Student st[n] = {
        {1, "Adamenko", {80, 75, 90, 85, 88}},
        {2, "Malanchuk", {70, 90, 97, 80, 78}},
        {3, "Pred", {85, 90, 88, 92, 85}},
        {4, "Kharchenko", {75, 80, 82, 78, 85}}
    };

    Student* pointers[n];
    for (int i = 0; i < n; ++i) {
        pointers[i] = &st[i];
    }

    std::cout << "Original list:" << std::endl;
    print_students(pointers, n);

    sort_grade(pointers, n);
    std::cout << "\nSorted by average grade:" << std::endl;
    print_students(pointers, n);

    std::cout << std::endl;

    condition(pointers, n);

    return 0;
}
void print_students(Student **st, int len) {
    std::cout << "Students:" << std::endl;
    for (int i = 0; i < len; ++i) {
        print_student(st[i]);
    }
}