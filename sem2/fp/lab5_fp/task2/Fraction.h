#pragma once

#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction() : numerator(0), denominator(1) {} 
    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

    friend bool operator<(const Fraction &f1, const Fraction &f2) {
        return f1.numerator * f2.denominator < f2.numerator * f1.denominator;
    }

    friend ostream &operator<<(ostream &out, const Fraction &f) {
        out << f.numerator << "/" << f.denominator;
        return out;
    }
};
