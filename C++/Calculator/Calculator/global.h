#ifndef GLOBAL_H
#define GLOBAL_H

// global includes
#include <QString>
#include <QChar>
#include <QDebug>
#define _USE_MATH_DEFINES
#include <cmath>

// global constants
#define ITERATIONS 1
#define PRECISION 15
#define NUMFUNCS 7
#define NUMSUBS 4
#define EPSILON (1e-14)
#define UNKNOWN 'u'
#define ANGLE_OP |
#define ANGLE '|'
#define USER_ANGLE '@'
#define PI_SYMB 'p'
#define FUNCSTART 'f'
#define FUNCEND 'n'
#define ARG_SEPARATOR ','

//#define PI_STRING QString("%1").arg(M_PI, 0, 'g', 16)
#define PI_STRING "3.1415926535897932384626433832795"
#define DEG_SEMICIRCLE 180.0
#define DEG_CIRCLE 360.0
#define RAD_SEMICIRCLE M_PI
#define RAD_CIRCLE  (M_PI * 2.0)
#define GRAD_SEMICIRCLE 200.0
#define GRAD_CIRCLE 400.0

#define DTR ((M_PI)/(180.0))
#define DTG ((400.0)/(360.0))
#define RTD ((180.0)/(M_PI))
#define RTG ((200.0)/(M_PI))
#define GTD ((360.0)/(400.0))
#define GTR ((M_PI)/(200.0))
//#define DEGREESYMB 176 // degree symbol ascii value

// enumerated types
enum form_t { RECT, POLAR };
enum angle_form_t { DEGREES, RADIANS, GRADS };
enum state_t { S_ZERO, S_ONE, S_TWO };
enum error_t
{
    NONE,
    GENERIC,
    PRNTHCNT,
    PRNTHRIGHT,
    INVCHAR,
    PNMD,
    ANGMATH,
    PRNTHMULT,
    BEGOPS,
    THREEOPS,
    EMPTPRNTH,
    OPERATEFUNC,
    DOUBLEANG,
    DIVZERO,
    MULTDIV,
    DOUBLE_E,
    ANGLE_TYPE,
    SUBST,
    COMPFUNC,
    FUNCARGS,
    BADSEPARATOR
};
enum func_t
{
    SIN,
    COS,
    TAN,
    MOD,
    MAG,
    ARG,
    CONJ
};

// global variables
extern angle_form_t g_angle_form;   // holds angle type
extern error_t g_error;             // holds error type

// global const variables
extern const QString sub_vars[];
extern const QList<QString> NO_SUBS;
extern const QString funcs[];
extern const QString JSUBS[];

using namespace std;

#endif // GLOBAL_H
