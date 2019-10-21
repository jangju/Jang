#include "mainwindow.h"
#include "gamerules.h"
#include "rule.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gamerules g;
    g.show();
    //MainWindow w;
    //w.show();




    return a.exec();
}
