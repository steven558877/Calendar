#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "direction.h"

#include <QWebEngineView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont font = ui->title->font();
    font.setPointSize(30);
    font.setBold(true);
    ui->title->setFont(font);
    this->setWindowTitle("Alarm");

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::set_arg(QString title, QString curDate, QString startTime, QString endDateTime, QString curLocation, QString des, QString note, QString alarmTime)
{
   argument[0]= title;
   argument[1]= curDate;
   argument[2] = startTime;
   argument[3] = endDateTime;
   argument[4] = curLocation;
   argument[5] = des;
   argument[6] = note;
   argument[7] = alarmTime;
   ui->title->setText(argument[0]);
   ui->start_time_content->setText(argument[1]+" "+argument[2]);
   ui->end_time_content->setText(argument[3]);
   ui->From_content->setText(argument[4]);
   ui->To_content->setText(argument[5]);
   ui->note_content->setText(argument[6]);

}
void MainWindow::play_rec()
{

}

void MainWindow::on_pushButton_clicked()
{
    QString user_name = qgetenv("USER");
    QSound::play(QString("/home/"+ user_name +"/Calendar/Record/" + argument[0]+ ".wav"));
}

void MainWindow::on_DirBtn_clicked()
{
    direction *dir = new direction;
    dir->set_start(ui->From_content->text());
    dir->set_des(ui->To_content->text());
    dir->show_direction();
    dir->show();
}
