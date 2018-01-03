#ifndef CALAIX2_H
#define CALAIX2_H

#include <QWidget>
#include <QTimer>
#include <QTime>

class calculadora;
class Calendari;
class Opcions;
class Cronometre;
namespace Ui {
class calaix2;
}

class calaix2 : public QWidget
{
    Q_OBJECT

public:
    explicit calaix2(QWidget *parent = 0);
    ~calaix2();



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
    Ui::calaix2 *ui;
    calculadora *calculadoraa;
    Opcions *opcions;
    Calendari *calendari;
    Cronometre *cronometre;


};

#endif // CALAIX2_H
