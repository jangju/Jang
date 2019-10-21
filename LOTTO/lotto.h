#ifndef LOTTO_H
#define LOTTO_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <qlabel.h>
#include <QPushButton>



namespace Ui {
class lotto;
}

class lotto : public QMainWindow
{
    Q_OBJECT

public:
    explicit lotto(QWidget *parent = 0);
    ~lotto();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_Bonus_clicked();

    void on_pushButton_number_reset_clicked();

    void on_pushButton_answer_clicked();

    void on_pushButton_allopen_clicked();


    void on_pushButton_autobuy_clicked();

private:
    Ui::lotto *ui;
    QMessageBox msgBox;
    QPushButton button;
    int lottos[50]={};
    int ifmoon[50] = {};

    int itemp,i,j;
    int value = 0;

    bool clicked;
    QLabel *image;


};

#endif // LOTTO_H
