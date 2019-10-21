#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "test.h"
#include "gamerules.h"
#include <QDebug>
#include <QString>


#define BG_baseball "/home/lubuntu/baseball/Image/BG_baseball.png"//시작누른 배경화면
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    new test(this);

    QPalette pal = palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap(BG_baseball)));
    setPalette(pal);


    //////////////////User 숫자를 가운데 맞춤///////////////////////////
    ui->t_num1->setAlignment(Qt::AlignCenter);
    ui->t_num2->setAlignment(Qt::AlignCenter);
    ui->t_num3->setAlignment(Qt::AlignCenter);
    ui->t_num4->setAlignment(Qt::AlignCenter);
    ///////////////////User 숫자를 1~9 한정 지음///////////////////////
    ui->t_num1->setValidator(new QIntValidator(1.0,9.0,this));
    ui->t_num2->setValidator(new QIntValidator(1.0,9.0,this));
    ui->t_num3->setValidator(new QIntValidator(1.0,9.0,this));
    ui->t_num4->setValidator(new QIntValidator(1.0,9.0,this));
    ///////////////////화면에 회차 진행을 알려주기위한 라벨/////////////////
    ui->label->setText("1회차 숫자야구");
    ///////////////////Computer Ball을 랜덤으로 작성////////////////////
    srand((unsigned)time(NULL));//중복되지 않게 작성
    for(i = 0;i<10;++i)
    {
     while(1)
        {
            computerBall[i] = rand()%9+1;
            itemp = 0;
            for(j = 0; j<i;++j)
            {
                if(computerBall[j]== computerBall[i])
                {
                    itemp = 1;
                    break;
                }
            }
            if(!itemp)
                break;
        }
    }

    ui->label_com1->setText(QString("%1").arg(computerBall[0]));//컴퓨터 첫번째 랜덤숫자
    ui->label_com2->setText(QString("%1").arg(computerBall[1]));//컴퓨터 두번째 랜덤숫자
    ui->label_com3->setText(QString("%1").arg(computerBall[2]));//컴퓨터 세번째 랜덤숫자
    ui->label_com4->setText(QString("%1").arg(computerBall[3]));//컴퓨터 네번째 랜덤숫자


}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::answers()
{

    ////////////입력한 숫자가 컴퓨터의 볼과 일치하는지//////////
    answer[0] = (ui->t_num1->text().toInt() == ui->label_com1->text().toInt());//strike
    answer[1] = (ui->t_num2->text().toInt() == ui->label_com2->text().toInt());//strike
    answer[2] = (ui->t_num3->text().toInt() == ui->label_com3->text().toInt());//strike
    answer[3] = (ui->t_num4->text().toInt() == ui->label_com4->text().toInt());//strike

    answer[4] = (ui->t_num1->text().toInt() == ui->label_com2->text().toInt());//ball
    answer[5] = (ui->t_num1->text().toInt() == ui->label_com3->text().toInt());//ball
    answer[6] = (ui->t_num1->text().toInt() == ui->label_com4->text().toInt());//ball

    answer[7] = (ui->t_num2->text().toInt() == ui->label_com1->text().toInt());//ball
    answer[8] = (ui->t_num2->text().toInt() == ui->label_com3->text().toInt());//ball
    answer[9] = (ui->t_num2->text().toInt() == ui->label_com4->text().toInt());//ball

    answer[10] = (ui->t_num3->text().toInt() == ui->label_com1->text().toInt());//ball
    answer[11] = (ui->t_num3->text().toInt() == ui->label_com2->text().toInt());//ball
    answer[12] = (ui->t_num3->text().toInt() == ui->label_com4->text().toInt());//ball

    answer[13] = (ui->t_num4->text().toInt() == ui->label_com1->text().toInt());//ball
    answer[14] = (ui->t_num4->text().toInt() == ui->label_com2->text().toInt());//ball
    answer[15] = (ui->t_num4->text().toInt() == ui->label_com3->text().toInt());//ball
    ///////////////Strike, Ball 개수 찾기/////////////////////////    
    strike = 0;
    ball = 0;

    for(int k=0;k<16;++k)//strike 개수 세기
    {
        if(k<4)
        {
            if(answer[k] == true)//스트라이크가 맞다면 스트라이크 개수+1
                ++strike;
        }
        else if(4<k<16)//ball 개수 세기
        {
            if(answer[k] == true)//볼이 맞다면 스트라이크 개수+1
                ++ball;
        }
    }
    ////////////////Strike, Ball 아웃 및 정보///////////////////////
    if(strike == 0 && ball == 0)
    {
        msg.setText("아웃");
    }
    else if(count==10)
    {
        msg.setText(" 컴퓨터 승리!!!\n 결과가 나옵니다.");
        msg.exec();
    }
    else
    {
        msg.information(this,"Title",QString("Strike : %1 Ball : %2").arg(strike).arg(ball));//스트라이크, 볼 메시지박스로 출력하기.
        qDebug()<<"\""<<count<<"회"<<"\"\n"<<"strike :"<<strike<<",ball :"<<ball;
        qDebug()<<ui->t_num1->text().toInt()<<ui->t_num2->text().toInt()<<ui->t_num3->text().toInt()<<ui->t_num4->text().toInt();//몇회차에 어떤거 입력했는지 알려줌.
    }
    ////////////////////USER 승리//////////////////////////////////
    if(strike == 4)//스트라이크가 전부 다나오면 실행
    {
        if(answer[0] && answer[1] && answer[2] && answer[3])//유저 승리 후 게임 종료.
        {
            qDebug()<<count<<"회 만에 승리"; //USER가 몇회만에 승리했는지 알려줌.
            ui->Hidden->hide();//컴퓨터 볼 공개
            msg.warning(this,"VICTORY",QString("USER VICTORY!!!\n %1회 만에 승리!!OK버튼을 누르면 종료됩니다.").arg(count));
            close();
        }
    }
}
/////////////회차를 알림///////////////
void MainWindow::Sequence()
{
    ///////////////////컴퓨터 승리//////////////////////////////////
    if(count==9)//9회차에서 눌렀을때 게임 종료.
    {

        str = (QString("Strike : %1 Ball : %2 \n    Game Over").arg(strike).arg(ball));
        ui->label->setText(str);
        ui->Hidden->hide();//컴퓨터 볼 공개
        ///더이상 숫자 못바꾸게 하려고 숨김///
        ui->t_num1->hide();
        ui->t_num2->hide();
        ui->t_num3->hide();
        ui->t_num4->hide();
        msg.setText("컴퓨터 승리~~!!");
        msg.exec();

    }
    if(count<9)//정답버튼을 누를때마다 회차가 바뀜.
    {
        ++count;
        ui->label->setText(QString("%1").arg(count)+"회차 숫자야구");

    }
}
void MainWindow::reset()//리셋 버튼
{
    ui->label->setText("1회차 숫자야구");

}
void MainWindow::on_b_answer_clicked()
{

    ////////////입력한 숫자 중복 표시 여부///////////////
    overlap[0] = (ui->t_num1->text().toInt() == ui->t_num2->text().toInt());
    overlap[1] = (ui->t_num1->text().toInt() == ui->t_num3->text().toInt());
    overlap[2] = (ui->t_num1->text().toInt() == ui->t_num4->text().toInt());
    overlap[3] = (ui->t_num2->text().toInt() == ui->t_num3->text().toInt());
    overlap[4] = (ui->t_num2->text().toInt() == ui->t_num4->text().toInt());
    overlap[5] = (ui->t_num3->text().toInt() == ui->t_num4->text().toInt());

    if((ui->t_num1->text().toInt()==false) && (ui->t_num2->text().toInt() == false) &&
       (ui->t_num3->text().toInt()==false) && (ui->t_num4->text().toInt() == false))//Text에 아무것도 입력 안할시 실행.
    {
        msg.setText("숫자를 입력해주세요");
        msg.exec();
    }

    else if((ui->t_num1->text().toInt()==false) || (ui->t_num2->text().toInt() == false) ||//Text에 하나라도 입력 안할시 실행.
            (ui->t_num3->text().toInt()==false) || (ui->t_num4->text().toInt() == false))
    {
        msg.setText("숫자를 전부 입력안하셨습니다.");
        msg.exec();
    }
    else if(overlap[0] || overlap[1] || overlap[2] || overlap[3] || overlap[4] || overlap[5])//Text에 숫자하나라도 같을시 실행.
    {
        msg.setText("숫자가 중복됬습니다..\n   다시 입력해주세요.");
        msg.exec();
    }

    else
    {
        answers();
        Sequence();

    }
}

void MainWindow::on_pushButton_computerball_clicked()
{
    ui->Hidden->hide();

}

/////////////처음화면으로 RESET//////////////
void MainWindow::on_pushButton_reset_clicked()
{
    this->close();
    (new gamerules())->show();
    /*
    count = 1;//회차를 초기화하기 위한 count
    ui->t_num1->show();
    ui->t_num2->show();
    ui->t_num3->show();
    ui->t_num4->show();
    ui->t_num1->clear();
    ui->t_num2->clear();
    ui->t_num3->clear();
    ui->t_num4->clear();
    reset();//setText("1회차 숫자야구");//label
    ui->Hidden->show();
    this->show();
    */
}
