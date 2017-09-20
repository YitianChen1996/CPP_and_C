//
// Created by 64419 on 9/19/2017.
//

#include <iostream>
#ifndef COPYCONSTRUCTORTEST_FRACTION_H
#define COPYCONSTRUCTORTEST_FRACTION_H

using namespace std;

class Fraction {
private:
    // Data members should almost always be private.  If you would like
    // users of your class to have "access" to data members, create
    // "get" and "set" public member functions.  For example, we could
    // support "int getNumerator()" to return the numerator.
    int numerator;
    int denominator;
    void reduce ();
    void sanityCheck ();

public:
    // Three constructors for objects of this class.

    // The "default constructor" takes no parameters.
    Fraction();

    // The "copy constructor" takes a reference to an object of this class
    // const and pass by reference is mandatory, otherwise, the compiler will
    Fraction(const Fraction &f1);

    // One "value constructor" that takes a numerator and denominator
    Fraction(int num, int denom);

    // Allows programmers to assign a new value to the fraction.
    void assignValue (int theNumerator, int theDenominator);

    // Some regular old functions to do things that could be more
    // naturally done as overloaded operators
    void readValueFor ();
    void writeValueOf () const;
    Fraction add (Fraction &f) const;
    bool equal (Fraction &f);

    // Destructor.  Called every time the object goes out of scope.
    ~Fraction();

    // ===========================================================
    // Overloaded operators for the =, +, -, and == operations.
    // ===========================================================

    // assignment operator (=) as member function (1 arg)
    Fraction& operator=(const Fraction& rightFraction);

    // binary operator (+) as member function (1 arg)
    Fraction operator+(const Fraction& rightFraction) const;

    // binary operator (-) as a friend function (2 args)
    friend Fraction operator-(const Fraction& leftFraction,
                              const Fraction& rightFraction);

    // binary operator (==) as a member function (1 args)
    bool operator==(const Fraction& rightFraction) const;

    // ===========================================================
    // Friend functions for the << and >> operators.
    // ===========================================================
    friend istream & operator>>(istream &in, Fraction &f);
    friend ostream & operator<<(ostream &out, const Fraction &f);
};

#endif //COPYCONSTRUCTORTEST_FRACTION_H
