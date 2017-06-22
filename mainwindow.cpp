#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QtSql>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Desktop Calendar Advanced Edition");
    ui->curDate->setText(ui->cal->selectedDate().toString("yyyy 年 MM 月 dd 日"));
    curDate = ui->cal->selectedDate().toString("yyyy-MM-dd");
    createConnection();

    //
    QSqlQuery query;
    QString ss = "SELECT * FROM List where startDate = '" + curDate + "'";
    query.exec(ss);

    ui->list->clear();
    int i = 0;
    while(query.next())
    {
        ui->list->insertItem(i, query.value(0).toString());
        i += 1;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_cal_selectionChanged()
{
    ui->curDate->setText(ui->cal->selectedDate().toString("yyyy 年 MM 月 dd 日"));
    curDate = ui->cal->selectedDate().toString("yyyy-MM-dd");

    QSqlQuery query;
    QString ss = "SELECT * FROM List where startDate = '" + curDate + "'";
    query.exec(ss);

    ui->list->clear();
    int i = 0;
    while(query.next())
    {
        ui->list->insertItem(i, query.value(0).toString());
        i += 1;
    }

}

void MainWindow::on_addBtn_clicked() // add item
{
    choose *ch = new choose;
    ch->isAdd = true; // add item
    connect(ch, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
    ch->get_curDate(curDate);
    ch->show();
}

void MainWindow::on_delBtn_clicked() // delete item
{
    int i = ui->list->currentRow();
    if(i != -1)
    {
        QSqlQuery query;
        QString title = ui->list->item(i)->text();
        QString ss = "delete from List where title = '" + title + "'and startDate = '" + curDate + "'";
        qDebug() << ss;
        query.exec(ss);

        delete ui->list->item(i);
    }

}

void MainWindow::on_list_doubleClicked(const QModelIndex &index)
{
    int i = ui->list->currentRow();
    QString title = ui->list->item(i)->text();
    QSqlQuery query;
    QString ss = "SELECT * FROM List where title = '" + title + "'and startDate = '" + curDate + "'";
    query.exec(ss);
    query.first();

    QString title2 = query.value(0).toString();
    QTime startTime = query.value(2).toTime();
    QDateTime endDateTime = query.value(3).toDateTime();
    QString curLocation = query.value(4).toString();
    QString destination = query.value(5).toString();
    QString note = query.value(6).toString();
    QString alarm = query.value(7).toString();

    choose *ch = new choose;
    ch->setting(title2, startTime, endDateTime, curLocation, destination, note, alarm);
    ch->get_curDate(curDate);
    ch->isAdd = false; // edit item
    ch->show();
}

void MainWindow::receiveData(QString data)
{
    ui->list->insertItem(index, data);
    index += 1;
}

void MainWindow::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":data:");

    if (!db.open()) {
        qFatal("Cannot open database");
        return;
    }

    QSqlQuery query;
    //query.exec("create table List (title TEXT, startTime TIME, endDateTime TIMESTAMP, curLocation TEXT, destination TEXT, note TEXT)");
    query.exec("create table List (title TEXT, startDate DATE, startTime TIME, endDateTime TIMESTAMP, curLocation TEXT, destination TEXT, note TEXT, alarm TEXT)");


    return;
}

/*
void MainWindow::on_test_clicked()
{
    QSqlQuery query;
    query.exec("drop table List");
}

void MainWindow::on_check_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM List");
    qDebug() << "----check----";
    while(query.next())
    {
        qDebug() << query.value(0).toString() <<
                    query.value(1).toString() <<
                    query.value(2).toString() <<
                    query.value(3).toString() <<
                    query.value(4).toString() <<
                    query.value(5).toString() <<
                    query.value(6).toString() <<
                    query.value(7).toString();

    }
    qDebug() << "----data finish----";
}

void MainWindow::on_re_clicked()
{
    createConnection();
}
*/
