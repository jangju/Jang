#include "ICON.h"
#include "mainwindow.h"

#include <QDesktopServices> // 파일오픈 설정

#define TRASH "/home/lubuntu/recttest/Image/trash.png"
#define BASEBALL "/home/lubuntu/recttest/Image/BASEBALLICON.png"
#define LOTTO "/home/lubuntu/recttest/Image/Lotto.png"
#define MEMO "/home/lubuntu/recttest/Image/memo.png"
#define FOLDER "/home/lubuntu/recttest/Image/folder.png"
#define CALCULATOR "/home/lubuntu/recttest/Image/calculator.png"
#define END "/home/lubuntu/recttest/Image/close.png"
#define ENDD "/home/lubuntu/recttest/Image/close2.png"

#define BG_SUNINJANG "/home/lubuntu/recttest/Image/suninjang.png"

ICON::ICON(QWidget *parent) :
    QWidget(parent)
{
    resize(1024, 768);
    setAutoFillBackground(true);//배경을 쓰려면 필요함
    setAttribute(Qt::WA_DeleteOnClose);

    /*
    QPalette pal = palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap(BG_SUNINJANG)));//선인장 배경 출력
    setPalette(pal);
    */

    iconshot();//아이콘들 출력

}

void ICON::mousePressEvent(QMouseEvent *me)
{
    if(me->button() != Qt::LeftButton) return;

    QRect bt(23, 698, 53, 53);

    if(bt.contains(me->x(), me->y()))
    {
        IC_end2 = new QLabel(this);
        IC_end2->setGeometry(QRect(25, 700, 50, 50));
        IC_end2->setPixmap(QPixmap(ENDD));//종료버튼
        //if(b_once_setup)
        //{
        //   b_once_setup = false; //한번만 실행되게 함


        qDebug()<<"ICONReleaseEvent";
        update(bt);
        //}
    }


}
void ICON::mouseReleaseEvent(QMouseEvent *me)
{

    if(me->button() != Qt::LeftButton) return;

    QRect end(23, 698, 53, 53);
    QRect bt_0(28, 178, 54, 54);
    QRect bt_1(28, 238, 54, 54);
    QRect bt_2(28, 298, 54, 54);
    QRect bt_3(28, 358, 54, 54);
    QRect bt_4(28, 418, 54, 54);
    QRect bt_5(28, 478, 54, 54);


    if(end.contains(me->x(),me->y()))
    {
        this->close();
    }
    else if(bt_0.contains(me->x(), me->y()))
    {
        Process = new QProcess(this);
        Process->start("/home/lubuntu/baseball/baseball");
        qDebug()<<"BaseBall game START";
        update(bt_0);
    }
    else if(bt_1.contains(me->x(), me->y()))
    {
        Process = new QProcess(this);
        Process->start("/home/lubuntu/baseball/baseball");
        qDebug()<<"BaseBall game START";
        update(bt_1);
    }
    else if(bt_2.contains(me->x(), me->y()))
    {
        Process = new QProcess(this);
        Process->start("/home/lubuntu/lotto/lotto");
        qDebug()<<"Lotto TEST START";
        update(bt_2);
    }
    else if(bt_3.contains(me->x(),me->y()))
    {
        Process = new QProcess(this);
        Process->start("/usr/bin/leafpad");
        qDebug()<<"LeafPad";
        update(bt_3);
    }
    else if(bt_4.contains(me->x(),me->y()))
    {
        QDesktopServices::openUrl(QUrl("file:///home/lubuntu",QUrl::TolerantMode));//폴더오픈 소스
        qDebug()<<"Folder Open";

    }
    else if(bt_5.contains(me->x(),me->y()))
    {
        Process = new QProcess(this);
        Process->start("/usr/bin/galculator");
        qDebug()<<"Galculator Program START";
        update(bt_5);
    }

}
void ICON::iconshot()
{
    qDebug()<<"absbasbregreagwragwragwragbasb";



    IC_trash = new QLabel(this);
    IC_trash->setGeometry(QRect(30, 60, 50, 50));
    IC_trash->setPixmap(QPixmap(TRASH));

    IC_baseball = new QLabel(this);
    IC_baseball->setGeometry(QRect(30, 240, 50, 50));
    IC_baseball->setPixmap(QPixmap(BASEBALL));

    IC_lotto = new QLabel(this);
    IC_lotto->setGeometry(QRect(30, 300, 50, 50));
    IC_lotto->setPixmap(QPixmap(LOTTO));

    IC_memo = new QLabel(this);
    IC_memo->setGeometry(QRect(30, 360, 50, 50));
    IC_memo->setPixmap(QPixmap(MEMO));

    IC_floder = new QLabel(this);
    IC_floder->setGeometry(QRect(30, 420, 50, 50));
    IC_floder->setPixmap(QPixmap(FOLDER));


    IC_calculator = new QLabel(this);
    IC_calculator->setGeometry(QRect(30, 480, 50, 50));
    IC_calculator->setPixmap(QPixmap(CALCULATOR));

    IC_end = new QLabel(this);
    IC_end->setGeometry(QRect(25, 700, 50, 50));
    IC_end->setPixmap(QPixmap(END));

    //move(30, 300);


}
ICON::~ICON()
{
    //실행파일 해제
    if(Process!=nullptr)
    {
        if(Process->isOpen())
        {
            Process->close();
        }
        Process->deleteLater();
    }

}
