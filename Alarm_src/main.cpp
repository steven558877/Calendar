#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.set_arg(QString(argv[1]),QString(argv[2]), QString(argv[3]), QString(argv[4]),QString(argv[5]), QString(argv[6]), QString(argv[7]), QString(argv[8]));
    w.show();

    return a.exec();
}
