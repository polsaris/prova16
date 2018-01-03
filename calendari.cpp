#include "calendari.h"
#include "ui_calendari.h"
#include <QPushButton>

Calendari::Calendari(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calendari)
{
    ui->setupUi(this);
}

Calendari::~Calendari()
{
    delete ui;
}


void Calendari::on_pushButton_clicked()
{
    close();
}
