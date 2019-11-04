#include "ICON.h"
#include "mainwindow.h"

#include <QDesktopServices> // 파일오픈 설정

#define TRASH "/home/lubuntu/TEST/RECTTEST/Image/trash.png"
#define BASEBALL "/home/lubuntu/TEST/RECTTEST/Image/BASEBALLICON.png"
#define LOTTO "/home/lubuntu/TEST/RECTTEST/Image/Lotto.png"
#define MEMO "/home/lubuntu/TEST/RECTTEST/Image/memo.png"
#define FOLDER "/home/lubuntu/TEST/RECTTEST/Image/folder.png"
#define CALCULATOR "/home/lubuntu/TEST/RECTTEST/Image/calculator.png"
#define END "/home/lubuntu/TEST/RECTTEST/Image/close.png"
#define END_D "/home/lubuntu/TEST/RECTTEST/Image/close2.png"
#define CALENDER "/home/lubuntu/TEST/RECTTEST/Image/calender.png"
#define START_D "/home/lubuntu/TEST/RECTTEST/Image/start_d.png"
#define STATUSBAR "/home/lubuntu/TEST/RECTTEST/Image/statusbar.png"

#define BG_WINDOW "/home/lubuntu/TEST/RECTTEST/Image/window.png"
#define BG_SUNINJANG "/home/lubuntu/TEST/RECTTEST/Image/suninjang.png"

ICON::ICON(QWidget *parent) :
    QWidget(parent)
{
    resize(1024, 768);
    setAutoFillBackground(true);//배경을 쓰려면 필요함
    setAttribute(Qt::WA_DeleteOnClose);

    QPalette pal = palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap(BG_WINDOW)));//선인장 배경 출력
    setPalette(pal);

    menubar = new QMenuBar(this);




    //iconshot();//아이콘들 출력
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
        q.drawPixmap(950, 50, QPixmap(END));
        q.drawPixmap(30, 60, QPixmap(TRASH));
        q.drawPixmap(30, 240, QPixmap(BASEBALL));
        q.drawPixmap(30, 300, QPixmap(LOTTO));
        q.drawPixmap(30, 360, QPixmap(MEMO));
        q.drawPixmap(30, 420, QPixmap(FOLDER));
        q.drawPixmap(30, 480, QPixmap(CALCULATOR));
        q.drawPixmap(30, 540, QPixmap(CALENDER));
        q.drawPixmap(0, 735, QPixmap(STATUSBAR));
         break;
    case 1:
        qDebug()<<"VIEW = DEFALT END";
        q.drawPixmap(951, 51, QPixmap(END_D));
        break;
    case 2:
        qDebug()<<"VIEW = DEFALT TRAST";
        q.drawPixmap(32, 62, QPixmap(TRASH));
        break;
    case 3:
        qDebug()<<"VIEW = DEFALT BASEBALL";
        q.drawPixmap(32, 242, QPixmap(BASEBALL));
        break;
    case 4:
        qDebug()<<"VIEW = DEFALT LOTTO";
        q.drawPixmap(32, 302, QPixmap(LOTTO));
        break;
    case 5:
        qDebug()<<"VIEW = DEFALT MEMO";
        q.drawPixmap(32, 362, QPixmap(MEMO));
        break;
    case 6:
        qDebug()<<"VIEW = DEFALT FOLDER";
        q.drawPixmap(32, 422, QPixmap(FOLDER));
        break;
    case 7:
        qDebug()<<"VIEW = DEFALT CALCULATOR";
        q.drawPixmap(32, 482, QPixmap(CALCULATOR));
        break;
    case 8:
        qDebug()<<"VIEW = DEFALT CALCULATOR";
        q.drawPixmap(32, 542, QPixmap(CALENDER));
        break;
    case 9:
        qDebug()<<"VIEW = DEFALT CALCULATOR";
        q.drawPixmap(0, 735, QPixmap(START_D));
        break;

        default: break;
    }
    i_base_image_flag = 0;
}

void ICON::mousePressEvent(QMouseEvent *me)
{
    if(me->button() != Qt::LeftButton) return;

    QRect bt_1(950, 50, 53, 53);//ENDD
    QRect bt_2(30,  60, 53, 53);//TRASH
    QRect bt_3(30, 240, 53, 53);//BASEBALL
    QRect bt_4(30, 300, 53, 53);//LOTTO
    QRect bt_5(30, 360, 53, 53);//MEMO
    QRect bt_6(30, 420, 53, 53);//FOLDER
    QRect bt_7(30, 480, 53, 53);//CALCULATOR
    QRect bt_8(30, 540, 53, 53);//CALENDER
    QRect bt_9(0, 735, 85 ,35);//STATUSBAR
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
    else if(bt_8.contains(me->x(), me->y()))
    {
        i_base_image_flag = 8;
        update(bt_8);
    }
    else if(bt_9.contains(me->x(), me->y()))
    {
        i_base_image_flag = 9;
        update(bt_9);
    }

}

void ICON::mouseReleaseEvent(QMouseEvent *me)//마우스 뗄떼
{
    if(me->button() != Qt::LeftButton) return;

    QRect bt_1(950, 50, 53, 53);
    QRect bt_2(28, 58, 54, 54);
    QRect bt_3(28, 238, 54, 54);
    QRect bt_4(28, 298, 54, 54);
    QRect bt_5(28, 358, 54, 54);
    QRect bt_6(28, 418, 54, 54);
    QRect bt_7(28, 478, 54, 54);
    QRect bt_8(28, 538, 54, 54);
    QRect bt_9(0, 735, 80, 80);

    if(bt_1.contains(me->x(),me->y()))
    {
        msgBox.setText("dfaefe0");
        msgBox.setStyleSheet("QLabel{min-width:300 px; font-size: 24px;} QPushButton{ width:200px; font-size: 18px;}");
        msgBox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        if(clicked == false)
        {
            int ret = msgBox.exec();
            switch (ret)
            {
            case QMessageBox::Yes:
               msgBox.information(this,"Yes","Yes Yes");
               this->close();
                break;
            case QMessageBox::No:
                msgBox.information(this,"No","No No");
                break;
            }
         }
        qDebug()<<"VIEW = UI CLOSE";
        update(bt_1);
    }
    else if(bt_2.contains(me->x(), me->y()))
    {
        QDesktopServices::openUrl(QUrl("file:/home/lubuntu/.local/share/Trash/", QUrl::TolerantMode));//폴더오픈 소스
        qDebug()<<"TRAST START";
        update(bt_2);
    }
    else if(bt_3.contains(me->x(), me->y()))
    {
        Process = new QProcess(this);
        Process->start("/home/lubuntu/TEST/Baseball/baseball");
        qDebug()<<"BaseBall game START";
        update(bt_3);
    }
    else if(bt_4.contains(me->x(), me->y()))
    {
        Process = new QProcess(this);
        Process->start("/home/lubuntu/TEST/LOTTO/lotto");
        qDebug()<<"Lotto TEST START";
        update(bt_4);
    }
    else if(bt_5.contains(me->x(),me->y()))
    {
        Process = new QProcess(this);
        Process->start("/usr/bin/leafpad");
        qDebug()<<"LeafPad";
        update(bt_5);
    }
    else if(bt_6.contains(me->x(),me->y()))
    {
        QDesktopServices::openUrl(QUrl("file:/home/lubuntu", QUrl::TolerantMode));//폴더오픈 소스
        qDebug()<<"Folder Open";
        update(bt_6);
    }
    else if(bt_7.contains(me->x(),me->y()))
    {
        Process = new QProcess(this);
        Process->start("/usr/bin/galculator");
        qDebug()<<"Galculator Program START";
        update(bt_7);
    }
    else if(bt_8.contains(me->x(),me->y()))
    {
        calendarWidget = new QCalendarWidget(this);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(200, 140, 500, 200));
        qDebug()<<"CALENDER Program START";
        update(bt_8);
    }
    else if(bt_9.contains(me->x(),me->y()))
    {
        qDebug()<<"CALENDER Program START";
        update(bt_9);
    }
}
void ICON::iconshot()
{
    qDebug()<<"Iconshot";

    IC_end = new QLabel(this);
    IC_end->setGeometry(QRect(950, 50, 50, 50));
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
