#include "direction.h"
#include "ui_direction.h"
#include <QWebEngineView>
#include <QApplication>
direction::direction(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::direction)
{
    ui->setupUi(this);
    this->setWindowTitle("Google Navigation");
}

direction::~direction()
{
    delete ui;
}

void direction::set_start(QString input)
{
    start = input;
}

void direction::set_des(QString input)
{
    destination = input;
}
void direction::show_direction()
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QString url = "https://www.google.com.tw/maps/dir/"+ start + "/" + destination;
    QWebEngineView *view = new QWebEngineView(this);
    view->load(url);
    // Sets the webview to be the main window's central widget.
    setCentralWidget(view);
}
