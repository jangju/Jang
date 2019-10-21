#ifndef GAMERULES_H
#define GAMERULES_H

#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
namespace Ui {
class gamerules;
}

class gamerules : public QWidget
{
    Q_OBJECT

public:
    explicit gamerules(QWidget *parent = 0);
    ~gamerules();
protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *me) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *me) Q_DECL_OVERRIDE;

private:
    Ui::gamerules *ui;
    int i_base_image_flag;
};

#endif // GAMERULES_H
