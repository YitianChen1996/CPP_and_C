#include <iostream>
using namespace std;

#include "Fraction.h"

Fraction::Fraction() {
    cout << "Called default constructor" << endl;
    numerator = 1;
    denominator = 1;
}

Fraction::Fraction(const Fraction &f2) {
    cout << "Called copy constructor" << endl;
    numerator = f2.numerator;
    denominator = f2.denominator;
}

Fraction::Fraction (int num, int denom) {
    cout << "Called value constructor" << endl;

    numerator = num;
    denominator = denom;
    sanityCheck();
}

void Fraction::assignValue (int num, int denom) {
    numerator = num;
    denominator = denom;
    sanityCheck();
}

void Fraction::readValueFor () {
    cout << "Enter the numerator: ";
    cin >> numerator;
    cout << "Enter the denominator: ";
    cin >> denominator;
    sanityCheck();
    reduce();
}

void Fraction::writeValueOf () const {
    cout << numerator << "/" << denominator;
}

Fraction Fraction::add (Fraction &f) const {
    Fraction result;
    result.numerator = numerator * f.denominator +
                       denominator * f.numerator;
    result.denominator = denominator * f.denominator;

    // you can access private data members of Fraction inside Fraction methods
    result.reduce ();
    return result;
}

Fraction::~Fraction() {
    // nothing to do in the destructor
}

bool Fraction::equal (Fraction &f) {
    // Side effect: Causes f to be reduced.
    reduce();
    f.reduce();
    return ((numerator == f.numerator) && (denominator == f.denominator));
}

int greatestCommonDivisor(int i1, int i2)
{
    if (i1 == 0)
        return i2;
    return greatestCommonDivisor((i2%i1), i1);
}

void Fraction::reduce () {
    int gcd = greatestCommonDivisor(numerator,denominator);
    numerator /= gcd;
    denominator /= gcd;
}

void Fraction::sanityCheck () {
    if (denominator == 0) {
        cout << "Tried to make a fraction with a zero in the denominator." << endl;
        cout << "Setting fraction to 1/1 instead." << endl;
        numerator = denominator = 1;
    }
}

// assignment operator (=) as member function (1 arg)
Fraction& Fraction::operator=(const Fraction& rightFraction) {
    cout << "Called assignment operator." << endl;
    numerator = rightFraction.numerator;
    denominator = rightFraction.denominator;
    return (*this);
}

// binary operator (+) as member function (1 arg)
Fraction Fraction::operator+(const Fraction& rightFraction) const {
    Fraction f;

    f.numerator = (this->numerator * rightFraction.denominator) +
                  (rightFraction.numerator * this->denominator);
    f.denominator = this->denominator * rightFraction.denominator;
    f.reduce();

    return f;
}

// binary operator (-) as a friend function (2 args)
Fraction operator-(const Fraction& leftFraction,
                   const Fraction& rightFraction) {
    Fraction f;

    f.numerator = (leftFraction.numerator * rightFraction.denominator) -
                  (rightFraction.numerator * leftFraction.denominator);
    f.denominator = leftFraction.denominator * rightFraction.denominator;
    f.reduce();

    return f;
}

// binary operator (==) as a member function (1 args)
bool Fraction::operator==(const Fraction& rightFraction) const {
    Fraction f = rightFraction;
    Fraction f2 = *this;
    f2.reduce();
    f.reduce();
    // Assumes both fractions are reduced!
    return ((f2.numerator == f.numerator) &&
            (f2.denominator == f.denominator));
}

istream &operator>>(istream &in, Fraction &f) {
    char ch;
    // WEAK programming effort here... assumes 4/5 format,
    // doesn't typ check anything including the '/', etc.
    // Works if the input is formatted properly.
    in >> f.numerator >> ch >> f.denominator;
    f.sanityCheck();
    return (in);
}

ostream &operator<<(ostream &out, const Fraction &f) {
    out << f.numerator << '/' << f.denominator;
    return out;
}

