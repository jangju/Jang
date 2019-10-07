#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "rect.h"
#include "ICON.h"
#include <QMainWindow>
#include <QLabel>
#include <QMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void changePage(const int page_number);

protected:
    //virtual void paintEvent(QPaintEvent *me) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *me) Q_DECL_OVERRIDE;//마우스를 뗄떼 인식한다.
    void mousePressEvent(QMouseEvent *me) Q_DECL_OVERRIDE;//마우스 누를떼 인식한다.
private slots:

    void timer_Screen_Stop();
private:
    Ui::MainWindow *ui;
    QTimer *screen_timer = nullptr;
    QLabel *text_label = nullptr;

    QRect bt_1;
    QRect bt_2;
    QRect bt_3;
    QRect bt_4;
    bool b_once_setup;

};

#endif // MAINWINDOW_H
