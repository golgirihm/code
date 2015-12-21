#include "global.h"
#include "functions.h"
#include "Complex.h"

/*******************************************************/
/*          Implementations for functions.h            */
/*******************************************************/

// cleans the whitespace from a QString
QString compress(const QString& s)
{
    QString cleaned;
    int length = s.length();

    for (int i = 0; i < length; ++i)
        if (!s[i].isSpace())
            cleaned += s[i];

    return cleaned;
}

// returns true if c is a '+' or '-'
bool ispn(const QChar& c)
{
    switch(c.toLatin1())
    {
    case '+':
    case '-':
        return true;
    default:
        return false;
    }
}

// returns true if c is a '*' or '/'
bool ismd(const QChar& c)
{
    switch(c.toLatin1())
    {
    case '*':
    case '/':
        return true;
    default:
        return false;
    }
}

// returns true if c is an operator
bool ismath(const QChar& c)
{
    return (ispn(c) || ismd(c) || c == ANGLE);
}

// returns true if c is a number, decimal, or 'e'
bool isnumeric(const QChar& c)
{
    return (c.isDigit() || c == '.' || c == 'e');
}

// returns a fully formatted string, changes the way disp looks
QString fix(QString& disp, const QList<QString>& subs)
{
    // check that user didn't input overloaded angle operator
    if(disp.contains(ANGLE)) g_error = INVCHAR;

    // local copy of input string, indexing variable
    QString in = compress(disp).toLower();
    int i;

    // substitute function names for coded names; ex) 3*tan(45)+1 --> 3*f2n(45)+1
    for(i = 0;  i < NUMFUNCS; ++i) in.replace(funcs[i], FUNCSTART + QString::number(i) + FUNCEND);

    // user substitutions
    i = 0; foreach(QString sub_it, subs)
    {
        for(int j = 0; j < NUMSUBS; ++j) if(sub_it.contains(sub_vars[j])) g_error = SUBST;

        if(!sub_it.length()) sub_it = '0';

        sub_it.prepend('(').append(')');
        in.replace(sub_vars[i++], sub_it);
    }

    // constant substitutions
    in.replace('i', 'j').replace('j', JSUBS[g_angle_form]).replace(USER_ANGLE, ANGLE);
    in.replace(PI_SYMB, PI_STRING);

    // explicitly add a '*' wherever implicit multiplication occurs
    for (i = 0; i < (int)in.length() - 1; ++i)
    {
        if ( ((in[i].isDigit() || in[i] == '.' || in[i] == ')') && (in[i + 1] == '(' || in[i + 1] == FUNCSTART))
             || (in[i] == ')' && (in[i + 1].isDigit() || in[i + 1] == '.')) )
            in.insert(i + 1, "*");
    }

    // makes sure last QChar in input is a number or ending parenthesis or substitution
    i = in.length() - 1; // last index of QString
    while (i >= 0 && !(in[i].isDigit() || in[i] == ')' || in[i] == '.'))
    {
        in.remove(i, 1);
        i = in.length() - 1;
    }

    // gets rid of unnecessary characters before end parenthesis like the ones in "(77 - 8+*krrsp)" and "(3*-+/)"
    for (i = in.length() - 1; i > 0; i--)
        if (in[i] == ')' && !isnumeric(in[i - 1]) && in[i - 1] != '(' && in[i - 1] != ')')
            in.remove(i - 1, 1);

    /***************************/
    /* do these steps for disp */
    /***************************/
    {
        disp = disp.simplified();
        disp = disp.toLower();

        // makes sure last QChar in input is a number or ending parenthesis or a substitution
        i = disp.length() - 1; // last index of QString
        while (i >= 0 && !(disp[i].isDigit() || disp[i] == ')' || disp[i] == '.' || issub(disp[i]) || disp[i] == 'j' || disp[i] == 'i'))
        {
            disp.remove(i, 1);
            i = disp.length() - 1;
        }

        // gets rid of unnecessary characters before an end parenthesis like the ones in "(77 - 8+*krrsp)" and "(3*-+/)"
        for (i = disp.length() - 1; i > 0; i--)
            if (i >= 0 && disp[i] == ')' && !isnumeric(disp[i - 1]) && disp[i - 1] != '(' && disp[i - 1] != ')' && disp[i - 1] != 'j' && disp[i - 1] != 'i' && !issub(disp[i - 1]))
                disp.remove(i - 1, 1);
    }

    return in;
}

// returns true if c is a QChar that is internally allowed
bool isokay(const QChar& c)
{

    switch(c.toLatin1())
    {
    case '(':
    case ')':
    case ANGLE:
    case FUNCSTART:
    case FUNCEND:
    case ARG_SEPARATOR:
        return true;
    }

    return (isnumeric(c) || ismd(c) || ispn(c));
}

// returns true if c is a substitution (a, x, y, z)
bool issub(const QChar& c)
{
    switch(c.toLatin1())
    {
    case 'a':
    case 'x':
    case 'y':
    case 'z':
    case PI_SYMB:
        return true;
    }

    return false;
}

// returns true if s is a correctly formatted internal string
bool goodstring(const QString& s)
{
    int length = s.length();

    for (int i = 0; i < length; ++i)
    {
        if (!isokay(s[i])) { g_error = INVCHAR; return false; }

        if (i + 1 < length)
        {
            if (ispn(s[i]) && ismd(s[i + 1])) { g_error = PNMD; return false; }

            if (ismd(s[i]) && ismd(s[i + 1])) { g_error = MULTDIV; return false;}

            if ((s[i] == ANGLE && ismd(s[i + 1])) || (ismath(s[i]) && s[i + 1] == ANGLE) ) { g_error = ANGMATH; return false; }

            if ( ((s[i].isDigit() || s[i] == '.') && s[i + 1] == '(') || (s[i] == ')' && (s[i + 1].isDigit() || s[i + 1] == '.')) ) { g_error = PRNTHMULT; return false; }

        } // checking pairs of Qchars in a row
    }

    // checking for proper parenthesis use
    int lcount = 0, rcount = 0;
    for (int j = 0; j < length; ++j)
        switch (s[j].toLatin1())
        {
        case'(':
            ++lcount;
            break;
        case')':
            ++rcount;
            if(rcount > lcount) { g_error = PRNTHRIGHT; return false; }
            break;
        }

    if (rcount != lcount) { g_error = PRNTHCNT; return false; }
    if (s.contains("()")) { g_error = EMPTPRNTH; return false; }
    if (s.contains("ee")) { g_error = DOUBLE_E; return false; }
    if (length && ((ismd(s[0]) || s[0] == ANGLE || s[0] == 'e') || (ismath(s[0]) && ismath(s[1])))) { g_error = BEGOPS; return false; }

    // state machine for finding 3 operators in a row, which is not allowed
    state_t op_state = S_ZERO;
    for (int i = 0; i < length; ++i)
        switch (op_state)
        {
        case S_ZERO:
            if (ismath(s[i])) op_state = S_ONE;
            break;
        case S_ONE:
            if (ismath(s[i])) op_state = S_TWO;
            else op_state = S_ZERO;
            break;
        case S_TWO:
            if (ismath(s[i])) { g_error = THREEOPS; return false; }
            else op_state = S_ZERO;
            break;
        } // end switch

    // otherwise
    return true;
}

// convert input QChars into an argument or an operator and store
QString convert(QString in, QList<double>& args, QString& ops)
{
    QString conv_arg;
    QChar conv_op = UNKNOWN;
    int i, length = in.length(), charcount = 0;

    for (i = 0; i < length; ++i)
    {
        if (conv_op == UNKNOWN)
        {
            // found a digit, decimal point, 'e' (exponent), or +/- sign
            if (isnumeric(in[i]) || ispn(in[i]))
            {
                if (!ispn(in[i]) || i == 0)
                    conv_arg += in[i];
                else if (i + 1 < length && in[i - 1] == 'e' && ispn(in[i]) && in[i + 1].isDigit())	// this means something like 1e-34
                    conv_arg += in[i];
                else
                    conv_op = in[i]; // Found '+' or '-' operator
            }

            // found operator
            else
                conv_op = in[i];
            ++charcount;	// increment charcount so that used portion of QString can be removed
        }

        // already found number and operator
        else
            break;
    } // end looping through QString

    // store number and operator into arrays
    args << conv_arg.toDouble();
    if (conv_op != UNKNOWN) ops += conv_op;

    return in.remove(0, charcount); // return only the unprocessed portion of the input QString
}

// calculates the actual value of the result of the input arrays
Complex calculate(const QList<double>& args, const QString& ops)
{
    QList<Complex> angle_args, md_args;
    QString angle_ops, md_ops;

    int i;

    int num_args = args.size();
    int num_ops = ops.size();

    // convert all double args[] to complex numbers in[]
    QList<Complex> in;
    for (i = 0; i < num_args; ++i) in << Complex(args[i]);

    // all combining of magnitudes and phases into Complex objects
    for (i = 0; i < num_args; ++i)
    {
        if ((i < num_ops) && (ops[i] == ANGLE))
        {
            angle_args.append(in[i].operate(ops[i], in[i + 1]));	// put a magnitude and phase into a single complex object in next array
            if (++i < num_ops) angle_ops.append(ops[i]);	// the operator after the complex object that was just created
        }
        else // numbers that are separated by + , -, *, or / operator
        {
            angle_args.append(in[i]);
            if (i < num_ops) angle_ops.append(ops[i]);
        }
    }

    num_args = angle_args.size();
    num_ops = angle_ops.size();

    // all multiplication and division
    for (i = 0; i < num_args; ++i)
    {
        if (i < num_ops && ismd(angle_ops[i]))
        {
            Complex temp = angle_args[i];

            do
            {   // Adjacent multiplications and divisions
                temp = temp.operate(angle_ops[i], angle_args[i + 1]);
            } while (++i < num_ops && ismd(angle_ops[i]));

            md_args.append(temp);
            if (i < num_ops) md_ops.append(angle_ops[i]);
        }
        else // numbers that are separated by positive or negative operator
        {
            md_args.append(angle_args[i]);
            if (i < num_ops) md_ops.append(angle_ops[i]);
        }
    }

    num_args = md_args.size();
    num_ops = md_ops.size();

    // all addition and subtraction
    Complex result;
    if(num_args) result = md_args[0];
    for (i = 0; i < num_ops; ++i)
        result = result.operate(md_ops[i], md_args[i + 1]); // add and subtract the final complex numbers

    return result;
}

QString userfunc(const QString& in, const func_t& func_id)
{
    QStringList arg_list = in.split(ARG_SEPARATOR, QString::SkipEmptyParts);
    QList<Complex> args;
    foreach(QString arg_it, arg_list) args << simplify_string(parenth(arg_it));

    Complex answer;
    if(args.size() == 1)
        switch(func_id)
        {
        case SIN:
            answer = sin( change_angle(args[0].real(), g_angle_form, RADIANS) );
            if(args[0].im()) g_error = COMPFUNC;
            break;
        case COS:
            answer = cos( change_angle(args[0].real(), g_angle_form, RADIANS) );
            if(args[0].im()) g_error = COMPFUNC;
            break;
        case TAN:
            answer = tan( change_angle(args[0].real(), g_angle_form, RADIANS) );
            if(args[0].im()) g_error = COMPFUNC;
            break;
        case MAG:
            answer = args[0].mag();
            break;
        case ARG:
            answer = args[0].phase();
            break;
        case CONJ:
            answer = args[0].conj();
            break;
        default:
            g_error = FUNCARGS;
        }
    else if(args.size() == 2)
        switch(func_id)
        {
        case MOD:
            answer = fmod(args[0].real(), args[1].real());
            if(args[0].im() || args[1].im()) g_error = COMPFUNC;
            break;
        default:
            g_error = FUNCARGS;
        }
    else g_error = FUNCARGS;

    //qDebug() << funcs[func_id].toStdString().c_str() << "(" << QString("%1").arg(temp, 0, 'g', PRECISION).toStdString().c_str() << ") == " << ans.to_string().toStdString().c_str();

    return answer.to_internal_string();
}

// strips all parenthesis from a string
QString parenth(const QString& in)
{
    {/*******************************************************************************************/
    /* basic is a QString that consists of the input QChars up to the first open parenthesis    */
    /* A set is a QString that consists of all the QChars between 2 matched parenthesis         */
    /* A mid is a QString that consists of all the Qchars between 2 opposing parenthesis        */
    /********************************************************************************************/
    /* Example string:  52.16*(1@45*(29.3)-4)+42/(5-2*3.67)                                     */
    /* basic  ==  "52.16*"                                                                      */
    /* set[0] ==  "1@45*(29.3)-4", set[1] == "5-2*3.67"                                         */
    /* mid[0] ==  "+42/"          <-- by definition, a mid will never have parenthesis          */
    /********************************************************************************************/}

    // find positions of outermost parenthesis
    int i, length = in.length();    // for looping
    int lcount = 0, rcount = 0;     // for counting left and right parenthesis
    QList<int> lpos, rpos;
    QList<bool> set_is_func;
    for (i = 0; i < length; ++i)
        switch (in[i].toLatin1())
        {
        case'(':
            ++lcount;
            if(lcount == rcount + 1)
            {
                lpos << i;

                if(i > 0 && in[i - 1] == FUNCEND)
                    set_is_func << true;
                else
                    set_is_func << false;
            }
            break;
        case')':
            ++rcount;
            if (lcount == rcount)
                rpos << i;
            break;
        }

    // store beginning of string up to any parenthesis or function
    QString basic = in.left(in.indexOf( ((!set_is_func.isEmpty() && set_is_func[0]) ? FUNCSTART : '('), 0) );

    // store all sets (outmost parenthesized portions) and mids (portions between parenthesis)
    QList<QString> sets, mids;
    func_t func_id[lpos.size()];
    for(i = 0; i < lpos.size(); ++i )
    {
        if(set_is_func[i])
        {
            int funcpos = in.indexOf(FUNCSTART, lpos[i] - 3);
            func_id[i] = (func_t) in.mid(funcpos + 1, in.indexOf(FUNCEND, funcpos) - funcpos - 1).toInt();
        }

        sets << in.mid(lpos[i] + 1, rpos[i] - 1 - lpos[i]);
        mids << in.mid(rpos[i] + 1, in.indexOf((i + 1 < set_is_func.size() && set_is_func[i + 1]) ? FUNCSTART : '(', rpos[i]) - (rpos[i] + 1));

//        qDebug() << "sets[" << i << "] = " << sets[i];
//        qDebug() << "mids[" << i << "] = " << mids[i];
    }

    // recursively call function to strip any parenthesis within sets and simplify sets
    for (i = 0; i < sets.size(); ++i)
    {
        if(set_is_func[i])
            basic += userfunc(sets[i], func_id[i]);
        else
            basic += parenth(sets[i]);
        basic += mids[i];
    }

    // call simplify string on basic when it has no parenthesis
    //qDebug() << "returning: simplify_string(" << basic << ") ==" << simplify_string(basic).to_string();
    return simplify_string(basic).to_internal_string();
}

// simplifies a string into an array of Complex objects and an array of operators and then down to a single Complex object
Complex simplify_string(QString in)
{
    if (g_error == NONE && in.length())
    {
        // create two arrays, one for numbers and one for operators
        QList<double> args;
        QString ops;

        // place everything from the QString into 2 arrays, "arg" and "op"
        while(!in.isEmpty()) in = convert(in, args, ops);

        Complex temp = calculate(args, ops);
        return temp;
    }

   // return an empty complex object if input is empty or invalid
   return Complex(0, 0, RECT);
}

QString error_msg(const error_t& error)
{
    QString msg = "Input string error number " + QString::number(error) + ":\n\n";

    switch (error){
    case NONE:
        msg += "No errors have been detected";
    case GENERIC:
        msg += "Generic error.";
        break;
    case PRNTHCNT:
        msg += "Different amount of left and right parenthesis.";
        break;
    case PRNTHRIGHT:
        msg += "Parenthesis do not match.";
        break;
    case INVCHAR:
        msg += "At least one invalid char.";
        break;
    case PNMD:
        msg += "Sign error, + or - sign directly followed by * or /.";
        break;
    case MULTDIV:
        msg += "Sign error, check multiplication and division operators.";
        break;
    case ANGMATH:
        msg += "Sign error, check angle operators.";
        break;
    case PRNTHMULT:
        msg += "Implicit multiplication issue with parenthesis.";
        break;
    case BEGOPS:
        msg += "Check beginning chars. First char may not be an\noperator unless it is a positive or negative sign.";
        msg += "\nThere cannot be two operators in a row at the\nbeginning of the input. ";
        msg += "First char also may not\nbe an 'e'.";
        break;
    case THREEOPS:
        msg += "Too many operators found in a row.";
        break;
    case EMPTPRNTH:
        msg += "Set of empty parenthesis.";
        break;
    case OPERATEFUNC:
        msg += "At least one invalid operator used.";
        break;
    case DOUBLEANG:
        msg += "Cannot assign an angle to a complex number that already has an angle.\n\n"
            "Ex: 24 @ 45 @ 36.87";
        break;
    case DIVZERO:
        msg += "Division by zero.";
        break;
    case DOUBLE_E:
        msg += "Two 'e's in a row.";
    case ANGLE_TYPE:
        msg += "Angle type (Degrees/Radians/Grads) not defined.";
    case SUBST:
        msg += "Input substitutions may not have substitutions within them.";
    case COMPFUNC:
        msg += "Complex number used as an argument to a math function\nthat takes a real number.";
        break;
    case FUNCARGS:
        msg += "Incorrect number of arguments to a math function.";
        break;
    case BADSEPARATOR:
        msg += "Do not place a comma outside of a function";
        break;
    }

    return msg + '\n';
}

void round_if_near(double& input, const double& val, const double& eps)
{
    if((input > val && input < val + eps) || (input < val && input > val - eps))
    {
        //qDebug() << QString("Setting input of %1 to %2").arg(input, 0, 'g', PRECISION).arg(val, 0, 'g', PRECISION);
        input = val;
    }
}

double r_cos(const double& x)
{
    double result = cos(x);

    round_if_near(result, 1, EPSILON);
    round_if_near(result, 0, EPSILON);
    round_if_near(result, -1, EPSILON);

    return result;
}

double r_sin(const double& x)
{
    double result = sin(x);

    round_if_near(result, 1, EPSILON);
    round_if_near(result, 0, EPSILON);
    round_if_near(result, -1, EPSILON);

    return result;
}

double change_angle(double angle, const angle_form_t& type1, const angle_form_t& type2)
{
    switch(type1)
    {
    case RADIANS:
        switch(type2)
        {
        case RADIANS:
            break;
        case DEGREES:
            angle *= RTD;
            break;
        case GRADS:
            angle *= RTG;
            break;
        }
        break;

    case DEGREES:
        switch(type2)
        {
        case RADIANS:
            angle *= DTR;
            break;
        case DEGREES:
            break;
        case GRADS:
            angle *= DTG;
            break;
        }
        break;

    case GRADS:
        switch(type2)
        {
        case RADIANS:
            angle *= GTR;
            break;
        case DEGREES:
            angle *= GTD;
            break;
        case GRADS:
            break;
        }
        break;
    }

    return angle;
}

void SetGlobalAngleType(const QChar& c)
{
    switch(c.toLatin1())
    {
    case 'D':
        g_angle_form = DEGREES;
        break;
    case 'R':
        g_angle_form = RADIANS;
        break;
    case 'G':
        g_angle_form = GRADS;
        break;
    default:
        g_error = ANGLE_TYPE;
        break;
    }
}
