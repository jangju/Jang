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


    QPalette pal = palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap(BG_SUNINJANG)));//선인장 배경 출력
    setPalette(pal);

    iconshot();//아이콘들 출력

}
ICON::~ICON()
{
    if(IC_trash != nullptr) delete IC_trash;
    if(IC_baseball != nullptr) delete IC_baseball;
    if(IC_lotto != nullptr) delete IC_lotto;
    if(IC_memo != nullptr) delete IC_memo;
    if(IC_floder != nullptr) delete IC_floder;
    if(IC_calculator != nullptr) delete IC_calculator;
    if(IC_end != nullptr) delete IC_end;
    if(IC_end2 != nullptr) delete IC_end2;

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

void ICON::paintEvent(QPaintEvent *)
{
    QPainter q(this);
    switch(i_base_image_flag)
    {
    case 0:
        qDebug()<<"PaintEvent";
        break;
    case 1:
        qDebug()<<"VIEW = DEFALT END";
        q.drawPixmap(25, 700, QPixmap(ENDD));
        break;
    case 2:
        qDebug()<<"VIEW = DEFALT TRAST";
        q.drawPixmap(30, 60, QPixmap(TRASH));
        break;
    case 3:
        qDebug()<<"VIEW = DEFALT BASEBALL";
        q.drawPixmap(30, 240, QPixmap(BASEBALL));
        break;
    case 4:
        qDebug()<<"VIEW = DEFALT LOTTO";
        q.drawPixmap(30, 300, QPixmap(LOTTO));
        break;
    case 5:
        qDebug()<<"VIEW = DEFALT MEMO";
        q.drawPixmap(30, 360, QPixmap(MEMO));
        break;
    case 6:
        qDebug()<<"VIEW = DEFALT FOLDER";
        q.drawPixmap(30, 420, QPixmap(FOLDER));
        break;
    case 7:
        qDebug()<<"VIEW = DEFALT CALCULATOR";
        q.drawPixmap(30, 480, QPixmap(CALCULATOR));
        break;

        default: break;

    }

    i_base_image_flag = 0;
}

void ICON::mousePressEvent(QMouseEvent *me)
{
    if(me->button() != Qt::LeftButton) return;

    QRect bt_1(25, 700, 53, 53);
    QRect bt_2(30,  60, 53, 53);
    QRect bt_3(30, 240, 53, 53);
    QRect bt_4(30, 300, 53, 53);
    QRect bt_5(30, 360, 53, 53);
    QRect bt_6(30, 420, 53, 53);
    QRect bt_7(30, 480, 53, 53);

    if(bt_1.contains(me->x(), me->y()))
    {
        i_base_image_flag = 1;
        update(bt_1);
    }
    else if(bt_2.contains(me->x(), me->y()))
    {
        i_base_image_flag = 2;
        update(bt_2);
    }
    else if(bt_3.contains(me->x(), me->y()))
    {
        i_base_image_flag = 3;
        update(bt_3);
    }
    else if(bt_4.contains(me->x(), me->y()))
    {
        i_base_image_flag = 4;
        update(bt_4);
    }
    else if(bt_5.contains(me->x(), me->y()))
    {
        i_base_image_flag = 5;
        update(bt_5);
    }
    else if(bt_6.contains(me->x(), me->y()))
    {
        i_base_image_flag = 6;
        update(bt_6);
    }
    else if(bt_7.contains(me->x(), me->y()))
    {
        i_base_image_flag = 7;
        update(bt_7);
    }
}
void ICON::mouseReleaseEvent(QMouseEvent *me)
{
    if(me->button() != Qt::LeftButton) return;


    QRect bt_0(28, 178, 54, 54);
    QRect bt_1(28, 238, 54, 54);
    QRect bt_2(28, 298, 54, 54);
    QRect bt_3(28, 358, 54, 54);
    QRect bt_4(28, 418, 54, 54);
    QRect bt_5(28, 478, 54, 54);

    QRect end(23, 698, 53, 53);

    if(end.contains(me->x(),me->y()))
    {
        qDebug()<<"VIEW = UI CLOSE";
        this->close();
        update(end);
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
        QDesktopServices::openUrl(QUrl("file:///home/lubuntu", QUrl::TolerantMode));//폴더오픈 소스
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
    qDebug()<<"Iconshot";

    IC_end = new QLabel(this);
    IC_end->setGeometry(QRect(25, 700, 50, 50));
    IC_end->setPixmap(QPixmap(END));

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



    //move(30, 300);

}

