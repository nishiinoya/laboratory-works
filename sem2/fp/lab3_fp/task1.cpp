#include <cmath>
#include <iostream>

class Point3D {
private:
    double x, y, z;

public:
    Point3D() : Point3D(0, 0, 0) {}
    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    void setZ(double z) { this->z = z; }
    
    friend double operator-(const Point3D &p1, const Point3D &p2);  
};

static double square(double x) { return x * x; }

double operator-(const Point3D &p1, const Point3D &p2) {
    return std::sqrt(square(p1.x - p2.x) + square(p1.y - p2.y) + square(p1.z - p2.z));
}

int main() {
    Point3D p1(1.2, 2, 5);
    std::cout << "Point 1: " << p1.getX() << " " << p1.getY() << " " << p1.getZ() << "\n";

    Point3D p2;
    p2.setX(4);
    p2.setY(6);
    p2.setZ(6.0);
    std::cout << "Point 2: " << p2.getX() << " " << p2.getY() << " " << p2.getZ() << "\n";

    // Calculate distance using the minus operator
    double distance1 = p1 - p2;
    std::cout << "Distance between p1 and p2: " << distance1 << "\n";

    p2.setX(3);
    p2.setY(1);
    p2.setZ(2);

    double distance2 = operator-(p1, p2);
    std::cout << "Distance between p1 and modified p2: " << distance2 << "\n";
}
