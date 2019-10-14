#ifndef ICON_H
#define ICON_H


#include "ui_mainwindow.h"
#include <QWidget>
#include <QPainter>
#include <QLabel>
#include <QTimer>
#include <QDebug>
#include <QMouseEvent>
#include <QPalette>
#include <QProcess>

class ICON : public QWidget
{
    Q_OBJECT
public:
    explicit ICON(QWidget *parent = 0);
    virtual ~ICON();
protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *me) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *me) Q_DECL_OVERRIDE;

private slots:
    void iconshot();
private:

    QLabel *IC_trash = nullptr;
    QLabel *IC_baseball = nullptr;
    QLabel *IC_lotto = nullptr;
    QLabel *IC_memo = nullptr;
    QLabel *IC_floder = nullptr;
    QLabel *IC_calculator = nullptr;
    QLabel *IC_end = nullptr;
    QLabel *IC_end2 = nullptr;



    bool b_check_click = true;
    bool b_once_setup = true;

    int i_base_image_flag;

    QProcess *Process;

};

#endif // ICON_H
