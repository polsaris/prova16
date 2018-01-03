#ifndef OPIWATCH_H
#define OPIWATCH_H

#include <QWidget>
#include <QtNetwork>
#include <QPushButton>
#include <QFileSystemWatcher>
#include <QLabel>
#include <QTime>
#include <QDate>

class AnalogClock;
class calaix;
class RDigital;

namespace Ui {
class OpiWatch;
}
class OpiWatch : public QWidget
{
    Q_OBJECT
    
public:
    OpiWatch(QWidget *parent = 0);



    private:
    QTime *time;
    QDate *date;
    Ui::OpiWatch *ui;
    AnalogClock *analogClock;
    calaix *calaixx;
    RDigital *rdigital;


};

#endif // OPIWATCH_H
