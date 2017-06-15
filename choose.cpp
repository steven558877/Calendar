#include "choose.h"
#include "ui_choose.h"
#include "direction.h"

#include <QApplication>
#include <QWebEngineView>
#include <QtSql>

choose::choose(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::choose)
{
    ui->setupUi(this);
    this->setWindowTitle("Edit Item");
    ui->timeFrom->setTime(QTime::currentTime());
    ui->timeTo->setDateTime(QDateTime::currentDateTime());
}

choose::~choose()
{
    delete ui;
}

void choose::on_rec_clicked()
{

}

void choose::on_okBtn_clicked()
{
    QSqlQuery query;
    QString title = ui->title->text();
    QString startTime = ui->timeFrom->time().toString();
    QString endDateTime = ui->timeTo->dateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString curLocation = ui->LocationFrom->text();
    QString des = ui->LocationTo->text();
    QString note = ui->note->toPlainText();

    QString ss = "INSERT INTO List values('" + title + "', '" + startTime + "', '" + endDateTime + "', '" + curLocation + "', '" + des + "', '" + note + "')";
    query.exec(ss);

    emit sendData(ui->title->text());
    this->close();
}

void choose::on_dirBtn_clicked()
{
    direction *dir = new direction;
    dir->set_start(ui->LocationFrom->text());
    dir->set_des(ui->LocationTo->text());
    dir->show_direction();
    dir->show();
}
