#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "functions.h"
#include <QHostInfo>

//constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // set up the functionalities of the buttons
    connect(ui->CalcPushButtons, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(processButtonClick(QAbstractButton*)));
    connect(ui->CalcRadioButtons, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(processButtonClick(QAbstractButton*)));

    // maintain correct focus, show when text has been changed, and calculate whenever return is pressed on a QLineEdit
    CalcLineEdits << ui->e_input << ui->e_x << ui->e_y << ui->e_z;
    foreach (QLineEdit* inputline, CalcLineEdits)
    {
        connect(inputline, SIGNAL(editingFinished()), this, SLOT(setlast_QLineEdit()));
        connect(inputline, SIGNAL(textChanged(QString)), ui->l_asterisk, SLOT(show()));
        connect(inputline, SIGNAL(returnPressed()), this, SIGNAL(NeedToCalculate()));
    }

    // initially focus on the main input and remember that degrees is the default radio button
    ui->e_input->setFocus();
    last_QRadioButton = ui->radio_degrees;

    // perform a calculation whenever it is necessary
    connect(this, SIGNAL(NeedToCalculate()), this, SLOT(perform_calculation()));

    // initially calculate with an empty input box
    emit NeedToCalculate();
}

// destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// helps with focus
void MainWindow::setlast_QLineEdit()
{
    last_QLineEdit = qobject_cast<QLineEdit*>(sender());
}

// handles button clicks
void MainWindow::processButtonClick(QAbstractButton* clickedButton)
{
    QString buttonName = clickedButton->text();
    buttonName = buttonName.toLower();
    char buttontype = clickedButton->metaObject()->className()[1];

    switch(buttontype)
    {
    case 'P': // QPushButton
        if(buttonName == ui->b_angle->text())
            buttonName = USER_ANGLE;

        if(buttonName == QChar('='))
            emit NeedToCalculate();
        else if(buttonName == QChar('c'))
            last_QLineEdit->clear();
        else
            last_QLineEdit->setText(last_QLineEdit->text() + QString(buttonName));

        if(buttonName.length() > 1) last_QLineEdit->setText(last_QLineEdit->text() + "( )");
        break;
    case 'T': // QToolButton
    case 'R': // QRadioButton
        if(!last_QRadioButton->isChecked())
        {
            ui->l_asterisk->show();
            last_QRadioButton = qobject_cast<QRadioButton*>(clickedButton);
        }
        break;
    case 'C': // QCheckBox
        break;
    }

    last_QLineEdit->setFocus();
}

// main parsing and math
void MainWindow::perform_calculation()
{

for(int j = 0; j < ITERATIONS; j++)
{
    // time for the purposes of efficiency testing
    maintimer.start();

    static Complex ans;

    // reset g_error and update g_angle_form
    g_error = NONE;
    SetGlobalAngleType(ui->CalcRadioButtons->checkedButton()->text()[0]);

    // take in strings from user and call parenth() on all substitutions
    QList<QString> LineEdits, fixed;
    for(int i = 0; i < CalcLineEdits.size(); ++i)
    {
        LineEdits << CalcLineEdits[i]->text();

        if(i)
        {
            fixed << fix(LineEdits[i], NO_SUBS);
            CalcLineEdits[i]->setText(LineEdits[i]);

            // save processing time by calculating before substituting
            if(g_error == NONE && fixed[i].length() && goodstring(fixed[i]))
                fixed[i] = parenth(fixed[i]);
        }
        else fixed << "";
    }

    QList<QString> subs; subs << prev_ans << fixed[1] << fixed[2] << fixed[3];

    fixed[0] = fix(LineEdits[0], subs);

    if(ui->e_input->text() != LineEdits[0])
        ui->e_input->setText(LineEdits[0]);

    subtimer.start();

    if(g_error == NONE && goodstring(fixed[0]))
        ans = simplify_string(parenth(fixed[0]));

    if(g_error == NONE)
    {
        ui->t_output->setText(ans.print_complex());
        ui->l_asterisk->hide();
        prev_ans = ans.to_user_string();
        //qDebug() << "prev_ans = " << prev_ans;
    }
    else if(j == ITERATIONS - 1)
    {
        QMessageBox::information(this, "Calculation Skipped", error_msg(g_error));
    }

    double timesub = subtimer.nsecsElapsed();
    double timemain = maintimer.nsecsElapsed();

    totaltimes[j] = timemain;
    subtimes[j] = timesub;

    if(j && j == ITERATIONS - 1)
    {
        double sumtot = 0;
        double sumsub = 0;

        for(int x = 0; x < ITERATIONS; x++)
        {
            sumtot += totaltimes[x];
            sumsub += subtimes[x];
        }

        qDebug() << "Number of iterations:" << ITERATIONS;
        qDebug() << "The sub process, on average, took" << (sumsub/ITERATIONS) / 1000000.0  << "milliseconds";
        qDebug() << "The full calculation, on average, took" << (sumtot/ITERATIONS) / 1000000.0  << "milliseconds" << endl;
    }

}


}
