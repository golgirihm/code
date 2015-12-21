#include "mainwindow.h"

// #include "global.h"
#include <QApplication>

/****************GLOBAL VARIABLES****************/
error_t g_error;            // holds error type */
angle_form_t g_angle_form;  // holds angle type */
/************************************************/

/*******************************************GLOBAL CONST VARIABLES******************************************/
const QString sub_vars[] = {"a", "x", "y", "z"};
const QList<QString> NO_SUBS;
const QString funcs[] = {"sin", "cos", "tan", "mod", "mag", "arg", "conj"};
const QString JSUBS[3] = {QString("(1" + QString(USER_ANGLE) + "90.0)"),
                    QString("(1" + QString(USER_ANGLE) + QString("%1)").arg(M_PI_2, 0, 'g', PRECISION + 1)),
                    QString("(1" + QString(USER_ANGLE) + "100.0)")};
/***********************************************************************************************************/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Complex Number Calculator");
    w.show();

    return a.exec();
}
