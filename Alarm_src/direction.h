#ifndef DIRECTION_H
#define DIRECTION_H

#include <QMainWindow>

namespace Ui {
class direction;
}

class direction : public QMainWindow
{
    Q_OBJECT

public:
    explicit direction(QWidget *parent = 0);
    ~direction();
    void set_start(QString);
    void set_des(QString);
    void show_direction();

private:
    Ui::direction *ui;
    QString start;
    QString destination;
};

#endif // DIRECTION_H
