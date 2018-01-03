#include "opiwatch.h"
#include "ui_opiwatch.h"
#include "analogclock.h"
#include "calaix.h"
#include "rdigital.h"
#include <QtDebug>
#include <QPushButton>
#include <QTimer>
#include <QPixmap>
#include <QLabel>

OpiWatch::OpiWatch(QWidget *parent) :
    QWidget(parent),
  ui(new Ui::OpiWatch)
{

    ui->setupUi(this);

    analogClock = new AnalogClock(this);
    rdigital = new RDigital(this);
    rdigital->hide();
    calaixx = new calaix(this);
    calaixx->hide();


}

