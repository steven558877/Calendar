#ifndef CHOOSE_H
#define CHOOSE_H

#include <QMainWindow>

namespace Ui {
class choose;
}

class choose : public QMainWindow
{
    Q_OBJECT

public:
    explicit choose(QWidget *parent = 0);
    ~choose();
    void setting(QString, QTime, QDateTime, QString, QString, QString, QString);
    bool isAdd = true; // true -> add, false -> edit
    void get_curDate(QString);

private slots:

    void on_okBtn_clicked();

    void on_dirBtn_clicked();

    void on_recBtn_clicked();

signals:
    void sendData(QString);

private:
    Ui::choose *ui;
    QString curDate;
};

#endif // CHOOSE_H
