#include "choose.h"
#include "ui_choose.h"
#include "direction.h"

#include <QApplication>
#include <QWebEngineView>

choose::choose(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::choose)
{
    ui->setupUi(this);
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
