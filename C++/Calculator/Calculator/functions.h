#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "global.h"
#include "Complex.h"

bool isnumeric(const QChar& c);     // returns true if c is a number, decimal, or 'e'
bool ismath(const QChar& c);        // returns true if c is an operator
bool ispn(const QChar& c);          // returns true if c is a '+' or '-'
bool ismd(const QChar& c);          // returns true if c is a '*' or '/'
bool issub(const QChar& c);         // returns true if c is a substitution (a, x, y, z)
bool isokay(const QChar& c);		// returns true if c is a QChar that is internally allowed
bool goodstring(const QString& s);   // returns true if s is a correctly formatted internal string

void round_if_near(double& input, const double& val, const double& eps);
void SetGlobalAngleType(const QChar& c);

double change_angle(double angle, const angle_form_t& type1, const angle_form_t& type2);
double r_cos(const double& x);
double r_sin(const double& x);

QString compress(const QString &s);                     // removes any whitespace from a QString
QString fix(QString& disp, const QList<QString>& subs); // alters the form of user input to be compatible with program
QString convert(QString in, QList<double>& args, QString& ops); // stores 1st number from "in" to args and 1st operator from "in" to ops
QString userfunc(const QString& in, const func_t& func_id);     // interfaces functions that correspond to buttons
QString parenth(const QString& in);         // handles parenthesis and returns a QString with no parenthesis
QString error_msg(const error_t& error);    // returns a QString that gives information on the error found

Complex simplify_string(QString in); // changes a QString with no parenthesis into a single Complex object
Complex calculate(const QList<double>& args, const QString& ops);   // converts a list of args and a list of ops into Complex object

#endif // FUNCTIONS_H
