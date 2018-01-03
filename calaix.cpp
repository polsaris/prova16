#include "calaix.h"
#include "ui_calaix.h"
#include "calculadora.h"
#include "ui_calculadora.h"
#include "calendari.h"
#include "ui_calendari.h"
#include "ui_opcions.h"
#include "cronometre.h"
#include <QProcess>


calaix::calaix(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::calaix)
{
    ui->setupUi(this);
    calculadoraa = new calculadora(this);
    calculadoraa->close();
    calendari = new Calendari(this);
    calendari->close();
    cronometre = new Cronometre(this);
    cronometre->close();

    ui->p_6->setIcon(QIcon("/home/pi/prova16/imatges/chrome.jpg"));
    ui->p_6->setIconSize(QSize(110,110));

    ui->p_3->setIcon(QIcon("/home/pi/prova16/imatges/calendari.png"));
    ui->p_3->setIconSize(QSize(71,71));

    ui->p_4->setIcon(QIcon("/home/pi/prova16/imatges/facebook_blanc.jpg"));
    ui->p_4->setIconSize(QSize(71,71));

    ui->p_5->setIcon(QIcon("/home/pi/prova16/imatges/youtube_blanc.jpg"));
    ui->p_5->setIconSize(QSize(71,71));

    ui->p_7->setIcon(QIcon("/home/pi/prova16/imatges/settings_blanc.png"));
    ui->p_7->setIconSize(QSize(71,71));

    ui->p_8->setIcon(QIcon("/home/pi/prova16/imatges/twitter_blanc.png"));
    ui->p_8->setIconSize(QSize(71,71));

    ui->p_9->setIcon(QIcon("/home/pi/prova16/imatges/raspbian_blanc.png"));
    ui->p_9->setIconSize(QSize(71,71));

    ui->calculadora->setIcon(QIcon("/home/pi/prova16/imatges/calculadora_blanc.png"));
    ui->calculadora->setIconSize(QSize(71,71));

    ui->cronometre->setIcon(QIcon("/home/pi/prova16/imatges/cronometre.svg"));
    ui->cronometre->setIconSize(QSize(71,71));


    ui->pb_rdigital->setIcon(QIcon("/home/pi/prova16/imatges/dretabo.png"));
    ui->pb_rdigital->setIconSize(QSize(65,320));

}



calaix::~calaix()
{
    delete ui;
}



void calaix::on_calculadora_clicked()
{
    calculadoraa->show();

}

void calaix::on_p_3_clicked()
{
    calendari->show();
}

void calaix::on_p_7_clicked()
{
    QProcess *proc = new QProcess(this);
    proc->start("rc_gui");
}

void calaix::on_pb_rdigital_clicked()
{
    close();
}



void calaix::on_p_6_clicked()
{
    QProcess *proc = new QProcess(this);
    proc->start("chromium-browser");
}

void calaix::on_p_4_clicked() {  //Facebook
    QProcess *proc = new QProcess(this);
    proc->start("chromium-browser facebook.com");
}

void calaix::on_p_5_clicked() //YT
{
    QProcess *proc = new QProcess(this);
    proc->start("chromium-browser youtube.com");
}

void calaix::on_p_8_clicked() //Twitter
{
    QProcess *proc = new QProcess(this);
    proc->start("chromium-browser twitter.com");
}

void calaix::on_p_9_clicked()
{
    exit(1);
}

void calaix::on_cronometre_clicked()
{
    cronometre->show();
}
