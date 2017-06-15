#include "choose.h"
#include "ui_choose.h"
#include "direction.h"
#include "audiorecorder.h"

#include <QApplication>
#include <QWebEngineView>
#include <QtSql>

choose::choose(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::choose)
{
    ui->setupUi(this);
    this->setWindowTitle("Edit Item");
    if(isAdd == true)
    {
        ui->timeFrom->setTime(QTime::currentTime());
        ui->timeTo->setDateTime(QDateTime::currentDateTime());
    }
}

choose::~choose()
{
    delete ui;
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
    QString ss;

    if(isAdd) // insert into List
    {
        ss = "INSERT INTO List values('" + title + "', '" + startTime + "', '" + endDateTime + "', '" + curLocation + "', '" + des + "', '" + note + "')";
        query.exec(ss);

        emit sendData(ui->title->text());
        this->close();
    }
    else // update
    {
        ss = "update List set startTime = '" + startTime + "', endDateTime = '" + endDateTime + "', curLocation = '" + curLocation + "', destination = '" + des + "', note = '" + note + "' where title = '" + title + "'";
        query.exec(ss);
        this->close();
    }
}

void choose::on_dirBtn_clicked()
{
    direction *dir = new direction;
    dir->set_start(ui->LocationFrom->text());
    dir->set_des(ui->LocationTo->text());
    dir->show_direction();
    dir->show();
}

void choose::on_recBtn_clicked()
{
    AudioRecorder *recorder = new AudioRecorder;
    recorder->show();
}

void choose::setting(QString title, QTime startTime, QDateTime endDateTime, QString curLocation, QString destination, QString note)
{
    ui->title->setText(title);
    ui->timeFrom->setTime(startTime);
    ui->timeTo->setDateTime(endDateTime);
    ui->LocationFrom->setText(curLocation);
    ui->LocationTo->setText(destination);
    ui->note->setText(note);
    ui->title->setDisabled(true);
}
