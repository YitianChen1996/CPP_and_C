This is a example class in C++, which shows the implementation of fraction.<br><br>
1.There are three types of constructors in C++:<br>
a.default constructor<br>
b.parameters with values<br>
c.copy constructor<br>
Constructors have no return values. Copy constructor has one parameter, which is the <b>const reference</b> of the class type, such as<br><br>
Fraction::Fraction(const Fraction &f2) {<br>
    cout << "Called copy constructor" << endl;<br>
    numerator = f2.numerator;<br>
    denominator = f2.denominator;<br>
}<br><br>
And when you use<br><br>
Fraction f1 = Fraction(1,2);<br>
Fraction f2 = f1;//copy constructor is called<br><br>
But if you use<br><br>
Fraction f2;
f2 = f1;//it is the assignment (operator=) is called.<br><br>
2.You can also overload some operators<br>
There are 38 operators in C++ you can overload, in C++'s official document:http://en.cppreference.com/w/cpp/language/operators<br>
And there are two ways to realize it, one is overload as a member function, or overload it as a non-member function(friend function).<br>
Assignment operator(=) must be implemented as a member function.You pass in a <b>const reference</b> of the class, and return *this*/ as the result.<br><br>
Fraction& Fraction::operator=(const Fraction& rightFraction) {<br>
    cout << "Called assignment operator." << endl;<br>
    numerator = rightFraction.numerator;<br>
    denominator = rightFraction.denominator;<br>
    return (*this);<br>
}<br><br>
Binary Arithmetic operators (+,-*,/) can be implemented as non-member functions, in order to main symmetry(for example, when adding a complex number and an integer, if operator+ is a member function of the complex type, then only complex+integer would compile, and not integer+complex)<br>
To declare a friend function in a class, we can use "friend" keyword. A friend function has the right to access all private members in the class. And another thing is, they can be declared in the class, but defined(implemented by code) outside the scope of the class.<br>
For example:<br><br>
in Fraction.h:<br>
friend Fraction operator-(const Fraction& leftFraction, const Fraction& rightFraction);<br>
and in Fraction.cpp:<br>
Fraction operator-(const Fraction& leftFraction, const Fraction& rightFraction) {//no need to use Fraction::operator-, because friend function can be implemented outside of the class<br>
    Fraction f;<br>
    f.numerator = (leftFraction.numerator * rightFraction.denominator) -<br>
                  (rightFraction.numerator * leftFraction.denominator);<br>
    f.denominator = leftFraction.denominator * rightFraction.denominator;<br>
    f.reduce();<br>
    return f;<br>
}<br><br>
Binary arithmetic operator can also be implemented as member function, but in this condition, it should has only one parameter. See the implementation of operator+ in the Fraction.cpp


