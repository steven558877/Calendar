#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSound>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void set_arg(QString ,QString ,QString ,QString,QString,QString,QString,QString);
    void play_rec();

private slots:
    void on_pushButton_clicked();


    void on_DirBtn_clicked();

private:
    QString argument[8];
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
