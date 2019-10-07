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
    void mousePressEvent(QMouseEvent *me) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *me) Q_DECL_OVERRIDE;


    int i_base_image_flag = 0;

private slots:

    void iconshot();
private:

    QLabel *IC_image = nullptr;
    QLabel *IC_lotto = nullptr;
    QLabel *IC_memo = nullptr;
    QLabel *IC_floder = nullptr;
    QLabel *IC_calculator = nullptr;
    QLabel *IC_end = nullptr;
    QLabel *IC_end2 = nullptr;


    bool b_check_click = true;
    bool b_once_setup = true;



    QProcess *Process;

};

#endif // ICON_H
