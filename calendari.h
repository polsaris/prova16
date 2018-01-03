#ifndef CALENDARI_H
#define CALENDARI_H

#include <QWidget>

namespace Ui {
class Calendari;
}

class Calendari : public QWidget
{
    Q_OBJECT

public:
    explicit Calendari(QWidget *parent = 0);
    ~Calendari();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Calendari *ui;
};

#endif // CALENDARI_H
