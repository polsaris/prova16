#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>
#include <QTimer>
#include <QTime>
class calaix2;
class RDigital;
namespace Ui {
class AnalogClock;
}

class AnalogClock : public QWidget
{
    Q_OBJECT
    
public:
    explicit AnalogClock(QWidget *parent = 0);
    ~AnalogClock();
    QTimer *timer;
    QTime time;
protected:
    void paintEvent(QPaintEvent *event);
private slots:

    void on_pb_rdigital_clicked();

    void on_pb_calaix_clicked();

    void data_avui();

private:
    Ui::AnalogClock *ui;
    calaix2 *calaixx2;
    RDigital *rdigital;
};

#endif // ANALOGCLOCK_H
