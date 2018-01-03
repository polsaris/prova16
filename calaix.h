#ifndef CALAIX_H
#define CALAIX_H

#include <QWidget>
#include <QTimer>
#include <QTime>

class calculadora;
class Calendari;
class Opcions;
class Cronometre;
namespace Ui {
class calaix;
}

class calaix : public QWidget
{
    Q_OBJECT

public:
    explicit calaix(QWidget *parent = 0);
    ~calaix();



private slots:
    void on_calculadora_clicked();

    void on_p_3_clicked();

    void on_p_7_clicked();

    void on_pb_rdigital_clicked();


    void on_p_6_clicked();

    void on_p_4_clicked();

    void on_p_5_clicked();

    void on_p_8_clicked();

    void on_p_9_clicked();

    void on_cronometre_clicked();

private:
    Ui::calaix *ui;
    calculadora *calculadoraa;
    Opcions *opcions;
    Calendari *calendari;
    Cronometre *cronometre;


};

#endif // CALAIX_H
