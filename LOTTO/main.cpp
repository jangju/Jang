#include "lotto.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    lotto w;
    w.show();

    return a.exec();
}
