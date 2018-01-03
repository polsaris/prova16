#include "calculadora.h"
#include "ui_calculadora.h"

double firstNum;
bool userIsTypingSecondNumber = false;
calculadora::calculadora(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::calculadora)
{
    ui->setupUi(this);

    connect(ui->p0,SIGNAL(released()),this,SLOT(digit_pitjat()));
    connect(ui->p1,SIGNAL(released()),this,SLOT(digit_pitjat()));
    connect(ui->p2,SIGNAL(released()),this,SLOT(digit_pitjat()));
    connect(ui->p3,SIGNAL(released()),this,SLOT(digit_pitjat()));
    connect(ui->p4,SIGNAL(released()),this,SLOT(digit_pitjat()));
    connect(ui->p5,SIGNAL(released()),this,SLOT(digit_pitjat()));
    connect(ui->p6,SIGNAL(released()),this,SLOT(digit_pitjat()));
    connect(ui->p7,SIGNAL(released()),this,SLOT(digit_pitjat()));
    connect(ui->p8,SIGNAL(released()),this,SLOT(digit_pitjat()));
    connect(ui->p9,SIGNAL(released()),this,SLOT(digit_pitjat()));

    connect(ui->mesmenys,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->percentatge,SIGNAL(released()),this,SLOT(unary_operation_pressed()));

     connect(ui->sumar,SIGNAL(released()),this,SLOT(operacio()));
     connect(ui->restar,SIGNAL(released()),this,SLOT(operacio()));
     connect(ui->multiplicar,SIGNAL(released()),this,SLOT(operacio()));
     connect(ui->dividir,SIGNAL(released()),this,SLOT(operacio()));

     ui->sumar->setCheckable(true);
     ui->restar->setCheckable(true);
     ui->multiplicar->setCheckable(true);
     ui->dividir->setCheckable(true);

}

calculadora::~calculadora()
{
    delete ui;
}

void calculadora::on_tanca_calculadora_clicked()
{
    close();
}

void calculadora::digit_pitjat() {
    QPushButton *button = (QPushButton*)sender();
    double labelNumber;
    QString newLabel;


    if ((ui->sumar->isChecked() || ui->restar->isChecked()
            || ui->multiplicar->isChecked() || ui->dividir->isChecked()) && (!userIsTypingSecondNumber)) {
        labelNumber = button->text().toDouble();
        userIsTypingSecondNumber = true;
        newLabel = QString::number(labelNumber,'g',15);
    }
    else {
        if (ui->label->text().contains('.') && button->text() == "0") {
            newLabel = ui->label->text() + button->text();
        }
        else {
        labelNumber = (ui->label->text() + button->text()).toDouble();
        newLabel = QString::number(labelNumber,'g',15);
    }


}
 ui->label->setText(newLabel);
}

void calculadora::on_punt_released()
{
    ui->label->setText(ui->label->text() + ".");
}

void calculadora::unary_operation_pressed() {

    QPushButton *button = (QPushButton*)sender();
    double labelNumber;
    QString newLabel;

    if (button->text() == "+/-") {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }
    else if (button->text() == "%") {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
}

}

void calculadora::on_reset_released()
{
    ui->sumar->setChecked(false);
    ui->restar->setChecked(false);
    ui->multiplicar->setChecked(false);
    ui->dividir->setChecked(false);

    userIsTypingSecondNumber = false;

    ui->label->setText("0");

}

void calculadora::on_igual_released()
{
    double labelNumber, secondNum;
    QString newLabel;

    secondNum = ui->label->text().toDouble();

    if (ui->sumar->isChecked()) {
        labelNumber = firstNum + secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->sumar->setChecked(false);
    }
    else if (ui->restar->isChecked()) {
        labelNumber = firstNum - secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->restar->setChecked(false);

    }
   else if (ui->multiplicar->isChecked()) {
        labelNumber = firstNum * secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->multiplicar->setChecked(false);
    }
    else if (ui->dividir->isChecked()) {
        labelNumber = firstNum / secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->dividir->setChecked(false);
    }

    userIsTypingSecondNumber = false;
}



void calculadora::operacio() {
    QPushButton *button = (QPushButton*)sender();
    firstNum = ui->label->text().toDouble();

    button->setChecked(true);


}

