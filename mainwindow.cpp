#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rect.h"
#include "ICON.h"

#include <QDebug>
#include <QPainter>
#include <QTimer>
#define BG_WINDOW "/home/lubuntu/recttest/Image/window.png"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //setWindowFlags(Qt::CustomizeWindowHint);//윈도우 프레임을 없애는 함수

    QPalette pal = palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap(BG_WINDOW)));//윈도우 배경 출력
    setPalette(pal);

    new ICON(this);
    // (new Rect(this))->show();
    ////////////타이머 멈춤///////////////
    screen_timer = new QTimer(this);
    connect(screen_timer, SIGNAL(timeout()), this, SLOT(timer_Screen_Stop()));

}

/*
void MainWindow::paintEvent(QPaintEvent *)//프로그램이 돌아가는동안 이벤트는 계속
{
     QPainter painter(this);
//  painter.drawPixmap(0 ,0, QPixmap(window));//윈도우 배경 출력
    painter.setPen(QColor(Qt::red));
    //painter.drawRect(28, 298, 54, 54);

    painter.setPen(QColor(Qt::green));
    painter.drawRect(28, 358, 54, 54);

    painter.setPen(QColor(Qt::yellow));
    painter.drawRect(28, 418, 54, 54);

    painter.setPen(QColor(Qt::gray));
    painter.drawRect(28, 478, 54, 54);

    qDebug()<<"====================================";

}
*/
void MainWindow::timer_Screen_Stop()
{
    if(b_once_setup)
    {
        b_once_setup = false;
        screen_timer->stop();
    }
}
void MainWindow::mousePressEvent(QMouseEvent *me)
{
    if(me->button() != Qt::LeftButton) return;//마우스 왼쪽버튼 실행

    bt_1.setRect(28, 298, 54, 54);
    bt_2.setRect(28, 358, 54, 54);
    bt_3.setRect(28, 418, 54, 54);
    bt_4.setRect(28, 478, 54, 54);

    if(bt_1.contains(me->x(), me->y()))
    {

    }
}


void MainWindow::mouseReleaseEvent(QMouseEvent *me)
{
    if(me->button() != Qt::LeftButton) return;//마우스 왼쪽버튼 실행

    bt_1.setRect(28, 298, 54, 54);
    bt_2.setRect(28, 358, 54, 54);
    bt_3.setRect(28, 418, 54, 54);
    bt_4.setRect(28, 478, 54, 54);

    if(bt_1.contains(me->x(), me->y()))
    {

        qDebug()<<"AAAAAAAAAAAAAAAAAAAAAAAAAAA";
        //update(bt_1);
    }
    else if(bt_2.contains(me->x(), me->y()))
    {
        qDebug()<<"BBBBBBBBBBBBBBBBBBBBBBBBBBB";
        //update(bt_2);
    }
    else if(bt_3.contains(me->x(), me->y()))
    {
        qDebug()<<"CCCCCCCCCCCCCCCCCCCCCCCCCCC";
        //update(bt_3);
    }
    else if(bt_4.contains(me->x(), me->y()))
    {
        qDebug()<<"DDDDDDDDDDDDDDDDDDDDDDDDDDD";
        //update(bt_4);
    }
}

void MainWindow::changePage(const int page_number)
{

}

MainWindow::~MainWindow()
{
    //if(screen_timer != nullptr) screen_timer->stop();
    delete ui;
}

