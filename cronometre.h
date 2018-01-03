#ifndef CRONOMETRE_H
#define CRONOMETRE_H
#include <QTime>
#include <QTimer>
#include <QWidget>

namespace Ui {
class Cronometre;
}

class Cronometre : public QWidget
{
    Q_OBJECT
    QTime startTime;
    QTime *tempsAra;
    QTimer t;

public:
    explicit Cronometre(QWidget *parent = 0);
    ~Cronometre();

private slots:
    void updateTime();
    void start();

    void on_b_stop_clicked();

    void on_b_start_2_clicked();

private:
    Ui::Cronometre *ui;
};

#endif // CRONOMETRE_H
