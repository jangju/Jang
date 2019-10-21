#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>

class test : public QObject
{
    Q_OBJECT

public:
    explicit test(QObject *parent = nullptr);

private:

    int i,n;
    int dice[6];




};

#endif // TEST_H
