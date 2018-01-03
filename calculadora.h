#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <QMainWindow>

namespace Ui {
class calculadora;
}

class calculadora : public QWidget
{
    Q_OBJECT

public:
    explicit calculadora(QWidget *parent = 0);
    ~calculadora();

private slots:
    void on_tanca_calculadora_clicked();
    void digit_pitjat();

    void on_punt_released();
    void unary_operation_pressed();

    void on_reset_released();

    void operacio();

    void on_igual_released();

private:
    Ui::calculadora *ui;
};

#endif // CALCULADORA_H
