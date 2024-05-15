#include <cmath>
#include <iostream>

struct Point {
    double x, y, z;
};

double square(double x) {
    return x * x;
}

double distance(Point p1, Point p2) {
    return std::sqrt(square(p1.x - p2.x) + square(p1.y - p2.y) + square(p1.z - p2.z));
}

int main() {
    Point p1 = {1.0, 2.6, 8.0};
    Point p2 = {4.0, 6.0, 5.0};
    std::cout << "Distance: " << distance(p1, p2) << std:: endl;
    return 0;
}
