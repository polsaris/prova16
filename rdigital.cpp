#include "rdigital.h"
#include "ui_rdigital.h"
#include <QTime>
#include <QTimer>
#include <QDate>
#include "calaix.h"
#include <QPainter>


RDigital::RDigital(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RDigital)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
    data_avui();

    calaixx = new calaix(this);
    calaixx->close();


    QFont f("Ubuntu",20,50,QFont::Bold);      //font de la data
    ui->label_2->setFont(f);
    RDigital::setStyleSheet("background-color:white;");      //color fons
    fontNormal();

    ui->pushButton->hide();
    ui->pushButton_4->hide();
    ui->c_blanc->hide();

    botons();


}

RDigital::~RDigital()
{
    delete ui;
}



void RDigital::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    QString text2 = time.toString("ss");
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    ui->label->setText(text);
    ui->label_3->setText(text2);
}

void RDigital::data_avui() {
    QDate date = QDate::currentDate();
        QString s = date.toString("dddd/MMMM/yyyy");
        ui->label_2->setText(s);

}

void RDigital::fontDigital() {
    QFont digital("Segment7",47,QFont::Bold);
    QFont digitalss("Segment7",27,QFont::Bold);
    ui->label->setFont(digital);
    ui->label_3->setFont(digitalss);
}

void RDigital::fontNormal() {
    QFont normal("Ubuntu",50,10,QFont::Bold);
    QFont normalss("Ubuntu",30,10,QFont::Bold);
    ui->label->setFont(normal);
    ui->label_3->setFont(normalss);
}


void RDigital::on_pushButton_clicked()
{
    fontNormal();
    ui->pushButton_2->show();
    ui->pushButton->hide();
}

void RDigital::on_pushButton_2_clicked()
{
    fontDigital();
    ui->pushButton->show();
    ui->pushButton_2->hide();

}

void RDigital::on_pushButton_3_clicked()
{
    QDate date = QDate::currentDate();
        QString s = date.toString("dd/MM/yy");
        ui->label_2->setText(s);
        QFont f("Ubuntu",30,50,QFont::Bold);      //font de la data
        ui->label_2->setFont(f);

        ui->pushButton_4->show();
        ui->pushButton_3->hide();

}

void RDigital::on_pushButton_4_clicked()
{
    QDate date = QDate::currentDate();
        QString s = date.toString("dddd/MMMM/yyyy");
        ui->label_2->setText(s);
        QFont f("Ubuntu",20,50,QFont::Bold);      //font de la data
        ui->label_2->setFont(f);

        ui->pushButton_3->show();
        ui->pushButton_4->hide();


}


void RDigital::on_pb_calaix_clicked()
{
    calaixx->show();
}

void RDigital::on_pb_analogclock_clicked()
{
    close();
}

void RDigital::color_negre() {
    ui->label->setStyleSheet("QLabel { color : white; }");
    ui->centralWidget->setStyleSheet("QWidget {background-color : black;}");
    ui->label_2->setStyleSheet("QLabel { color : white; }");
    ui->label_3->setStyleSheet("QLabel { color : white; }");
}

void RDigital::color_blanc() {
    ui->label->setStyleSheet("QLabel { color : black; }");
    ui->centralWidget->setStyleSheet("QWidget {background-color : white;}");
    ui->label_2->setStyleSheet("QLabel { color : black; }");
    ui->label_3->setStyleSheet("QLabel { color : black; }");
}

void RDigital::on_c_negre_clicked()
{
    color_negre();
    ui->c_blanc->show();
    ui->c_negre->hide();
    ui->pushButton->setStyleSheet("border: 1px solid white;");
    ui->pushButton_2->setStyleSheet("border: 1px solid white;");
    ui->pushButton_3->setStyleSheet("border: 1px solid white;");
    ui->pushButton_4->setStyleSheet("border: 1px solid white;");
    ui->c_blanc->setStyleSheet("border: 1px solid white;");
    ui->c_negre->setStyleSheet("border: 1px solid white;");
}

void RDigital::on_c_blanc_clicked()
{
    color_blanc();
    ui->c_negre->show();
    ui->c_blanc->hide();
    ui->pushButton->setStyleSheet("");
    ui->pushButton_2->setStyleSheet("");
    ui->pushButton_3->setStyleSheet("");
    ui->pushButton_4->setStyleSheet("");
    ui->c_blanc->setStyleSheet("");
    ui->c_negre->setStyleSheet("");
}

void RDigital::botons() {
    ui->c_blanc->setIcon(QIcon("/home/pi/prova16/imatges/blanc4.jpeg"));
    ui->c_blanc->setIconSize(QSize(65,65));

    ui->c_negre->setIcon(QIcon("/home/pi/prova16/imatges/negre2.png"));
    ui->c_negre->setIconSize(QSize(65,65));

    ui->pushButton->setIcon(QIcon("/home/pi/prova16/imatges/fontubuntu2.png"));
    ui->pushButton->setIconSize(QSize(65,65));

    ui->pushButton_2->setIcon(QIcon("/home/pi/prova16/imatges/7segment.jpg"));
    ui->pushButton_2->setIconSize(QSize(65,65));

    ui->pushButton_4->setIcon(QIcon("/home/pi/prova16/imatges/datalletres2.jpg"));
    ui->pushButton_4->setIconSize(QSize(65,65));

    ui->pushButton_3->setIcon(QIcon("/home/pi/prova16/imatges/datanum.jpg"));
    ui->pushButton_3->setIconSize(QSize(65,65));

    ui->pb_analogclock->setIcon(QIcon("/home/pi/prova16/imatges/dretabo.png"));
    ui->pb_analogclock->setIconSize(QSize(65,320));

    ui->pb_calaix->setIcon(QIcon("/home/pi/prova16/imatges/esquerra.png"));
    ui->pb_calaix->setIconSize(QSize(65,320));


}
