#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_b_answer_clicked();
    void on_pushButton_computerball_clicked();
    void on_pushButton_reset_clicked();

    void answers();
    void Sequence();
    void reset();


private:
    Ui::MainWindow *ui;
    QMessageBox msg;//메세지 출력하기
    QString str;//게임종료 라벨

    int overlap[6];//입력한 숫자 표시 여부
    int answer[20];//정답 확인 위한 표시 여부

    int computerBall[4];//컴퓨터 볼
    int userBall[4];// 유저 볼
    int i,j;//볼을 랜덤 돌리기위한 숫자
    int itemp; //정렬하기 위한 숫자
    int count =1; //회차
    int strike;//strike의 갯수
    int ball;// ball의 갯수
    bool clicked;//클릭 참거

    int stball;//strick,ball 개수 돌리기
};

#endif // MAINWINDOW_H
