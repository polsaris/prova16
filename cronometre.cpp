#include "cronometre.h"
#include "ui_cronometre.h"
#include <QTimer>
#include <QTime>

Cronometre::Cronometre(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cronometre)
{

    ui->setupUi(this);
    connect(&t, SIGNAL(timeout()), this, SLOT(updateTime()));
    connect(ui->b_start, SIGNAL(clicked(bool)), this, SLOT(start()));



}

Cronometre::~Cronometre()
{
    delete ui;
}


void Cronometre::updateTime() {

    ui->label->setText(QTime(0,0).addMSecs(startTime.elapsed()).toString());
}

void Cronometre::start() {
      ui->label->setText(QTime(0, 0).toString());
      startTime.start();
      t.start(1000);
      QString restart = "RESTART";
      ui->b_start->setText(restart);
    }




void Cronometre::on_b_stop_clicked()
{
t.stop();
QString sstart = "START";
ui->b_start->setText(sstart);

}

void Cronometre::on_b_start_2_clicked()
{
    close();
}
