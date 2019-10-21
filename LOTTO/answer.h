#ifndef ANSWER_H
#define ANSWER_H

#include <QObject>
#include <QDebug>

class answer : public QObject
{
    Q_OBJECT
public:
    explicit answer(QObject *parent = nullptr);
    answer(int size);




    void popBack();
    void pushBack(int data);
    void print();
    int &operator[](int index);

private:
    int num1,num2;
};

#endif // ANSWER_H
