import studentModule;
import groupModule;

import std;


int main() {
    // Grades for students
    vector<int> grades1 = {80, 75, 90, 85, 88};
    vector<int> grades2 = {70, 90, 97, 80, 78};
    vector<int> grades3 = {85, 90, 88, 92, 85};
    vector<int> grades4 = {75, 80, 82, 78, 85};

    // Create students
    Student st1(1, "Smith", grades1);
    Student st2(2, "Brown", grades2);
    Student st3(3, "Dou", grades3);
    Student st4(4, "Jones", grades4);

    // Create a group and add students
    Group group(1);
    group.addStudent(st1);
    group.addStudent(st2);
    group.addStudent(st3);
    group.addStudent(st4);

    // Display original group
    cout << "Original Group:" << endl;
    cout << group << endl;

    // Sort group by average grade
    group.sortByAverageGrade();
    cout << "Sorted by average grade:" << endl;
    cout << group << endl;

    // Find students with long last names
    group.findLongLastNames();

    return 0;
}
