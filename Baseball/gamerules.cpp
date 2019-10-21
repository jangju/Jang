#include "gamerules.h"
#include "mainwindow.h"
#include "rule.h"
#include "ui_gamerules.h"

#define BG_BASEBALL "/home/lubuntu/baseball/Image/BG_BASEBALL"
#define START "/home/lubuntu/baseball/Image/start_bt.png"
#define RULE "/home/lubuntu/baseball/Image/rule_bt.png"

gamerules::gamerules(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamerules)
{
    ui->setupUi(this);

    QPalette pal = palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap(BG_BASEBALL)));
    setPalette(pal);

}
void gamerules::paintEvent(QPaintEvent *)
{
    QPainter q(this);
    switch(i_base_image_flag)
    {
    case 0:
        qDebug()<<"PaintEvent";
         break;
    case 1:
        qDebug()<<"VIEW = DEFALT END";
        q.drawPixmap(232, 312, QPixmap(START));
        break;
    case 2:
        qDebug()<<"VIEW = DEFALT TRAST";
        q.drawPixmap(232, 412, QPixmap(RULE));
        break;

        default: break;
    }
    i_base_image_flag = 0;
}

void gamerules::mousePressEvent(QMouseEvent *me)
{
    if(me->button() != Qt::LeftButton) return;

    QRect start_bt(230, 310, 155, 80);//게임시작버튼
    QRect rule_bt(230,  410, 155, 80);//게임방법버튼

    if(start_bt.contains(me->x(), me->y()))
    {
        i_base_image_flag = 1;
        update(start_bt);
    }
    else if(rule_bt.contains(me->x(), me->y()))
    {
        i_base_image_flag = 2;
        update(rule_bt);
    }

}
void gamerules::mouseReleaseEvent(QMouseEvent *me)
{
    if(me->button() != Qt::LeftButton) return;
    QRect start_bt(230, 310, 155, 80);
    QRect rule_bt(230, 410, 155, 80);

    if(start_bt.contains(me->x(),me->y()))
    {
        this->close();
        (new MainWindow())->show();//메인함수 호출
    }
    else if(rule_bt.contains(me->x(),me->y()))
    {
        (new rule())->show();//게임 방법
    }
}
gamerules::~gamerules()
{
    delete ui;
}
