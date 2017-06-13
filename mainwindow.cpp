#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->curDate->setText(ui->cal->selectedDate().toString("yyyy年MM月dd日"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_cal_selectionChanged()
{
    ui->curDate->setText(ui->cal->selectedDate().toString("yyyy年MM月dd日"));
}

void MainWindow::on_addBtn_clicked() // add item
{
    choose *ch = new choose;
    connect(ch, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
    ch->show();
}

void MainWindow::on_delBtn_clicked() // delete item
{
    int i = ui->list->currentRow();
    delete ui->list->item(i);
}

void MainWindow::on_list_doubleClicked(const QModelIndex &index)
{
    // map
}

void MainWindow::receiveData(QString data)
{
    ui->list->insertItem(index, data);
    index += 1;
}





