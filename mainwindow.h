#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "choose.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_cal_selectionChanged();

    void on_addBtn_clicked();

    void on_delBtn_clicked();

    void on_list_doubleClicked(const QModelIndex &index);

    void receiveData(QString data);

private:
    Ui::MainWindow *ui;
    int index=1;
};

#endif // MAINWINDOW_H
