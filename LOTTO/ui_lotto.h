/********************************************************************************
** Form generated from reading UI file 'lotto.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOTTO_H
#define UI_LOTTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lotto
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_Bonus;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_Bonus;
    QPushButton *pushButton_number_reset;
    QLineEdit *lineEdit_1;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_Bonus;
    QPushButton *pushButton_answer;
    QPushButton *pushButton_allopen;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label;
    QPushButton *pushButton_autobuy;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *lotto)
    {
        if (lotto->objectName().isEmpty())
            lotto->setObjectName(QStringLiteral("lotto"));
        lotto->resize(746, 570);
        lotto->setMaximumSize(QSize(752, 584));
        centralWidget = new QWidget(lotto);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_1 = new QPushButton(centralWidget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setGeometry(QRect(20, 290, 81, 71));
        QFont font;
        font.setPointSize(30);
        pushButton_1->setFont(font);
        pushButton_1->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_1->setIconSize(QSize(16, 16));
        pushButton_1->setAutoRepeatDelay(298);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 290, 81, 71));
        pushButton_2->setFont(font);
        pushButton_2->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(220, 290, 81, 71));
        pushButton_3->setFont(font);
        pushButton_3->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(320, 290, 81, 71));
        pushButton_4->setFont(font);
        pushButton_4->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(420, 290, 81, 71));
        pushButton_5->setFont(font);
        pushButton_5->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(520, 290, 81, 71));
        pushButton_6->setFont(font);
        pushButton_6->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_Bonus = new QPushButton(centralWidget);
        pushButton_Bonus->setObjectName(QStringLiteral("pushButton_Bonus"));
        pushButton_Bonus->setGeometry(QRect(600, 290, 101, 71));
        QFont font1;
        font1.setPointSize(20);
        pushButton_Bonus->setFont(font1);
        pushButton_Bonus->setCursor(QCursor(Qt::ArrowCursor));
        label_1 = new QLabel(centralWidget);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setGeometry(QRect(10, 210, 91, 51));
        QFont font2;
        font2.setPointSize(15);
        label_1->setFont(font2);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 210, 91, 51));
        label_2->setFont(font2);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 210, 91, 51));
        label_3->setFont(font2);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(320, 210, 91, 51));
        label_4->setFont(font2);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(420, 210, 91, 51));
        label_5->setFont(font2);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(520, 210, 91, 51));
        label_6->setFont(font2);
        label_Bonus = new QLabel(centralWidget);
        label_Bonus->setObjectName(QStringLiteral("label_Bonus"));
        label_Bonus->setGeometry(QRect(620, 210, 101, 51));
        QFont font3;
        font3.setPointSize(13);
        label_Bonus->setFont(font3);
        pushButton_number_reset = new QPushButton(centralWidget);
        pushButton_number_reset->setObjectName(QStringLiteral("pushButton_number_reset"));
        pushButton_number_reset->setGeometry(QRect(360, 440, 171, 81));
        lineEdit_1 = new QLineEdit(centralWidget);
        lineEdit_1->setObjectName(QStringLiteral("lineEdit_1"));
        lineEdit_1->setGeometry(QRect(20, 80, 61, 61));
        lineEdit_1->setFont(font2);
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(130, 80, 61, 61));
        lineEdit_2->setFont(font2);
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(230, 80, 61, 61));
        lineEdit_3->setFont(font2);
        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(330, 80, 61, 61));
        lineEdit_4->setFont(font2);
        lineEdit_5 = new QLineEdit(centralWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(430, 80, 61, 61));
        lineEdit_5->setFont(font2);
        lineEdit_6 = new QLineEdit(centralWidget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(530, 80, 61, 61));
        lineEdit_6->setFont(font2);
        lineEdit_Bonus = new QLineEdit(centralWidget);
        lineEdit_Bonus->setObjectName(QStringLiteral("lineEdit_Bonus"));
        lineEdit_Bonus->setGeometry(QRect(630, 80, 71, 61));
        lineEdit_Bonus->setFont(font2);
        pushButton_answer = new QPushButton(centralWidget);
        pushButton_answer->setObjectName(QStringLiteral("pushButton_answer"));
        pushButton_answer->setGeometry(QRect(570, 440, 141, 80));
        pushButton_allopen = new QPushButton(centralWidget);
        pushButton_allopen->setObjectName(QStringLiteral("pushButton_allopen"));
        pushButton_allopen->setGeometry(QRect(150, 440, 171, 81));
        pushButton_allopen->setFont(font1);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 30, 41, 50));
        QFont font4;
        font4.setFamily(QStringLiteral("Umpush"));
        font4.setPointSize(30);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setWeight(75);
        label_7->setFont(font4);
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/IMAGE/1.png")));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(140, 30, 41, 50));
        QFont font5;
        font5.setFamily(QStringLiteral("Umpush"));
        font5.setPointSize(30);
        font5.setBold(true);
        font5.setWeight(75);
        label_8->setFont(font5);
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/IMAGE/2.png")));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(240, 30, 41, 50));
        label_9->setFont(font5);
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/IMAGE/3.png")));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 170, 401, 41));
        label->setFont(font1);
        pushButton_autobuy = new QPushButton(centralWidget);
        pushButton_autobuy->setObjectName(QStringLiteral("pushButton_autobuy"));
        pushButton_autobuy->setGeometry(QRect(20, 440, 111, 81));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(340, 29, 41, 50));
        label_14->setFont(font5);
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/IMAGE/4.png")));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(440, 29, 41, 50));
        label_15->setFont(font5);
        label_15->setPixmap(QPixmap(QString::fromUtf8(":/IMAGE/5.png")));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(540, 30, 41, 50));
        label_16->setFont(font5);
        label_16->setPixmap(QPixmap(QString::fromUtf8(":/IMAGE/6.png")));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(600, 30, 131, 51));
        QPalette palette;
        QBrush brush(QColor(46, 52, 54, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(190, 190, 190, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_17->setPalette(palette);
        label_17->setFont(font5);
        label_17->setPixmap(QPixmap(QString::fromUtf8(":/IMAGE/BONUS.png")));
        lotto->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(lotto);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 746, 22));
        lotto->setMenuBar(menuBar);
        mainToolBar = new QToolBar(lotto);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        lotto->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(lotto);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        lotto->setStatusBar(statusBar);

        retranslateUi(lotto);

        QMetaObject::connectSlotsByName(lotto);
    } // setupUi

    void retranslateUi(QMainWindow *lotto)
    {
        lotto->setWindowTitle(QApplication::translate("lotto", "lotto", 0));
        pushButton_1->setText(QApplication::translate("lotto", "1", 0));
        pushButton_2->setText(QApplication::translate("lotto", "2", 0));
        pushButton_3->setText(QApplication::translate("lotto", "3", 0));
        pushButton_4->setText(QApplication::translate("lotto", "4", 0));
        pushButton_5->setText(QApplication::translate("lotto", "5", 0));
        pushButton_6->setText(QApplication::translate("lotto", "6", 0));
        pushButton_Bonus->setText(QApplication::translate("lotto", "\353\263\264\353\204\210\354\212\244", 0));
        label_1->setText(QApplication::translate("lotto", "1\353\262\210OPEN", 0));
        label_2->setText(QApplication::translate("lotto", "2\353\262\210OPEN", 0));
        label_3->setText(QApplication::translate("lotto", "3\353\262\210OPEN", 0));
        label_4->setText(QApplication::translate("lotto", "4\353\262\210OPEN", 0));
        label_5->setText(QApplication::translate("lotto", "5\353\262\210OPEN", 0));
        label_6->setText(QApplication::translate("lotto", "6\353\262\210OPEN", 0));
        label_Bonus->setText(QApplication::translate("lotto", "Bonus Open", 0));
        pushButton_number_reset->setText(QApplication::translate("lotto", "\354\210\253\354\236\220 Reset", 0));
        pushButton_answer->setText(QApplication::translate("lotto", "\354\240\225\353\213\265 \354\240\234\354\266\234", 0));
        pushButton_allopen->setText(QApplication::translate("lotto", "\353\213\271\354\262\250\353\262\210\355\230\270 \n"
"Open", 0));
        label_7->setText(QString());
        label_8->setText(QString());
        label_9->setText(QString());
        label->setText(QApplication::translate("lotto", "                          \353\213\271\354\262\250 \353\262\210\355\230\270", 0));
        pushButton_autobuy->setText(QApplication::translate("lotto", "\354\236\220\353\217\231 \352\265\254\353\247\244", 0));
        label_14->setText(QString());
        label_15->setText(QString());
        label_16->setText(QString());
        label_17->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class lotto: public Ui_lotto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOTTO_H
