#include "global.h"
#include "Complex.h"
#include "functions.h"

/*******************************************************/
/*          Implementations for Complex.h              */
/*******************************************************/

// Constructor 1
Complex::Complex(void)
{
    this->p1 = 0.0;
    this->p2 = 0.0;
    this->form = RECT;
}

// Constructor 2
Complex::Complex(const double& part1, const double& part2, const form_t& type)
{
    this->p1 = part1;
    this->p2 = part2;
    this->form = type;
}

// Constructor 3
Complex::Complex(const double &value)
{
    this->p1 = value;
    this->p2 = 0.0;
    this->form = RECT;
}

// returns true if current form is polar
bool Complex::ispolar(void)
{
    return (this->form == POLAR);
}

// returns true if current form is rectangular
bool Complex::isrect(void)
{
    return (this->form == RECT);
}

// returns the current form
form_t Complex::getform(void)
{
    return this->form;
}

// returns the complex conjugate
Complex Complex::conj(void)
{
    return Complex(this->p1, -1.0 * this->p2, this->form);
}

// converts to polar if necessary
Complex& Complex::topolar(void)
{
    if (this->form == RECT)
    {
        double mag = hypot(this->p1, this->p2);
        double phase = atan2(this->p2, this->p1);

        this->p1 = mag;
        this->p2 = change_angle(phase, RADIANS, g_angle_form);
        this->form = POLAR;
    }

    return *this;
}

// converts to rectangular if necessary
Complex& Complex::torect(void)
{
    if (this->form == POLAR)
    {
        double mag = this->p1;
        double phase = change_angle(this->p2, g_angle_form, RADIANS); // adjust the phase to radians for trig functions

        this->p1 = mag * r_cos(phase);
        this->p2 = mag * r_sin(phase);
        this->form = RECT;
    }

    return *this;
}

// brings the phase into a natural range
Complex& Complex::to_normal_angle(void)
{
    double circle, semicircle;

    switch(g_angle_form)
    {
    case DEGREES:
        circle = DEG_CIRCLE;
        semicircle = DEG_SEMICIRCLE;
        break;
    case RADIANS:
        circle = RAD_CIRCLE;
        semicircle = RAD_SEMICIRCLE;
        break;
    case GRADS:
        circle = GRAD_CIRCLE;
        semicircle = GRAD_SEMICIRCLE;
        break;
    default:
        circle = DEG_CIRCLE;
        semicircle = DEG_SEMICIRCLE;
        g_error = ANGLE_TYPE;
    }

    int i_ang = (int) ((this->p2 / semicircle) + copysign(1, this->p2)) / 2 ;
    this->p2 -= i_ang * circle;

    return *this;
}

// returns the real part (rectangular)
double Complex::real(void)
{
    return this->torect().p1;
}

// returns the imaginary part (rectangular)
double Complex::im(void)
{
    return this->torect().p2;
}

// returns the magnitude (polar)
double Complex::mag(void)
{
    return this->topolar().p1;
}

// returns the phase angle (polar)
double Complex::phase(void)
{
    return this->topolar().p2;
}

// copies (obj) to (this)
Complex& Complex::operator =(const Complex& obj)
{
    this->p1 = obj.p1;
    this->p2 = obj.p2;
    this->form = obj.form;

    return *this;
}

// returns a positive magnitude, normal-angled Complex object
Complex Complex::operator ANGLE_OP(const Complex& obj)
{
    // error if either number already has an imaginary part
    if (this->p2 || obj.p2) { g_error = DOUBLEANG; return *this; }

    Complex result(this->p1, obj.p1, POLAR);

    // change (-M | A) to (+M | A+180) so magnitude is positive
    if(result.p1 < 0)
    {
        result.p1 *= -1.0;
        result.p2 = change_angle( (change_angle(result.p2, g_angle_form, DEGREES) + DEG_SEMICIRCLE), DEGREES, g_angle_form );
    }

    if(result.mag())
        return result.to_normal_angle();
    else
        return Complex(0, 0, POLAR);
}

// returns the sum of (this) and (obj) in rectangular
Complex Complex::operator +(Complex obj)
{
    this->torect();
    obj.torect();
    return Complex(this->p1 + obj.p1, this->p2 + obj.p2, RECT);
}

// returns the difference of (this) and (obj) in rectangular
Complex Complex::operator -(Complex obj)
{
    this->torect();
    obj.torect();
    return Complex(this->p1 - obj.p1, this->p2 - obj.p2, RECT);
}

// returns the product of (this) and (obj) in polar
Complex Complex::operator *(Complex obj)
{
    if(this->mag() && obj.mag())
        return Complex(this->mag() * obj.mag(), this->phase() + obj.phase(), POLAR);
    else
        return Complex(0, 0, POLAR);
}

// returns the quotient of (this) and (obj) in polar
Complex Complex::operator /(Complex obj)
{
    this->topolar();
    obj.topolar();
    return Complex(this->p1 / obj.p1, this->p2 - obj.p2, POLAR);
}

// operate on another Complex object, with any operator
Complex Complex::operate(const QChar &op, Complex obj)
{
    switch (op.toLatin1())
    {
    case '+':
        return *this + obj;
    case '-':
        return *this - obj;
    case '*':
        return *this * obj;
    case '/':
        if (obj.mag())
            return *this / obj;
        else
            g_error = DIVZERO;
        break;
    case ANGLE:
        return *this ANGLE_OP obj; // angle operator
        break;
    case ARG_SEPARATOR:
        g_error = BADSEPARATOR;
        break;
    default:
        g_error = OPERATEFUNC;
        break;
    }

    return Complex();
}

// copies a double to the real part of (this), imaginary part set to zero
Complex& Complex::operator =(const double& number)
{
    this->p1 = number;
    this->p2 = 0.0;
    this->form = RECT;

    return *this;
}

// overloads operator ANGLE_OP
Complex Complex::operator ANGLE_OP(const double& num)
{
    return *this ANGLE_OP Complex(num);
}

// overloads operator+
Complex Complex::operator +(const double& num)
{
    this->torect();
    return Complex(this->p1 + num, this->p2, RECT);
}

// overloads operator-
Complex Complex::operator -(const double& num)
{
    this->torect();
    return Complex(this->p1 - num, this->p2, RECT);
}

// overloads operator*
Complex Complex::operator *(const double& num)
{
    this->topolar();
    return Complex(this->p1 * num, this->p2, RECT);
}

// overloads operator/
Complex Complex::operator /(const double& num)
{
    this->topolar();
    return Complex(this->p1 / num, this->p2, RECT);
}

// operate on a double, with any operator
Complex Complex::operate(const QChar &op, const double& num)
{
    switch (op.toLatin1())
    {
    case '+':
        return *this + num;
    case '-':
        return *this - num;
    case '*':
        return *this * num;
    case '/':
        if (num)
            return *this / num;
        else
            g_error = DIVZERO;
        break;
    case ANGLE:
        return *this ANGLE_OP num; // angle operator
        break;
    case ARG_SEPARATOR:
        g_error = BADSEPARATOR;
        break;
    default:
        g_error = OPERATEFUNC;
        break;
    }

    return Complex();
}

// returns a normal, user-friendly string; ex) 5@-90 --> -5j, 1@180 --> -1
QString Complex::to_user_string(void)
{
    QString formatted;

    // number is purely real, ex. -4 + 0j, 4@180
    if(this->real() && !this->im())
        formatted += QString::number(this->real(), 'g', PRECISION);

    // number is purely imaginary, ex. 0 - 4j, 4@-90
    else if(!this->real() && this->im())
        formatted += QString::number(this->im(), 'g', PRECISION) + 'j';

    // number has a real and imaginary part, ex. 4 - 4j, 5.6569@-45
    else if(this->real() && this->im())
        formatted = QString::number(this->mag(), 'g', PRECISION - 1) + USER_ANGLE + QString::number(this->phase(), 'g', PRECISION - 1);

    // number is zero
    else if(!this->mag())
        formatted = '0';

    return formatted;
}

// returns an internally-friendly string; ex) 5|180 --> -5, -192j --> 192|-90
QString Complex::to_internal_string(void)
{
    // eliminate negative magnitudes by using operator ANGLE_OP
    Complex temp = Complex(this->mag()) ANGLE_OP Complex(this->phase());

    // convert (M @ 180) and (M @ -180) to (-M @ 0) for simplification
    double angle = temp.phase();
    angle = change_angle(angle, g_angle_form, DEGREES);

    if(angle == DEG_SEMICIRCLE || angle == -DEG_SEMICIRCLE)
        temp = Complex(-1.0*temp.mag(), 0, POLAR);

    // reconstruct the complex object as a QString
    QString converted = QString::number(temp.p1, 'g', PRECISION);
    if (temp.p2)
    { // do NOT represent real numbers as ( real | 0 ) or ( real | 180 ) or ( real | -180 )
        converted += ANGLE;
        converted += QString::number(temp.p2, 'g', PRECISION);
    }

    return converted;
}

// returns a string used strictly for output on GUI
QString Complex::print_complex(void)
{
    QString rect;

    if(this->real()) rect += QString::number(this->real(), 'g', PRECISION - 1);

    if(this->im() && this->real())
    {
        if(this->im() > 0) rect += " + ";
        else rect += " - ";

        // absolute value of imaginary part since sign was already handled
        rect += QString::number(fabs(this->im()), 'g', PRECISION - 1) + 'j';
    }
    else if(this->im()) rect += QString::number(this->im(), 'g', PRECISION - 1) + 'j';

    else if(!(this->mag())) rect = '0';

    QString polar = QString::number(this->mag(), 'g', PRECISION - 1) + "  /_  " + QString::number(this->phase(), 'g', PRECISION - 1);

    return rect + "\n\n" + polar;
}
