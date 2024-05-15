#include <iostream>

using std::cout;
using std::endl;

class ObjectSum {
private:
    int data;
    static int sum;

public:
    static int getSum() {
        return sum;
    }

    ObjectSum(int value) : data(value) {
        sum += data;
    }

    ~ObjectSum() {
        sum -= data;
    }
};

int ObjectSum::sum = 0;

int main() {
    ObjectSum c1(5);
    cout << "Sum after creating p1: " << ObjectSum::getSum() << endl; // 5

    ObjectSum *p2 = new ObjectSum(10);
    cout << "Sum after creating p2: " << p2->getSum() << endl; // 15

    delete p2;
    cout << "Sum after deleting p2: " << p2->getSum() << endl; 

    return 0;
}
