This is a example class in C++, which shows the implementation of fraction.<br><br>
There are three types of constructors in C++:<br>
1.default constructor<br>
2.parameters with values<br>
3.copy constructor<br>
Constructors have no return values. Copy constructor has one parameter, which is the <b>const reference</b> of the class type, such as<br>
Fraction::Fraction(const Fraction &f2) {<br>
    cout << "Called copy constructor" << endl;<br>
    numerator = f2.numerator;<br>
    denominator = f2.denominator;<br>
}<br>
And when you use<br>
Fraction f1 = Fraction(1,2);<br>
Fraction f2 = f1;//copy constructor is called<br>
But if you use<br>
Fraction f2;
f2 = f1;//it is the assignment (operator=) is called.


