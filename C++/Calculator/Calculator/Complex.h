#ifndef COMPLEX_H
#define COMPLEX_H

#include "global.h"

class Complex
{

private:
    double p1;
    double p2;
    form_t form;

public:
    Complex(void);                                                          // Constructor 1
    Complex(const double& part1, const double& part2, const form_t& type);  // Constructor 2
    Complex(const double& value);                                           // Constructor 3

    bool ispolar(void);                                     // returns true if complex object is in polar form
    bool isrect(void);                                      // returns true if complex object is in rectangular form

    form_t getform(void);                                   // returns the current form

    double real(void);                                      // returns the real part of a complex object
    double im(void);                                        // returns the imaginary part of a complex object
    double mag(void);                                       // returns the magnitude of a complex object
    double phase(void);                                     // returns the phase of a complex object

    Complex& topolar(void);                                 // converts a complex object to polar form
    Complex& torect(void);                                  // converts a complex object to rectangular form
    Complex& to_normal_angle(void);                         // brings angle between +/- 180 or +/- pi/2 or +/- 200
    Complex conj(void);                                     // returns the complex conjugate of a complex object, in the same form
    Complex operate(const QChar& op, Complex obj);          // operate on another Complex object, with any operator
    Complex operate(const QChar& op, const double& num);    // operate on a double, with any operator

    Complex& operator = (const Complex& obj);               // overloaded '=' operator for two Complex objects (Complex = Complex)
    Complex operator + (Complex obj);                       // overloaded '+' operator for adding Complex objects
    Complex operator - (Complex obj);                       // overloaded '-' operator for subtracting Complex objects
    Complex operator * (Complex obj);                       // overloaded '*' operator for multiplying Complex objects
    Complex operator / (Complex obj);                       // overloaded '/' operator for dividing Complex objects
    Complex operator ANGLE_OP (const Complex& obj);         // angle operator for two Complex objects (Complex @ Complex)

    Complex& operator = (const double& num);                // overloaded '=' operator for a Complex object and a double (Complex = double)
    Complex operator + (const double& num);                 // overloaded '+' operator for adding a double to a Complex object (Complex + double)
    Complex operator - (const double& num);                 // overloaded '-' operator for subtracting a double from a Complex object (Complex - double)
    Complex operator * (const double& num);                 // overloaded '*' operator for multiplying a Complex object by a double (Complex * double)
    Complex operator / (const double& num);                 // overloaded '/' operator for dividing a Complex object by a double (Complex / double)
    Complex operator ANGLE_OP(const double& num);           // angle operator for a Complex object and a double (Complex @ double)

    QString to_user_string(void);                           // returns a normal, user-friendly string; ex) 5@-90 --> -5j, 1@180 --> -1
    QString to_internal_string(void);                       // returns an internally-friendly string; ex) 5|180 --> -5, -192j --> 192|-90
    QString print_complex(void);                            // returns a string used strictly for output on GUI
};

#endif // COMPLEX_H
