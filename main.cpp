#include "mainwindow.h"
#include <QApplication>
#include "rect.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    //Rect rec;
    //rec.show();

    return a.exec();
}
