#include "lotto.h"
#include "ui_lotto.h"
#include "answer.h"

#include <time.h>

#include <unistd.h>//usleep 헤더
#include <QTimer>

#include <QPalette>
#define BG_LOTTO "/home/lubuntu/lotto/IMAGE/BG_lotto.png"

lotto::lotto(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lotto)
{

    ui->setupUi(this);
    new answer(this);
    ///////////////////배경 출력//////////////
    QPalette pal = palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap(BG_LOTTO)));
    setPalette(pal);

    ////////보너스라벨 장식///////
    ui->label_Bonus->setAlignment(Qt::AlignCenter);
    ui->label_Bonus->setStyleSheet(tr("color : red;"
                                      "background-color: blue;"));
    ////////그림 삽입////////////
    image = new QLabel(centralWidget());
    //image->setObjectName(QStringLiteral("label"));
    image->setGeometry(QRect(30,235,670,230));
    image->setPixmap(QPixmap(QString::fromUtf8("/home/lubuntu/lotto/IMAGE/lotto.png")));
    ui->pushButton_answer->setDefault(false);
    srand((unsigned)time(NULL));
    for(i = 0;i<45;++i)
    {
        while(1)
        {
            lottos[i] = rand()%45+1;
            itemp = 0;
            for(j = 0; j<i;++j)
            {
                if(lottos[j]== lottos[i])
                {
                    itemp = 1;
                    break;
                }
            }
            if(!itemp)
                break;
        }
    }
    //////////////////////로또 번호 가운데 맞춤//////////////////////////////
    ui->label_1->setAlignment(Qt::AlignCenter);
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_3->setAlignment(Qt::AlignCenter);
    ui->label_4->setAlignment(Qt::AlignCenter);
    ui->label_5->setAlignment(Qt::AlignCenter);
    ui->label_6->setAlignment(Qt::AlignCenter);
    ui->label_Bonus->setAlignment(Qt::AlignCenter);
    //////////////////////사용자 번호 가운데 맞춤//////////////////////////////
    ui->lineEdit_1->setAlignment(Qt::AlignCenter);
    ui->lineEdit_2->setAlignment(Qt::AlignCenter);
    ui->lineEdit_3->setAlignment(Qt::AlignCenter);
    ui->lineEdit_4->setAlignment(Qt::AlignCenter);
    ui->lineEdit_5->setAlignment(Qt::AlignCenter);
    ui->lineEdit_6->setAlignment(Qt::AlignCenter);
    ui->lineEdit_Bonus->setAlignment(Qt::AlignCenter);
    //////////////////////사용자 번호 1~45 까지만 입력되도록 함//////////////////////////////
    ui->lineEdit_1->setValidator(new QIntValidator(1.0,45.0,this));
    ui->lineEdit_2->setValidator(new QIntValidator(1.0,45.0,this));
    ui->lineEdit_3->setValidator(new QIntValidator(1.0,45.0,this));
    ui->lineEdit_4->setValidator(new QIntValidator(1.0,45.0,this));
    ui->lineEdit_5->setValidator(new QIntValidator(1.0,45.0,this));
    ui->lineEdit_6->setValidator(new QIntValidator(1.0,45.0,this));
    ui->lineEdit_Bonus->setValidator(new QIntValidator(1.0,45.0,this));
    //////////////////////그림 뒤에있는 버튼이 눌릴 수 있으니 false 시킴/////////////////////////////
    ui->pushButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_Bonus->setEnabled(false);


    //ui->pushButton_allopen->click();//로또 번호를 시작과 동시에 공개하는 소스
}

lotto::~lotto()
{
    delete ui;
}

void lotto::on_pushButton_1_clicked()
{

    ui->label_1->setText(QString::number(lottos[1]));
    ui->pushButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_Bonus->setEnabled(false);
}

void lotto::on_pushButton_2_clicked()
{
    if(ui->pushButton_1->isEnabled() == false)
    {
    ui->label_2->setText(QString::number(lottos[2]));
    ui->pushButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_Bonus->setEnabled(false);
    }
}

void lotto::on_pushButton_3_clicked()
{
    if(ui->pushButton_2->isEnabled() == false)
    {
    ui->label_3->setText(QString::number(lottos[3]));
    ui->pushButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_Bonus->setEnabled(false);
    }
}
void lotto::on_pushButton_4_clicked()
{
    if(ui->pushButton_3->isEnabled() == false)
    {
    ui->label_4->setText(QString::number(lottos[4]));
    ui->pushButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_Bonus->setEnabled(false);
    }
}

void lotto::on_pushButton_5_clicked()
{
    if(ui->pushButton_4->isEnabled() == false)
    {
    ui->label_5->setText(QString::number(lottos[5]));
    ui->pushButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_Bonus->setEnabled(false);
    }
}

void lotto::on_pushButton_6_clicked()
{
    if(ui->pushButton_5->isEnabled() == false)
    {
    ui->label_6->setText(QString::number(lottos[6]));
    ui->pushButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_Bonus->setEnabled(true);
    }
}

void lotto::on_pushButton_Bonus_clicked()
{
    if(ui->pushButton_6->isEnabled() == false)
    {
    ui->label_Bonus->setText(QString::number(lottos[7]));
    ui->pushButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_Bonus->setEnabled(false);
    }
}

void lotto::on_pushButton_autobuy_clicked()
{
    for(i =0;i<45;++i)
    {
        while(1)
        {
            lottos[i] = rand()%45+1;
            itemp = 0;
            for(j = 0; j<i;++j)
            {
                if(lottos[j]== lottos[i])
                {
                    itemp = 1;
                    break;
                }
            }
            if(!itemp)
                break;
        }
}
    ui->lineEdit_1->setText(QString::number(lottos[1]));
    ui->lineEdit_2->setText(QString::number(lottos[2]));
    ui->lineEdit_3->setText(QString::number(lottos[3]));
    ui->lineEdit_4->setText(QString::number(lottos[4]));
    ui->lineEdit_5->setText(QString::number(lottos[5]));
    ui->lineEdit_6->setText(QString::number(lottos[6]));
    ui->lineEdit_Bonus->setText(QString::number(lottos[7]));
}

void lotto::on_pushButton_allopen_clicked()
{
      for(i =0;i<45;++i)
     {
         while(1)
         {
             lottos[i] = rand()%45+1;
             itemp = 0;
             for(j = 0; j<i;++j)
             {
                 if(lottos[j]== lottos[i])
                 {
                     itemp = 1;
                     break;
                 }
             }
             if(!itemp)
                 break;
         }
     }
    lotto::on_pushButton_1_clicked();
    lotto::on_pushButton_2_clicked();
    lotto::on_pushButton_3_clicked();
    lotto::on_pushButton_4_clicked();
    lotto::on_pushButton_5_clicked();
    lotto::on_pushButton_6_clicked();
    lotto::on_pushButton_Bonus_clicked();
    /*라벨과 텍스트를 한번에 오픈
    ui->label_1->setText(QString::number(lottos[1]));
    usleep(400000);
    ui->label_2->setText(QString::number(lottos[2]));

    ui->label_3->setText(QString::number(lottos[3]));

    ui->label_4->setText(QString::number(lottos[4]));

    ui->label_5->setText(QString::number(lottos[5]));

    ui->label_6->setText(QString::number(lottos[6]));

    ui->label_Bonus->setText(QString::number(lottos[7]));
    ui->pushButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_Bonus->setEnabled(false);
    */
}

void lotto::on_pushButton_number_reset_clicked()
{
    ui->lineEdit_1->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_Bonus->clear();
    ui->pushButton_1->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_Bonus->setEnabled(false);
    ui->label_1->setText(QApplication::translate("lotto", "1\353\262\210OPEN", 0));
    ui->label_2->setText(QApplication::translate("lotto", "2\353\262\210OPEN", 0));
    ui->label_3->setText(QApplication::translate("lotto", "3\353\262\210OPEN", 0));
    ui->label_4->setText(QApplication::translate("lotto", "4\353\262\210OPEN", 0));
    ui->label_5->setText(QApplication::translate("lotto", "5\353\262\210OPEN", 0));
    ui->label_6->setText(QApplication::translate("lotto", "6\353\262\210OPEN", 0));
    ui->label_Bonus->setText(QApplication::translate("lotto", "Bonus Open", 0));
    ui->pushButton_number_reset->setText(QApplication::translate("lotto", "\354\210\253\354\236\220 Reset", 0));

  ///////////////////////////////////
     for(i =0;i<45;++i)
     {
         while(1)
         {
             lottos[i] = rand()%45+1;
             itemp = 0;
             for(j = 0; j<i;++j)
             {
                 if(lottos[j]== lottos[i])
                 {
                     itemp = 1;
                     break;
                 }
             }
             if(!itemp)
                 break;
         }
     }
}

void lotto::on_pushButton_answer_clicked()
{

    ifmoon[0] = (ui->label_1->text().toInt() == ui->lineEdit_1->text().toInt());
    ifmoon[1] = (ui->label_1->text().toInt() == ui->lineEdit_2->text().toInt());
    ifmoon[2] = (ui->label_1->text().toInt() == ui->lineEdit_3->text().toInt());
    ifmoon[3] = (ui->label_1->text().toInt() == ui->lineEdit_4->text().toInt());
    ifmoon[4] = (ui->label_1->text().toInt() == ui->lineEdit_5->text().toInt());
    ifmoon[5] = (ui->label_1->text().toInt() == ui->lineEdit_6->text().toInt());
    ifmoon[6] = (ui->label_2->text().toInt() == ui->lineEdit_1->text().toInt());
    ifmoon[7] = (ui->label_2->text().toInt() == ui->lineEdit_2->text().toInt());
    ifmoon[8] = (ui->label_2->text().toInt() == ui->lineEdit_3->text().toInt());
    ifmoon[9] = (ui->label_2->text().toInt() == ui->lineEdit_4->text().toInt());
    ifmoon[10] = (ui->label_2->text().toInt() == ui->lineEdit_5->text().toInt());
    ifmoon[11] = (ui->label_2->text().toInt() == ui->lineEdit_6->text().toInt());
    ifmoon[12] = (ui->label_3->text().toInt() == ui->lineEdit_1->text().toInt());
    ifmoon[13] = (ui->label_3->text().toInt() == ui->lineEdit_2->text().toInt());
    ifmoon[14] = (ui->label_3->text().toInt() == ui->lineEdit_3->text().toInt());
    ifmoon[15] = (ui->label_3->text().toInt() == ui->lineEdit_4->text().toInt());
    ifmoon[16] = (ui->label_3->text().toInt() == ui->lineEdit_5->text().toInt());
    ifmoon[17] = (ui->label_3->text().toInt() == ui->lineEdit_6->text().toInt());
    ifmoon[18] = (ui->label_4->text().toInt() == ui->lineEdit_1->text().toInt());
    ifmoon[19] = (ui->label_4->text().toInt() == ui->lineEdit_2->text().toInt());
    ifmoon[20] = (ui->label_4->text().toInt() == ui->lineEdit_3->text().toInt());
    ifmoon[21] = (ui->label_4->text().toInt() == ui->lineEdit_4->text().toInt());
    ifmoon[22] = (ui->label_4->text().toInt() == ui->lineEdit_5->text().toInt());
    ifmoon[23] = (ui->label_4->text().toInt() == ui->lineEdit_6->text().toInt());
    ifmoon[24] = (ui->label_5->text().toInt() == ui->lineEdit_1->text().toInt());
    ifmoon[25] = (ui->label_5->text().toInt() == ui->lineEdit_2->text().toInt());
    ifmoon[26] = (ui->label_5->text().toInt() == ui->lineEdit_3->text().toInt());
    ifmoon[27] = (ui->label_5->text().toInt() == ui->lineEdit_4->text().toInt());
    ifmoon[28] = (ui->label_5->text().toInt() == ui->lineEdit_5->text().toInt());
    ifmoon[29] = (ui->label_5->text().toInt() == ui->lineEdit_6->text().toInt());
    ifmoon[30] = (ui->label_6->text().toInt() == ui->lineEdit_1->text().toInt());
    ifmoon[31] = (ui->label_6->text().toInt() == ui->lineEdit_2->text().toInt());
    ifmoon[32] = (ui->label_6->text().toInt() == ui->lineEdit_3->text().toInt());
    ifmoon[33] = (ui->label_6->text().toInt() == ui->lineEdit_4->text().toInt());
    ifmoon[34] = (ui->label_6->text().toInt() == ui->lineEdit_5->text().toInt());
    ifmoon[35] = (ui->label_6->text().toInt() == ui->lineEdit_6->text().toInt());
    ifmoon[36] = (ui->label_Bonus->text().toInt() == ui->lineEdit_1->text().toInt());
    ifmoon[37] = (ui->label_Bonus->text().toInt() == ui->lineEdit_2->text().toInt());
    ifmoon[38] = (ui->label_Bonus->text().toInt() == ui->lineEdit_3->text().toInt());
    ifmoon[39] = (ui->label_Bonus->text().toInt() == ui->lineEdit_4->text().toInt());
    ifmoon[40] = (ui->label_Bonus->text().toInt() == ui->lineEdit_5->text().toInt());
    ifmoon[41] = (ui->label_Bonus->text().toInt() == ui->lineEdit_6->text().toInt());
    ifmoon[42] = (ui->label_1->text().toInt() == ui->lineEdit_Bonus->text().toInt());
    ifmoon[43] = (ui->label_2->text().toInt() == ui->lineEdit_Bonus->text().toInt());
    ifmoon[44] = (ui->label_3->text().toInt() == ui->lineEdit_Bonus->text().toInt());
    ifmoon[45] = (ui->label_4->text().toInt() == ui->lineEdit_Bonus->text().toInt());
    ifmoon[46] = (ui->label_5->text().toInt() == ui->lineEdit_Bonus->text().toInt());
    ifmoon[47] = (ui->label_6->text().toInt() == ui->lineEdit_Bonus->text().toInt());
    ifmoon[48] = (ui->label_Bonus->text().toInt() == ui->lineEdit_Bonus->text().toInt());
    int a=(ifmoon[0] || ifmoon[1] || ifmoon[2] || ifmoon[3] || ifmoon[4] || ifmoon[5]);
    int b=(ifmoon[6] || ifmoon[7] || ifmoon[8] || ifmoon[9] || ifmoon[10] || ifmoon[11]);
    int c=(ifmoon[12] || ifmoon[13] || ifmoon[14] || ifmoon[15] || ifmoon[16] || ifmoon[17]);
    int d=(ifmoon[18] || ifmoon[19] || ifmoon[20] || ifmoon[21] ||   ifmoon[22] || ifmoon[23]);
    int e=(ifmoon[24] || ifmoon[25] || ifmoon[26] || ifmoon[27] || ifmoon[28] || ifmoon[29]);
    int f=(ifmoon[30] || ifmoon[31] || ifmoon[32] || ifmoon[33] || ifmoon[34] || ifmoon[35]);
    int g=(ifmoon[36] || ifmoon[37] || ifmoon[38] || ifmoon[39] || ifmoon[40] || ifmoon[41]);
    int h=(ifmoon[42] || ifmoon[43] || ifmoon[44] || ifmoon[45] || ifmoon[46] || ifmoon[47] || ifmoon[48]);
    if(a && b && c && d && e && f)
    {
        msgBox.setText("    축하드립니다 1등입니다.\n    금액을 확인하시겠습니까?");
        msgBox.setStyleSheet("QLabel{min-width:300 px; font-size: 24px;} QPushButton{ width:200px; font-size: 18px;}");
        msgBox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        if(clicked == false)
        {

            int ret = msgBox.exec();
            switch (ret)
            {
            case QMessageBox::Yes:
               msgBox.information(this,"look","20억!!");
                break;
            case QMessageBox::No:
                msgBox.information(this,"No","Good Bye");
                break;

            }
         }
        msgBox.setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    }
    else if(((a && b && c && d && e) || (a && b && c && d && f) || (a && b && c && e && f) || (a && b && d && e && f) || (a && c && d && e && f) || (b && c && d && e && f))&&ifmoon[48])
    {
        msgBox.setText("    축하드립니다 2등입니다.\n    금액을 확인하시겠습니까?");
        msgBox.setStyleSheet("QLabel{min-width:300 px; font-size: 24px;} QPushButton{ width:200px; font-size: 18px;}");
        msgBox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        if(clicked == false)
        {
            int ret = msgBox.exec();
            switch (ret)
            {
            case QMessageBox::Yes:
               msgBox.information(this,"look","2천만원!!");
                break;
            case QMessageBox::No:
                msgBox.information(this,"No","Good Bye");
                break;
            }
         }
        msgBox.setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    }
    else if((a && b && c && d && e) || (a && b && c && d && f) || (a && b && c && e && f) || (a && b && d && e && f) || (a && c && d && e && f) || (b && c && d && e && f))
    {
        msgBox.setText("    축하드립니다 3등입니다.\n    금액을 확인하시겠습니까?");
        msgBox.setStyleSheet("QLabel{min-width:300 px; font-size: 24px;} QPushButton{ width:200px; font-size: 18px;}");
        msgBox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        if(clicked == false)
        {
            int ret = msgBox.exec();
            switch (ret)
            {
            case QMessageBox::Yes:
               msgBox.information(this,"look ","100만원!!");
                break;
            case QMessageBox::No:
                msgBox.information(this ,"No","Good Bye");
                break;
            }
         }
        msgBox.setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    }
    else if((a && b && c && d)||(a && b && c && e)|| (a && b && d && e)|| ( a && c && d && e)||(b && c && d && e)|| (a&&b&&c&&f)||(a&&b&&d&&f)||(a&&c&&d&&f)||(b&&c&&d&&f)
            || (a&&b&&e&&f)||(a&&c&&e&&f)||(b&&c&&e&&f)||(a&&d&&e&&f)||(b&&d&&e&&f)||(c&&d&&e&&f))
    {
        msgBox.setText("    축하드립니다 4등입니다.\n    금액을 확인하시겠습니까?");
        msgBox.setStyleSheet("QLabel{min-width:300 px; font-size: 24px;} QPushButton{ width:200px; font-size: 18px;}");
        msgBox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        if(clicked == false)
        {
            int ret = msgBox.exec();
            switch (ret)
            {
            case QMessageBox::Yes:
               msgBox.information(this,"look","50,000원");
                break;
            case QMessageBox::No:
                msgBox.information(this,"No","Good Bye");
                break;
            }
         }
        msgBox.setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    }
    else
    {
        msgBox.setText("    꽝입니다.");
        msgBox.setStyleSheet("QLabel{min-width:300 px; font-size: 24px;} QPushButton{ width:200px; font-size: 18px;}");
        msgBox.exec();
    }
}



