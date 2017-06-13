#include "choose.h"
#include "ui_choose.h"

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
