#include "test.h"
#include "mainwindow.h"

#include <QDebug>
test::test(QObject *parent) : QObject(parent)
{
    for(i=0;i<6;++i)
    {
        dice[i] = 0;
    }
    for(i=1;i<101;i++){
        n=rand()%6+1;
                dice[n-1]+=1;
    }
    for(i=0;i<6;i++)
    {
        qDebug()<<("[%d]=%d\n",i+1,dice[i]);
    }

}



