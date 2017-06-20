#include "choose.h"
#include "ui_choose.h"
#include "direction.h"
#include "audiorecorder.h"

#include <QApplication>
#include <QWebEngineView>
#include <QtSql>
#include <QTimer>
#include <QProcess>
#include <QMessageBox>

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
    QString endTime = ui->timeTo->time().toString();
    QString curLocation = ui->LocationFrom->text();
    QString des = ui->LocationTo->text();
    QString note = ui->note->toPlainText();
    QString ss, s2;
    QString alarm = ui->alarm->text();
    QString alarmTime = startTime;
    QString tmp_Hour1,tmp_Hour2;
    QString tmp_Min1,tmp_Min2;
    QString startTime_30 = ui->timeFrom->time().addSecs(-30 * 60).toString();
    QString endTime_30 = ui->timeTo->time().addSecs(30 * 60).toString();
    qDebug() << startTime_30 << endTime_30 << endTime;
    QString startDateTime = curDate + " " + startTime;
    QString startDateTime_30 = curDate + " " +startTime_30;
    tmp_Hour1= startTime[0];
    tmp_Hour2= startTime[1];

    tmp_Min1 = startTime[3];
    tmp_Min2 = startTime[4];

    int hour = tmp_Hour1.toInt()*10 + tmp_Hour2.toInt();
    int Min = tmp_Min1.toInt()*10 + tmp_Min2.toInt();
    int alarm_int = alarm.toInt();

    if(alarm_int-Min>0)
    {
        hour -= 1;
        Min = Min + 60 - alarm_int;
    }
    else
    {
        Min -= alarm_int;
    }
    tmp_Hour1 = QString(hour/10+48);
    tmp_Hour2 = QString(hour%10+48);

    tmp_Min1 = QString(Min/10+48);
    tmp_Min2 = QString(Min%10+48);


    alarmTime.replace(0,1,tmp_Hour1);
    alarmTime.replace(1,1,tmp_Hour2);

    alarmTime.replace(3,1,tmp_Min1);
    alarmTime.replace(4,1,tmp_Min2);


    ss = "select * from List where startDate = '" + curDate + "' and endDateTime between '" + startDateTime_30 + "' and '" + startDateTime + "'";
    s2 = "select * from List where startDate = '" + curDate + "' and startTime between '" + endTime + "' and '" + endTime_30 + "'";
    query.exec(ss);
    bool exist1 = query.first();
    qDebug() <<  query.value(0);
    query.exec(s2);
    bool exist2 = query.first();
    qDebug() <<  query.value(0);
    if(exist1 || exist2)
    {
        switch(QMessageBox::warning(NULL,"Warning","時間與其他行程太過相近，是否確認要送出?",QMessageBox::Yes|QMessageBox::No))
        {
            case QMessageBox::Yes:
                {
                    if(isAdd) // insert into List
                    {
                        ss = "INSERT INTO List values('" + title + "', '" + curDate + "', '" + startTime + "', '" + endDateTime + "', '" + curLocation + "', '" + des + "', '" + note + "', '" + alarm + "')";
                        qDebug() << ss;
                        query.exec(ss);

                        emit sendData(ui->title->text());
                        //
                        QProcess *p1 = new QProcess();
                        p1->start("bash /home/erer/Calendar/set_alarm.sh "+ title + " " + curDate + " " + startTime + " " + endDateTime + " " + curLocation + " "+ des + " " + note + " " + alarmTime);
                        //
                        this->close();
                    }
                    else // update
                    {
                        ss = "update List set startTime = '" + startTime + "', endDateTime = '" + endDateTime + "', curLocation = '" + curLocation + "', destination = '" + des + "', note = '" + note + "', alarm = '" + alarm + "' where title = '" + title + "'";
                        qDebug() << ss;
                        query.exec(ss);
                        this->close();
                    }
                    break;
                }
            case QMessageBox::No:
                //按下放棄鍵後的處理
                break;
            default:
                break;
        }
    }
    else
    {
        if(isAdd) // insert into List
        {
            ss = "INSERT INTO List values('" + title + "', '" + curDate + "', '" + startTime + "', '" + endDateTime + "', '" + curLocation + "', '" + des + "', '" + note + "', '" + alarm + "')";
            qDebug() << ss;
            query.exec(ss);

            emit sendData(ui->title->text());
            //
            QProcess *p1 = new QProcess();
            p1->start("bash /home/erer/Calendar/set_alarm.sh "+ title + " " + curDate + " " + startTime + " " + endDateTime + " " + curLocation + " "+ des + " " + note + " " + alarmTime);
            //
            this->close();
        }
        else // update
        {
            ss = "update List set startTime = '" + startTime + "', endDateTime = '" + endDateTime + "', curLocation = '" + curLocation + "', destination = '" + des + "', note = '" + note + "', alarm = '" + alarm + "' where title = '" + title + "'";
            qDebug() << ss;
            query.exec(ss);
            this->close();
        }
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

    QString title = ui->title->text();
    AudioRecorder *recorder = new AudioRecorder;
    recorder->set_Name(title);
    recorder->show();

}

void choose::setting(QString title, QTime startTime, QDateTime endDateTime, QString curLocation, QString destination, QString note, QString alarm)
{
    ui->title->setText(title);
    ui->timeFrom->setTime(startTime);
    ui->timeTo->setDateTime(endDateTime);
    ui->LocationFrom->setText(curLocation);
    ui->LocationTo->setText(destination);
    ui->note->setText(note);
    ui->title->setDisabled(true);
    ui->alarm->setText(alarm);
}

void choose::get_curDate(QString input)
{
    curDate = input;
}
