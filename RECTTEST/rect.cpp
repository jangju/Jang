#include "rect.h"
#include "ui_rect.h"
#include <QRect>
#include <QDebug>
#include <QPainter>
Rect::Rect(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Rect)
{
    ui->setupUi(this);

}

Rect::~Rect()
{
    delete ui;
}

void Rect::on_Dreawing_button_clicked()
{

    X=ui->lineEdit_X->text().toInt();
    Y=ui->lineEdit_X->text().toInt();
    Right=ui->lineEdit_X->text().toInt();
    Bottom=ui->lineEdit_X->text().toInt();
    QPainter painter(this);
    painter.begin(this);
    painter.setPen(QPen(Qt::black,5));
    painter.drawRect(X,Y,Right,Bottom);

}
