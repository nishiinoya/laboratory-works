#include <algorithm>
#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

public:
    // Constructors
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int num, int denom) : numerator(num), denominator(denom) {}

    void reduce() {
        int gcd_val = gcd(abs(numerator), abs(denominator));
        numerator /= gcd_val;
        denominator /= gcd_val;
    }

    Fraction operator+(const Fraction &other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    Fraction operator-(const Fraction &other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }

    Fraction operator*(const Fraction &other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction &other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    bool operator==(const Fraction &other) const {
        return numerator * other.denominator == other.numerator * denominator;
    }

    bool operator!=(const Fraction &other) const {
        return !(*this == other);
    }

    friend std::ostream &operator<<(std::ostream &os, const Fraction &frac) {
        if (frac.denominator == 0) {
            os << "Undefined";
        } else if (frac.denominator == 1 || frac.numerator == 0) {
            os << frac.numerator;
        } else if (abs(frac.numerator) < abs(frac.denominator)) {
            os << frac.numerator << "/" << frac.denominator;
        } else {
            int whole_part = frac.numerator / frac.denominator;
            int remainder = abs(frac.numerator) % abs(frac.denominator);
            os << whole_part << " ";
            if (remainder != 0) {
                os << remainder << "/" << frac.denominator;
            }
        }
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Fraction &frac) {
        is >> frac.numerator >> frac.denominator;
        return is;
    }
};

int main() {
    Fraction frac1, frac2;

    std::cout << "Enter two fractions: ";
    std::cin >> frac1 >> frac2;


    frac1.reduce();
    frac2.reduce();

    Fraction sum = frac1 + frac2;
    Fraction difference = frac1 - frac2;
    Fraction product = frac1 * frac2;
    Fraction quotient = frac1 / frac2;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Quotient: " << quotient << std::endl;

    // Comparison
    std::cout << "Comparison: ";
    if (frac1 == frac2) {
        std::cout << "Fractions are equal";
    } else {
        std::cout << "Fractions are not equal";
    }
    std::cout << std::endl;

    return 0;
}
