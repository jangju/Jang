#ifndef BASE_WIDGET_H
#define BASE_WIDGET_H

#include <QWidget>

class Base_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Base_Widget(QWidget *parent = 0);
    virtual ~Base_Widget();

    void timerEvent_Start(int value);
    void timerEvent_Stop();

    int i_base_image_flag = 0;
public:
    int i_base_timer_id = 0;
};

#endif // BASE_WIDGET_H
